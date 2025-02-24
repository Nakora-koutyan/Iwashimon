#pragma once
#include "../ObjectBase.h"
#define D_GRAVITY  (9.897f)					//define gravity

class Ball:public ObjectBase
{
private:
	int ballflag;							//spacebarActivationFlag
	Vector2D speed;							//uniform speed
	int WaitTime;							//manipulate time
	class InputControl* input;
	float g_velocity;						//simulate gravity

public:
	Ball();
	~Ball();

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