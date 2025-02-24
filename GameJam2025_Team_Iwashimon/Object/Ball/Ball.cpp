#include "Ball.h"
#include "DxLib.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/UserTemplate.h"
#include <math.h>

Ball::Ball()
{
	input = nullptr;
	speed = 4.0f;
	g_velocity = 0.0f;
	startangle = 45.0;
	time = 0.0;
	dt = 0.1;
	speed1 = 20.0;
	is_air = false;
}

Ball::~Ball()
{
}

void Ball::Initialize()
{
	world_pos = Vector2D(300.0f, 400.0f);
	obj_size = Vector2D(50.0f, 50.0f);
	input = InputControl::GetInstance();

	//time = Max<double>(-1.0, 0.0);
}

void Ball::Update(float delta_second)
{
	if (world_pos.y >= 600.0f)
	{
		is_air = false;
	}
	if (input->GetKeyPress(KEY_INPUT_SPACE))
	{
		is_air = true;
		speed.y = -2500.0f;
	}
	if (is_air == true)
	{
		g_velocity += D_GRAVITY / 440.0f;			//重力加算
		speed.y += g_velocity * delta_second;		//重力をY方向の加速度に加算する
		speed.x = 60.0f;							//X方向の速度を設定
		world_pos += speed * delta_second;			//座標に加速を加算し移動させる
	}
	
	if (is_air == false)
	{
		g_velocity = 0.0f;
		speed.y = 0.0f;
		world_pos.y = 600.0f;
	}
}

void Ball::Draw(Vector2D target) const
{
	DrawFormatStringF(300, 450, GetColor(255, 255, 255), "X : %lf Y : %lf", this->GetLocation().x, this->GetLocation().y);

	__super::Draw(target);
}

void Ball::Finalize()
{
}
