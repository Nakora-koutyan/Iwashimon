#pragma once
#include "../ObjectBase.h"

class BaseballBat :public ObjectBase
{
private:
	Vector2D velocity;		//�ړ�����

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
};

