#pragma once
#include "../Object/ObjectBase.h"

class SpeedBoost :public ObjectBase
{
private:

public:
	SpeedBoost();
	~SpeedBoost();

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