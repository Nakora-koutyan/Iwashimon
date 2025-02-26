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
	current_gauge = MAX_GAUGE;				// ���݂̃Q�[�W��
	down_count = (MAX_GAUGE / 10);			//�������x

	//�Q�[�W�o�[�̐F�̒l��ݒ�
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
	// �Q�[�W�̕`��
	DrawBoxAA(10.0f, 10.0f, 10.0f + current_gauge, 40.0f, GetColor(color.red, color.blue, color.green), TRUE);
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
