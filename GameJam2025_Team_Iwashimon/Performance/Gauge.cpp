#include "Gauge.h"
#include "DxLib.h"
#include "../Utility/UserTemplate.h"

Gauge::Gauge():
	down_count(0.0f),
	current_gauge(0)
{
}

Gauge::~Gauge()
{
}

void Gauge::Initialize()
{
	current_gauge = MAX_GAUGE;				// 現在のゲージ量
	down_count = (MAX_GAUGE / 10);			//減少速度

	//ゲージバーの色の値を設定
	color.red = 255;
	color.blue = 255;
	color.green = 255;
}

void Gauge::Update(float delta_second)
{
	TimePassage(delta_second);

	color.blue = max(color.red - 0.5f, 0);
	if (color.blue = 0)
	{
		color.green = max(color.green - 0.5f, 0);
	}
}

void Gauge::Draw() const
{
	// ゲージの描画
	DrawBoxAA(10.0f, 10.0f, 10.0f + current_gauge, 40.0f, GetColor(color.red, color.blue, color.green), TRUE);
	// ゲージの枠線を描画
	DrawBoxAA(10.0f, 10.0f, 10.0f + MAX_GAUGE, 40, GetColor(255, 255, 255), FALSE);
}

void Gauge::Finalize()
{
}

//減少処理
void Gauge::TimePassage(float delta_second)
{
	current_gauge -= (down_count) * delta_second;

	if (current_gauge < 0) 
	{
		current_gauge = 0;
	}
}
