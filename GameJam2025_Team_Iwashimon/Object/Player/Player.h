#pragma once
#include "../ObjectBase.h"

class Player:public ObjectBase
{
private:
	int player_image[2];
	class InputControl* input;

public:
	Player();
	~Player();

public:
	//����������
	void Initialize()override;
	//�X�V����
	void Update(float delta_second)override;
	//�`��
	void Draw(Vector2D target)const override;
	//�I��������
	void Finalize()override;
};

