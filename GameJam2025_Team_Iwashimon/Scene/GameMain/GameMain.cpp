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
	}

	gauge->Update(delta_second);

	//�{�^���Ŋe�V�[���ɑJ�ڂł���悤�ɂ��܂���
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