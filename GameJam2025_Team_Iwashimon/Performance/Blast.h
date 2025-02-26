#pragma once
#include "../Object/ObjectBase.h"

class Blast:public ObjectBase
{
private:
	bool bom_flg;
	float alpha_time;
	int blast_image[2];

public:
	Blast();
	~Blast();

public:
	//‰Šú‰»ˆ—
	void Initialize();
	//XVˆ—
	void Update(float delta_second);
	//•`‰æ
	void Draw(Vector2D target)const;
	//I—¹ˆ—
	void Finalize();
};