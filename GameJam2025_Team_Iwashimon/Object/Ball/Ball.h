#pragma once
#include "../ObjectBase.h"
#define D_GRAVITY  (9.897f)					//define gravity

class Ball:public ObjectBase
{
private:
	Vector2D speed;							//uniform speed
	class InputControl* input;
	float g_velocity;						//simulate gravity
	double angle;							//radian conversion
	double startangle;						//launch angle(start)
	double time;								
	double x, y;
	double dt;
	double speed1;

	const float max_a = 500.0f;
	const float min_a = 0.0f;

	bool is_air;

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