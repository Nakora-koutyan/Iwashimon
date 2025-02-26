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
	current_gauge = MAX_GAUGE;				// ���݂̃Q�[�W��
	down_count = (MAX_GAUGE / 10);			//�������x
}

void Gauge::Update(float delta_second)
{
	TimePassage(delta_second);
}

void Gauge::Draw() const
{
	// �Q�[�W�̕`��
	DrawBoxAA(10.0f, 10.0f, 10.0f + current_gauge, 40.0f, GetColor(255, 0, 0), TRUE);
	// �Q�[�W�̘g����`��
	DrawBoxAA(10.0f, 10.0f, 10.0f + MAX_GAUGE, 40, GetColor(255, 255, 255), FALSE);
}

void Gauge::Finalize()
{
}

//��������
void Gauge::TimePassage(float delta_second)
{
	current_gauge -= (down_count) * delta_second;

	if (current_gauge < 0) 
	{
		current_gauge = 0;
	}
}
