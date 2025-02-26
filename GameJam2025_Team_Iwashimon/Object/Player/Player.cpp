#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	world_pos = Vector2D(200.0f, 400.0f);
	obj_size = Vector2D(50.0f, 120.0f);
}

void Player::Update(float delta_second)
{
	
}

void Player::Draw(Vector2D target) const
{
	__super::Draw(target);
}

void Player::Finalize()
{
}