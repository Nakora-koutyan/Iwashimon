#pragma once
#include "../Utility/Vector2D.h"

#define MAX_GAUGE  (500.0f)	// �Q�[�W�̍ő�l
#define DECREASE_SPEED  (1)	// �������x (1�b������)

struct ColorParam
{
	int red;
	int blue;
	int green;
};

class Gauge
{
private:
	float current_gauge; // ���݂̃Q�[�W��
	float down_count;

	int Gauge_SE;

	ColorParam color{};

public:
	Gauge();
	~Gauge();

public:
	//����������
	void Initialize();
	//�X�V����
	void Update(float delta_second);
	//�`��
	void Draw()const;
	//�I��������
	void Finalize();

	//���Ԍo�ߏ���
	void TimePassage(float delta_second);

	//���݂̃Q�[�W�̒l���擾
	float GetConsumedLength()const { return MAX_GAUGE - current_gauge; }

	float GetCurrentGauge()const { return current_gauge; }
};

