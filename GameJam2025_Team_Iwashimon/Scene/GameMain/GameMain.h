#pragma once
#include "../SceneBase.h"
#include "../../Utility/Vector2D.h"
#include "../../Object/ObjectBase.h"

#include "../../Object/Player/Player.h"
#include "../../Object/Ball/Ball.h"
#include "../../Object/BaseballBat/BaseballBat.h"
#include "../../Performance/Blast.h"
#include "../../Performance/SpeedBoost.h"

#include "../../Performance/Gauge.h"

class GameMain :public SceneBase
{
private:
	//�I�u�W�F�N�g����
	Player* player;
	Ball* ball;
	BaseballBat* bat;
	Blast* blast;
	SpeedBoost* speed_boost;
	Gauge* gauge;

	//�o�b�g�ƃ{�[���������������H
	bool is_hit_bat = false;

	//���̓X�e�[�^�X
	class InputControl* input;
	//�I�u�W�F�N�g���i�[����ϒ��z��
	std::vector<ObjectBase*>objects;

	//�w�i�̉摜�Ɋւ���ϐ�
	int main_backgound_image;
	Vector2D back_image_pos;

public:
	GameMain();
	~GameMain();

public:
	void Initialize()override;
	eSceneType Update(float delta_second)override;
	void Draw()const override;
	void Finalize()override;

public:
	eSceneType GetNowSceneType()const override;
};

