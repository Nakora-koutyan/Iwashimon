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
	//オブジェクト生成
	Player* player;
	Ball* ball;
	BaseballBat* bat;
	Blast* blast;
	SpeedBoost* speed_boost;
	Gauge* gauge;

	//バットとボールが当たったか？
	bool is_hit_bat = false;

	//入力ステータス
	class InputControl* input;
	//オブジェクトを格納する可変長配列
	std::vector<ObjectBase*>objects;

	//背景の画像に関する変数
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

