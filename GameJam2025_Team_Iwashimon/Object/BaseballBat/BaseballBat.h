#pragma once
#include "../ObjectBase.h"

class BaseballBat :public ObjectBase
{
private:
	Vector2D velocity;		//ˆÚ“®‹——£

public:
	BaseballBat();
	~BaseballBat();

public:
	//‰Šú‰»ˆ—
	void Initialize()override;
	//XVˆ—
	void Update(float delta_second)override;
	//•`‰æ
	void Draw(Vector2D target)const override;
	//I—¹ˆ—
	void Finalize()override;
};

