#pragma once
#include "../Utility/Vector2D.h"

#define MAX_GAUGE  (60)// �Q�[�W�̍ő�l
#define DECREASE_SPEED  (1)// �������x (1�b������)

class Gauge
{
private:

public:
	Gauge();
	~Gauge();

	int currentGauge; // ���݂̃Q�[�W��
	int previousTime;// �O��̍X�V����
	
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


	
};

