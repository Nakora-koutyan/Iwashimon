#pragma once
#include "../Utility/Vector2D.h"

#define MAX_GAUGE  (500.0f)	// �Q�[�W�̍ő�l
#define DECREASE_SPEED  (1)	// �������x (1�b������)

class Gauge
{
private:
	float current_gauge; // ���݂̃Q�[�W��
	float down_count;

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
};

