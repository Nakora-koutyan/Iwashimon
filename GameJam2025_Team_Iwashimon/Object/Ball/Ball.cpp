﻿#include "Ball.h"
#include "DxLib.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/UserTemplate.h"
#include "../../Utility/ResourceManager.h"
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
	target_height = 0.0f;
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

	//インスタンスを確保
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("Resource/Image/ball.png");
	image = tmp[0];

	init_pos_ = world_pos;
}

void Ball::Update(float delta_second)
{
	if (world_pos.y >= 400.0f && 0 <= speed.y)
	{
		is_air = false;
	}
	if (is_air == true)
	{
		g_velocity += D_GRAVITY / 110.0f;			//重力加算
		speed.y += g_velocity * delta_second*10;	//重力をY方向の加速度に加算する
		world_pos += speed * delta_second;			//座標に加速を加算し移動させる
	}
	
	if (is_air == false)
	{
		g_velocity = 0.0f;
		speed.y = 0.0f;
		world_pos.y = 400.0f;
	}
}

void Ball::Draw(Vector2D target) const
{
	__super::Draw(target);
}

void Ball::Finalize()
{
}

void Ball::OnCollisionEnter(ObjectBase* obj)
{
	is_air = true;
	
	//自身のObjの座標と半径を取得
	Vector2D a = Vector2D(this->GetLocation());
	//対象のObjの座標と半径を取得
	Vector2D b = Vector2D(obj->GetLocation());

	//a²+b²＝c²(ルートでcの実際の長さを取得する所まで)
	target_height = sqrt(powf((a.x - b.x), 2.0f) + powf((a.x - b.x), 2.0f));
}

void Ball::SetTargetHeight(float length)
{
	target_length = target_height * length;
	speed.x = target_length;
	speed.y = -target_length;
}
