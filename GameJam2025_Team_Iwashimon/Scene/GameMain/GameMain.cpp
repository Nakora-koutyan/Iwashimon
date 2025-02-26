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
	objects.push_back(ball);
	//プレイヤー生成
	player = new Player();
	objects.push_back(player);
	//バット生成
	bat = new BaseballBat();
	objects.push_back(bat);
	//加速エフェクト生成
	speed_boost = new SpeedBoost();
	objects.push_back(speed_boost);

	//blast生成
	blast = new Blast();
	blast->Initialize();

	for (auto i = 0; i < objects.size(); i++)
	{
		//オブジェクトの初期化
		objects[i]->Initialize();
	}

	bat->SetLocation(Vector2D(player->GetLocation().x,player->GetLocation().y + 25.0f));
	blast->SetLocation(Vector2D(ball->GetLocation().x - 40, ball->GetLocation().y ));

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
		blast->Update(delta_second);
	}

	//スコアを追加
	if (is_hit_bat && !ball->GetIsAir())
	{
		score = ball->GetLocation().x;
		return eSceneType::eResult;
	}
	else
	{
		return GetNowSceneType();
	}
}

void GameMain::Draw() const
{
	//追尾対象を決定
	Vector2D camera_pos = ball->GetLocation();

	//カメラがステージの一番上からはみ出さなようにする
	if ((camera_pos.y - (SCREEN_HEIGHT * 0.5f)) <= 0)
	{
		camera_pos.y = (SCREEN_HEIGHT * 0.5f);
	}
	//カメラがステージの底より下にならないようにする
	if (STAGE_HEIGHT <= (camera_pos.y + (SCREEN_HEIGHT * 0.5f)))
	{
		camera_pos.y = STAGE_HEIGHT - (SCREEN_HEIGHT * 0.5f);
	}

	//カメラ座標からスクリーン座標の原点に変換する
	Vector2D screen_origin_pos;
	screen_origin_pos.x = camera_pos.x - (SCREEN_WIDTH * 0.5f);
	screen_origin_pos.y = camera_pos.y - (SCREEN_HEIGHT * 0.5f);

	for (int i = 0; i < 10; i++)
	{
		DrawGraphF(((-50.0f + i * 1280) - screen_origin_pos.x), (0 - screen_origin_pos.y), main_backgound_image, TRUE);
	}

	for (auto i = 0; i < objects.size(); i++)
	{
		objects[i]->Draw(objects[0]->GetLocation());
	}
	if (is_hit_bat)
	{
		blast->Draw(objects[0]->GetLocation());
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