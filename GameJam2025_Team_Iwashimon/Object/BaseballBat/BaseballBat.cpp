#include "BaseballBat.h"
#include <math.h>

BaseballBat::BaseballBat()
	:velocity(0.0f)
{
}

BaseballBat::~BaseballBat()
{
}

void BaseballBat::Initialize()
{
	world_pos = Vector2D(125.0f, 380.0f);
	obj_size = Vector2D(20.0f, 60.0f);
}

void BaseballBat::Update(float delta_second)
{
	//velocity.x
}

void BaseballBat::Draw(Vector2D target) const
{
	__super::Draw(target);
}

void BaseballBat::Finalize()
{
}