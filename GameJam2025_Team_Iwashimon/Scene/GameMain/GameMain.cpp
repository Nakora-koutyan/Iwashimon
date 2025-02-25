#include "GameMain.h"

#include <iostream>
#include <fstream>
#include <string>


GameMain::GameMain()
	:gauge(nullptr)
	,input(nullptr)
	,player(nullptr)
	,ball(nullptr)
	,bat(nullptr)
	,blast(nullptr)
	,speed_boost(nullptr)
{
}

GameMain::~GameMain()
{
}

void GameMain::Initialize()
{
	//ボール生成
	ball = new Ball();
	ball->Initialize();
	objects.push_back(ball);
	//プレイヤー生成
	player = new Player();
	player->Initialize();
	objects.push_back(player);
	//バット生成
	bat = new BaseballBat();
	bat->Initialize();
	objects.push_back(bat);
	//blast生成
	blast = new Blast();
	blast->Initialize();
	objects.push_back(blast);
	//加速エフェクト生成
	speed_boost = new SpeedBoost();
	speed_boost->Initialize();
	objects.push_back(speed_boost);

	for (auto i = 0; i < objects.size(); i++)
	{
		objects[i]->Initialize();
	}

	//ゲージを表示
	gauge = new Gauge();
	gauge->Initialize();
}

eSceneType GameMain::Update(float delta_second)
{
	for (auto i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(delta_second);
	}

	//バットとボールの当たり判定
	if (bat->CollisionHit(ball))
	{

	}

	gauge->Update(delta_second);

	return GetNowSceneType();
}

void GameMain::Draw() const
{
	for (auto i = 0; i < objects.size(); i++)
	{
		objects[i]->Draw(objects[0]->GetLocation());
	}

	gauge->Draw();
}

void GameMain::Finalize()
{
}

eSceneType GameMain::GetNowSceneType() const
{
	return eSceneType::eInGame;
}
