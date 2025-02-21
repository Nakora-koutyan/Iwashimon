#include "Ball.h"
#include "DxLib.h"

Ball::Ball()
{
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
}

void Ball::Draw(Vector2D target) const
{
	__super::Draw(target);
}

void Ball::Finalize()
{
}
