#pragma once
#include "../Utility/Vector2D.h"

class Gauge
{
private:

public:
	Gauge();
	~Gauge();
	
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

