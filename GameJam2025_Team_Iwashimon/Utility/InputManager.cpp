#include "InputManager.h"
#include "DxLib.h"

InputControl* InputControl::instance = nullptr;

//�C���X�^���X���擾
InputControl* InputControl::GetInstance()
{
	//�C���X�^���X����������Ă��Ȃ����
	if (instance == nullptr)
	{
		//�C���X�^���X�𐶐�
		instance = new InputControl();
	}

	return instance;
}

//�C���X�^���X���폜
void InputControl::DeleteInstance()
{
	//�C���X�^���X����������Ă����
	if (instance != nullptr)
	{
		//�C���X�^���X���폜
		delete instance;
		//�C���X�^���X��nullptr�ɂ���
		instance = nullptr;
	}
}

//2��ނ̓��͏��̍X�V
void InputControl::Update()
{
	//�L�[���͍X�V
	KeyInputUpdate();
	//GamePad���͍X�V
	PadInputUpdate();
}

//�L�[���͍X�V
void InputControl::KeyInputUpdate()
{
	//�O��̓��͒l���X�V
	memcpy(old_key, now_key, (sizeof(char) * D_KEY_CODE_MAX));

	//�S�L�[�̉�����Ԃ��擾����
	GetHitKeyStateAll(now_key);
}
//�L�[���������u�Ԃ��擾
bool InputControl::GetKeyPress(int key_code) const
{
	return (CheckKeyCodeRange(key_code) == TRUE
		&& now_key[key_code] == TRUE
		&& old_key[key_code] == FALSE);
}
//�L�[�����������Ă���Ԏ擾
bool InputControl::GetKeyHeld(int key_code) const
{
	return (CheckKeyCodeRange(key_code) == TRUE
		&& now_key[key_code] == TRUE
		&& old_key[key_code] == TRUE);
}
//�L�[�𗣂����u�Ԃ��擾
bool InputControl::GetKeyRelease(int key_code) const
{
	return (CheckKeyCodeRange(key_code) == TRUE
		&& now_key[key_code] == FALSE
		&& old_key[key_code] == TRUE);
}
//�L�[�̓��͔͈͂��`�F�b�N
bool InputControl::CheckKeyCodeRange(int key_code) const
{
	return (0 <= key_code
		&& key_code < D_KEY_CODE_MAX);
}

void InputControl::PadInputUpdate()
{
	//�O��̓��͏�Ԃ��X�V
	memcpy(old_button, now_button, (sizeof(char) * D_KEY_CODE_MAX));
	XINPUT_STATE xinput{};

	//���͏�Ԃ��擾
	GetJoypadXInputState(DX_INPUT_PAD1, &xinput);

	//�{�^���̉�����Ԃ̍X�V
	for (int i = 0; i < D_BUTTON_CODE_MAX; i++)
	{
		if (xinput.Buttons[i] == TRUE)
		{
			now_button[i] = TRUE;
		}
		else
		{
			now_button[i] = FALSE;
		}
	}

	//���X�e�B�b�N�̓��͍X�V
	l_stick_thumb.x = StickNormalize(xinput.ThumbLX);
	l_stick_thumb.y = StickNormalize(xinput.ThumbLY);

	//�E�X�e�B�b�N�̓��͍X�V
	r_stick_thumb.x = StickNormalize(xinput.ThumbRX);
	r_stick_thumb.y = StickNormalize(xinput.ThumbRY);

	//���E�g���K�[�̉������݋���擾
	trigger[0] = TriggerNormalize(xinput.LeftTrigger);
	trigger[1] = TriggerNormalize(xinput.RightTrigger);
}
//�{�^�����������u�Ԃ��擾
bool InputControl::GetButtonPress(int button_code) const
{
	return (CheckButtonCodeRange(button_code) == TRUE
		&& now_button[button_code] == TRUE
		&& old_button[button_code] == FALSE);
}
//�{�^�������������Ă���Ԏ擾
bool InputControl::GetButtonHeld(int button_code) const
{
	return (CheckButtonCodeRange(button_code) == TRUE
		&& now_button[button_code] == TRUE
		&& old_button[button_code] == TRUE);
}
//�{�^���𗣂����u�Ԃ��擾
bool InputControl::GetButtonRelease(int button_code) const
{
	return (CheckButtonCodeRange(button_code) == TRUE
		&& now_button[button_code] == FALSE
		&& old_button[button_code] == TRUE);
}
//���g���K�[�̒l���擾
float InputControl::GetLTrigger() const
{
	return trigger[0];
}
//�E�g���K�[�̒l���擾
float InputControl::GetRTrigger() const
{
	return trigger[1];
}
//���X�e�B�b�N�̌X���̒l���擾
Vector2D InputControl::GetLStickPos() const
{
	return l_stick_thumb;
}
//�E�X�e�B�b�N�̌X���̒l���擾
Vector2D InputControl::GetRStickPos() const
{
	return r_stick_thumb;
}
//�{�^���̓��͔͈͂��`�F�b�N
bool InputControl::CheckButtonCodeRange(int button_code) const
{
	return (0 <= button_code
		&& button_code < D_BUTTON_CODE_MAX);
}
//�X�e�B�b�N�̓��͒l��␳
float InputControl::StickNormalize(short tip_value) const
{
	/* �X�e�B�b�N�̒l �u-32768 �` 32767�v�̒l�� */
	/*�u -1.0f�`1.0f�v �̒l���Ԃ��Ă���l�ɏ��Z���s��*/
	if (0 < tip_value)
	{
		return (static_cast<float>(tip_value) / static_cast<float>(SHRT_MAX));
	}
	else
	{
		return -(static_cast<float>(tip_value) / static_cast<float>(SHRT_MIN));
	}
}
//�g���K�[�̓��͒l��␳
float InputControl::TriggerNormalize(unsigned int trigger_value) const
{
	/* �g���K�[�̒l �u0�`255�v�̒l�� */
	/* �u0�`1.0f�v�̒l���Ԃ��Ă���悤�ɏ��Z���� */
	if (0 < trigger_value)
	{
		return (static_cast<float>(trigger_value) / static_cast<float>(UCHAR_MAX));
	}
	else
	{
		return 0.0f;
	}
}
