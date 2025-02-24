#pragma once
#include "../ObjectBase.h"

class Ball:public ObjectBase
{
private:
	int ballflag;						//spacebarActivationFlag
	int speed;							//uniform speed
	int ballx[5], bally[5];				//ball trajectory variables
	int WaitTime;						//manipulate time
	int ballX;							//dwell variable
	class InputControl* input;
	int posx;							//control time

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