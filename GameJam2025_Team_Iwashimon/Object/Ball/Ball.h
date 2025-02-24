#pragma once
#include "../ObjectBase.h"

class Ball:public ObjectBase
{
private:
	int ballflag;						//�X�y�[�X�L�[�������ꂽ��{�[������Ԃ��߂̃t���O
	int speed;							//�Œ葬�x
	int ballx[5], bally[5];				//�{�[�������ł���悤�Ɍ�����ϐ�
	int WaitTime;						//���Ԃ𐧌䂷��
	int ballX;							//��莞�Ԃ��̏�łƂǂ܂�悤�ɂ���ϐ�

public:
	Ball();
	~Ball();

public:
	//����������
	void Initialize();
	//�X�V����
	void Update(float delta_second);
	//�`��
	void Draw(Vector2D target)const;
	//�I��������
	void Finalize();
};