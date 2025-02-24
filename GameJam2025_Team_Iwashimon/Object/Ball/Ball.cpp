#include "Ball.h"
#include "DxLib.h"

Ball::Ball()
{
	ballflag = 0;
	for (int i = 0; i < 5; i++)
	{
		ballx[i] = 0;
		bally[i] = 0;
	}
	WaitTime = 0;
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
		ballflag = 1;/*
		speed = 5;*/
		for (int j = 0; j < 5; j++)
		{
			ballx[j] += 10;
			bally[j] += 10;
		}
		if (++WaitTime < 1200)
		{

		}
	}
}

void Ball::Draw(Vector2D target) const
{
	__super::Draw(target);
	for (int i = 0; i < 5; i++)
	{
		if (ballflag == 1)
		{
			DrawCircle(200 + ballx[i], 200, 15, 0xffffff);
		}
	}
	
	//DrawCircle(200, 200, 15, 0xffffff);
}

void Ball::Finalize()
{
}
