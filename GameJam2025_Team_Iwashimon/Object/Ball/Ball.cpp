#include "Ball.h"
#include "DxLib.h"
#include "../../Utility/InputManager.h"

Ball::Ball()
{
	ballflag = 0;
	WaitTime = 0;
	input = nullptr;
	speed = 0.0f;
	g_velocity = 0.0f;
}

Ball::~Ball()
{
}

void Ball::Initialize()
{
	world_pos = Vector2D(300.0f, 400.0f);
	obj_size = Vector2D(50.0f, 50.0f);
	input = InputControl::GetInstance();
}

void Ball::Update(float delta_second)
{
	if (world_pos.y >= 600.0f)
	{
		g_velocity = 0.0f;
		speed = 0.0f;
		world_pos.y = 600.0f;
	}
	if (input->GetKeyPress(KEY_INPUT_SPACE))
	{
		ballflag = 1;
		speed.y = -5.0f;
		speed.x = 5.0f;
	}
	g_velocity += D_GRAVITY / 440.0f;
	speed.y += g_velocity;
	world_pos.x += speed.y;
}

void Ball::Draw(Vector2D target) const
{
	__super::Draw(target);
}

void Ball::Finalize()
{
}
