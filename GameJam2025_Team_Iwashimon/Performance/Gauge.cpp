#include "Gauge.h"
#include "DxLib.h"


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
	current_gauge = MAX_GAUGE;				// Œ»İ‚ÌƒQ[ƒW—Ê
	down_count = (MAX_GAUGE / 10);			//Œ¸­‘¬“x
}

void Gauge::Update(float delta_second)
{
	TimePassage(delta_second);
}

void Gauge::Draw() const
{
	// ƒQ[ƒW‚Ì•`‰æ
	DrawBoxAA(10.0f, 10.0f, 10.0f + current_gauge, 40.0f, GetColor(255, 0, 0), TRUE);
	// ƒQ[ƒW‚Ì˜gü‚ğ•`‰æ
	DrawBoxAA(10.0f, 10.0f, 10.0f + MAX_GAUGE, 40, GetColor(255, 255, 255), FALSE);
}

void Gauge::Finalize()
{
}

//Œ¸­ˆ—
void Gauge::TimePassage(float delta_second)
{
	current_gauge -= (down_count) * delta_second;

	if (current_gauge < 0) 
	{
		current_gauge = 0;
	}
}
