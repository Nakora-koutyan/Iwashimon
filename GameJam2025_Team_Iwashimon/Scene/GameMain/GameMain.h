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
	Player* player;
	Ball* ball;
	BaseballBat* bat;
	Blast* blast;
	SpeedBoost* speed_boost;

	Gauge* gauge;

	class InputControl* input;
	std::vector<ObjectBase*>objects;

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

