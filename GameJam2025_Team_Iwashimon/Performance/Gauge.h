#pragma once
#include "../Utility/Vector2D.h"

#define MAX_GAUGE  (500.0f)	// ゲージの最大値
#define DECREASE_SPEED  (1)	// 減少速度 (1秒あたり)

class Gauge
{
private:
	float current_gauge; // 現在のゲージ量
	float down_count;

public:
	Gauge();
	~Gauge();

public:
	//初期化処理
	void Initialize();
	//更新処理
	void Update(float delta_second);
	//描画
	void Draw()const;
	//終了時処理
	void Finalize();

	//時間経過処理
	void TimePassage(float delta_second);

	//現在のゲージの値を取得
	float GetConsumedLength()const { return MAX_GAUGE - current_gauge; }
};

