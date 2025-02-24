#include "Ball.h"
#include "DxLib.h"
#include "../../Utility/InputManager.h"
#include <math.h>

Ball::Ball()
{
	input = nullptr;
	speed = 5.0f;
	g_velocity = 0.0f;
	startangle = 45.0;
	time = 0.0;
	dt = 0.1;
	speed1 = 20.0;
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
	//ball speed ramp
	if (world_pos.y >= 600.0f)
	{
		g_velocity = 0.0f;
		//speed.y = 0.0f;
		world_pos.y = 600.0f;
	}
	angle = startangle * DX_PI / 180.0f;
	g_velocity += D_GRAVITY / 440.0f;
	speed.y += g_velocity;
	world_pos.y += speed.y;
	/*if (input->GetKeyPress(KEY_INPUT_A))
	{*/
		/*if (time <= 2.0)
		{
			world_pos.x = speed1 * cos(angle) * time;
			world_pos.y = speed1 * sin(angle) * time - 0.5 * D_GRAVITY * time * time;
		}*/
	//}
	
	world_pos.x = speed.x * cos(angle) * time;
	world_pos.y = speed.y * sin(angle) * time - 0.5 * D_GRAVITY * time * time;

	if (is_air == true)
	{
		locationx = world_pos.x;
		locationy = world_pos.y;
	}
	
	//change ragian
	
	/*x = speed1 * cos(angle) * time;
	y = speed1 * sin(angle) * time - 1.0 * D_GRAVITY * time * time;*/
	time += dt;
}

void Ball::Draw(Vector2D target) const
{
	__super::Draw(target);
}

void Ball::Finalize()
{
}
