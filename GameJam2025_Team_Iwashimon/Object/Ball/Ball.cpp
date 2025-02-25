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

	obj_type = ObjectType::eBall;
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
		g_velocity += D_GRAVITY / 440.0f;			//d—Í‰ÁŽZ
		speed.y += g_velocity * delta_second;		//d—Í‚ðY•ûŒü‚Ì‰Á‘¬“x‚É‰ÁŽZ‚·‚é
		speed.x = 60.0f;							//X•ûŒü‚Ì‘¬“x‚ðÝ’è
		world_pos += speed * delta_second;			//À•W‚É‰Á‘¬‚ð‰ÁŽZ‚µˆÚ“®‚³‚¹‚é
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
