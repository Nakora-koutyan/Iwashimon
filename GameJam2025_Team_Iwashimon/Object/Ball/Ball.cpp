#include "Ball.h"
#include "DxLib.h"

Ball::Ball()
{
	ballflag = 0;
	speed = 5;
}

Ball::~Ball()
{
}

void Ball::Initialize()
{
	world_pos = Vector2D(300.0f, 400.0f);
	obj_size = Vector2D(50.0f, 50.0f);
}

void Ball::Update(float delta_second)
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		ballflag = 1;
	}
}

void Ball::Draw(Vector2D target) const
{
	__super::Draw(target);
	if (ballflag == 1)
	{
		DrawCircle(200, 200, 15, 0xffffff);
	}
	//DrawCircle(200, 200, 15, 0xffffff);
}

void Ball::Finalize()
{
}
