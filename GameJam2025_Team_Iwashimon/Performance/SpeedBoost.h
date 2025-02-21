#pragma once
#include "../Object/ObjectBase.h"

class SpeedBoost :public ObjectBase
{
private:

public:
	SpeedBoost();
	~SpeedBoost();

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