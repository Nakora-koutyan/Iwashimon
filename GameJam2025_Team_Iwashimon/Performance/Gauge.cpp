#include "Gauge.h"
#include "DxLib.h"


Gauge::Gauge():
	down_count(0.0f),
	currentGauge(0)
{
}

Gauge::~Gauge()
{
}

void Gauge::Initialize()
{
	currentGauge = MAX_GAUGE;				// Œ»İ‚ÌƒQ[ƒW—Ê
	down_count = (MAX_GAUGE / 15);			//Œ¸­‘¬“x
}

void Gauge::Update(float delta_second)
{
	Gauge::TimePassage(delta_second);
	Gauge::Draw();
}

void Gauge::Draw() const
{
	// ƒQ[ƒW‚Ì•`‰æ
	DrawBox(10, 10, 10 + currentGauge, 40, GetColor(255, 0, 0), TRUE);

	// ƒQ[ƒW‚Ì˜gü‚ğ•`‰æ
	DrawBox(10, 10, 10 + MAX_GAUGE, 40, GetColor(255, 255, 255), FALSE);

}
void Gauge::Finalize()
{
}

//Œ¸­ˆ—
void Gauge::TimePassage(float delta_second)
{
	currentGauge -= (down_count) * delta_second;
	if (currentGauge < 0) {
		currentGauge = 0;
	}
}
