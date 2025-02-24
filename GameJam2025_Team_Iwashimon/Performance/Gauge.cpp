#include "Gauge.h"
#include "DxLib.h"
Gauge::Gauge()
{
}

Gauge::~Gauge()
{
}

void Gauge::Initialize()
{
    currentGauge = MAX_GAUGE; // ���݂̃Q�[�W��
    previousTime = GetNowCount(); // �O��̍X�V����
}

void Gauge::Update(float delta_second)
{
    Gauge::TimePassage(delta_second);
    Gauge::Draw();
}

void Gauge::Draw() const
{
    // �Q�[�W�̕`��
    DrawBox(10, 10, 10 + currentGauge, 30, GetColor(255, 0, 0), TRUE);

    // �Q�[�W�̘g����`��
    DrawBox(10, 10, 10 + MAX_GAUGE, 30, GetColor(255, 255, 255), FALSE);


	////�R���E�̗̓Q�[�W�̕`��
	//float fx = 1050.0f;
	//float fy = 350.0f;

	//float fxe = 1150.0f;
	//float fye = 380.0f;

	//fx = 1050.0f;
	//fy = 450.0f;
	//DrawBoxAA(fx, fy + 20.0f, fxe + (player->GetHp() * 100 / 10000), fye + 40.0f, GetColor(255, 0, 0), TRUE);
	//DrawBoxAA(fx, fy + 20.0f, fxe + 100.0f, fye + 40.0f, GetColor(0, 0, 0), FALSE);

}
void Gauge::Finalize()
{
}

void Gauge::TimePassage(float delta_second)
{
        int currentTime = GetNowCount();
        int elapsedTime = currentTime - previousTime;
        if (elapsedTime >= 1000) { // 1�b���ƂɌ���
            currentGauge -= DECREASE_SPEED * delta_second;
            if (currentGauge < 0) {
                currentGauge = 0;
            }
            previousTime = currentTime;
        }
}
