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
	currentGauge = MAX_GAUGE;				// ���݂̃Q�[�W��
	down_count = (MAX_GAUGE / 15);			//�������x
}

void Gauge::Update(float delta_second)
{
	Gauge::TimePassage(delta_second);
	Gauge::Draw();
}

void Gauge::Draw() const
{
	// �Q�[�W�̕`��
	DrawBox(10, 10, 10 + currentGauge, 40, GetColor(255, 0, 0), TRUE);

	// �Q�[�W�̘g����`��
	DrawBox(10, 10, 10 + MAX_GAUGE, 40, GetColor(255, 255, 255), FALSE);

}
void Gauge::Finalize()
{
}

//��������
void Gauge::TimePassage(float delta_second)
{
	currentGauge -= (down_count) * delta_second;
	if (currentGauge < 0) {
		currentGauge = 0;
	}
}
