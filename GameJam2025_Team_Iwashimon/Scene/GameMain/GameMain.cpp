#include "GameMain.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"

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
	, main_backgound_image(NULL)
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

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("Resource/Image/background_gamemain.png");
	main_backgound_image = tmp[0];
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
		is_hit_bat = true;
	}
	
	if (!is_hit_bat)
	{
		gauge->Update(delta_second);
	}

	//スコアを追加
	if (is_hit_bat && !ball->GetIsAir())
	{
		return eSceneType::eResult;
		score = ball->GetLocation().x;
	}
	else
	{
		return GetNowSceneType();
	}
}

void GameMain::Draw() const
{
	DrawGraphF(0.0f, 0.0f, main_backgound_image, TRUE);

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