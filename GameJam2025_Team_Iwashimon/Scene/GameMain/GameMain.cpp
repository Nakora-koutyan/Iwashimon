#include "GameMain.h"
#include "../../Utility/InputManager.h"

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
		//オブジェクトの初期化
		objects[i]->Initialize();
	}

	bat->SetLocation(Vector2D(player->GetLocation().x,player->GetLocation().y + 25.0f));

	//ゲージを表示
	gauge = new Gauge();
	gauge->Initialize();

	input = InputControl::GetInstance();
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
		ball->OnCollisionEnter(bat);
		ball->SetTargetHeight(gauge->GetConsumedLength() * delta_second);
	}

	gauge->Update(delta_second);

	//ボタンで各シーンに遷移できるようにしました
	if (input->GetKeyPress(KEY_INPUT_R))
	{
		return eSceneType::eResult;
	}
	else if (input->GetKeyPress(KEY_INPUT_T))
	{
		return eSceneType::eTitle;
	}
	else if (input->GetKeyPress(KEY_INPUT_H))
	{
		return eSceneType::eHelp;
	}
	else
	{
		return GetNowSceneType();
	}
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