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
	objects.push_back(ball);
	//�v���C���[����
	player = new Player();
	objects.push_back(player);
	//�o�b�g����
	bat = new BaseballBat();
	objects.push_back(bat);
	//�����G�t�F�N�g����
	speed_boost = new SpeedBoost();
	objects.push_back(speed_boost);

	//blast����
	blast = new Blast();
	blast->Initialize();

	for (auto i = 0; i < objects.size(); i++)
	{
		//�I�u�W�F�N�g�̏�����
		objects[i]->Initialize();
	}

	bat->SetLocation(Vector2D(player->GetLocation().x,player->GetLocation().y + 25.0f));
	blast->SetLocation(Vector2D(ball->GetLocation().x - 40, ball->GetLocation().y ));

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
		blast->Update(delta_second);
	}

	//�X�R�A��ǉ�
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
	//�ǔ��Ώۂ�����
	Vector2D camera_pos = ball->GetLocation();

	//�J�������X�e�[�W�̈�ԏォ��͂ݏo���Ȃ悤�ɂ���
	if ((camera_pos.y - (SCREEN_HEIGHT * 0.5f)) <= 0)
	{
		camera_pos.y = (SCREEN_HEIGHT * 0.5f);
	}
	//�J�������X�e�[�W�̒��艺�ɂȂ�Ȃ��悤�ɂ���
	if (STAGE_HEIGHT <= (camera_pos.y + (SCREEN_HEIGHT * 0.5f)))
	{
		camera_pos.y = STAGE_HEIGHT - (SCREEN_HEIGHT * 0.5f);
	}

	//�J�������W����X�N���[�����W�̌��_�ɕϊ�����
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