#pragma once
#include "../Object/ObjectBase.h"

class Blast:public ObjectBase
{
private:
	bool bom_flg;
	float alpha_time;

public:
	Blast();
	~Blast();

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