#pragma once
#include "../ObjectBase.h"

class BaseballBat :public ObjectBase
{
private:
	class InputControl* input;	//���̓C���X�^���X���擾

	Vector2D velocity;		//�ړ�����

	float amplitude;		//�p�x
	float frequency;		//���W�A���l

	bool is_swinging;		//�o�b�g��U�����H

	int Hit_SE;
	int Bakuhatu_SE;

public:
	BaseballBat();
	~BaseballBat();

public:
	//����������
	void Initialize()override;
	//�X�V����
	void Update(float delta_second)override;
	//�`��
	void Draw(Vector2D target)const override;
	//�I��������
	void Finalize()override;

private:
	//��]����
	void Rolling();

	//�U�q����
	void Pendulum();
};

