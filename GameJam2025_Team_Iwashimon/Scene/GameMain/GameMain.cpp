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
		objects[i]->Initialize();
	}

	//�Q�[�W��\��
	gauge = new Gauge();
	gauge->Initialize();
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
