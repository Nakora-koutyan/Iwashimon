#pragma once
#include "Vector2D.h"

#define D_KEY_CODE_MAX (255)
#define D_BUTTON_CODE_MAX (255)

class InputControl
{
private:
	static InputControl* instance;

	//�L�[���͂Ɋւ���ϐ�
	char now_key[D_KEY_CODE_MAX]{};
	char old_key[D_KEY_CODE_MAX]{};

	//�{�^�����͂Ɋւ���ϐ�
	char now_button[D_BUTTON_CODE_MAX]{};
	char old_button[D_BUTTON_CODE_MAX]{};

	//�X�e�B�b�N�̌X���x�����擾����ϐ�
	Vector2D l_stick_thumb = Vector2D(0.0f);
	Vector2D r_stick_thumb = Vector2D(0.0f);
	//GamePad�g���K�[�̒l�擾�p�ϐ�
	float trigger[2];

private:
	InputControl() = default;

	//�R�s�[�R���X�g���N�^�֎~
	InputControl(InputControl& v) = delete;
	InputControl& operator=(const InputControl& v) = delete;

public:
	~InputControl() = default;

public:
	//�C���X�^���X���擾
	static InputControl* GetInstance();
	//�C���X�^���X���폜
	static void DeleteInstance();

public:
	//2��ނ̓��͏��̍X�V
	void Update();
public:

	//�L�[�̓��͏����Ɋւ���֐�
	void KeyInputUpdate();

	bool GetKeyPress(int key_code)const;		//�L�[���������u�Ԃ��擾
	bool GetKeyHeld(int key_code)const;			//�L�[�����������Ă���Ԏ擾
	bool GetKeyRelease(int key_code)const;		//�L�[�𗣂����u�Ԃ��擾

private:
	bool CheckKeyCodeRange(int key_code)const;	//�L�[�̓��͔͈͂��`�F�b�N

public:

	//GamePad�̓��͂Ɋւ���X�V
	void PadInputUpdate();

	bool GetButtonPress(int button_code)const;		//�{�^�����������u�Ԃ��擾
	bool GetButtonHeld(int button_code)const;		//�{�^�������������Ă���Ԏ擾
	bool GetButtonRelease(int button_code)const;	//�{�^���𗣂����u�Ԃ��擾

	float GetLTrigger()const;						//���g���K�[�̒l���擾
	float GetRTrigger()const;						//�E�g���K�[�̒l���擾

	Vector2D GetLStickPos()const;					//���X�e�B�b�N�̌X���̒l���擾
	Vector2D GetRStickPos()const;					//�E�X�e�B�b�N�̌X���̒l���擾

private:

	bool CheckButtonCodeRange(int button_code)const;	//�{�^���̓��͔͈͂��`�F�b�N

	/* �X�e�B�b�N�̒l �u-32768 �` 32767�v�̒l�� */
	/*�u - 1.0f�`1.0f�v �̒l���Ԃ��Ă���l�ɏ��Z���s�� */
	float StickNormalize(short tip_value)const;						//�X�e�B�b�N�̓��͒l��␳
	/* �g���K�[�̒l �u0�`255�v�̒l�� */
	/* �u0�`1.0f�v�̒l���Ԃ��Ă���悤�ɏ��Z���� */
	float TriggerNormalize(unsigned int trigger_value)const;		//�g���K�[�̓��͒l��␳
};