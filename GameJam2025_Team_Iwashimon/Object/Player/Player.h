#pragma once
#include "../ObjectBase.h"

class Player:public ObjectBase
{
private:
	int player_image[2];
	class InputControl* input;

public:
	Player();
	~Player();

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

