#pragma once
#include "../Object/ObjectBase.h"

class Blast:public ObjectBase
{
private:
	
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