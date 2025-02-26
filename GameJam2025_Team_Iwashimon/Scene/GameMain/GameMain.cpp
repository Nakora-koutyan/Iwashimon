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
	//�{�[������
	ball = new Ball();
	ball->Initialize();
	objects.push_back(ball);
	//�v���C���[����
	player = new Player();
	player->Initialize();
	objects.push_back(player);
	//�o�b�g����
	bat = new BaseballBat();
	bat->Initialize();
	objects.push_back(bat);
	//blast����
	blast = new Blast();
	blast->Initialize();
	objects.push_back(blast);
	//�����G�t�F�N�g����
	speed_boost = new SpeedBoost();
	speed_boost->Initialize();
	objects.push_back(speed_boost);

	for (auto i = 0; i < objects.size(); i++)
	{
		//�I�u�W�F�N�g�̏�����
		objects[i]->Initialize();
	}

	bat->SetLocation(Vector2D(player->GetLocation().x,player->GetLocation().y + 25.0f));

	//�Q�[�W��\��
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

	//�o�b�g�ƃ{�[���̓����蔻��
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

	//�X�R�A��ǉ�
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