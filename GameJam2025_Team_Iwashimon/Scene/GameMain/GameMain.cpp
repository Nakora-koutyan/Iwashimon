#include "GameMain.h"

#include "../../Object/Player/Player.h"
#include "../../Object/Ball/Ball.h"
#include "../../Performance/Blast.h"
#include "../../Performance/SpeedBoost.h"

#include <iostream>
#include <fstream>
#include <string>


GameMain::GameMain()
	:gauge(nullptr)
	,input(nullptr)
{
}

GameMain::~GameMain()
{
}

void GameMain::Initialize()
{
	//オブジェクトを登録・生成
	CreateObject<Ball>();
	CreateObject<Player>();
	CreateObject<Blast>();
	CreateObject<SpeedBoost>();

	//ゲージを表示
	gauge = new Gauge();
}

eSceneType GameMain::Update(float delta_second)
{
	for (auto i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(delta_second);
	}

	return GetNowSceneType();
}

void GameMain::Draw() const
{
	for (auto i = 0; i < objects.size(); i++)
	{
		objects[i]->Draw(objects[0]->GetLocation());
	}
}

void GameMain::Finalize()
{
}

eSceneType GameMain::GetNowSceneType() const
{
	return eSceneType::eInGame;
}
