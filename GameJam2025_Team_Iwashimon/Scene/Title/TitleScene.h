#pragma once
#include "../SceneBase.h"

class TitleScene :public SceneBase
{
private:
	int title_image;
	int selectedIndex;
	int cursor_image;
	int cursor_position;
	int cursor_speed;
	int move_interval;
	int Sound_data;
public:
	TitleScene();
	virtual ~TitleScene();

	//����������
	virtual void Initialize() override;

	virtual eSceneType Update(float delta_second);

	//�`�揈��
	virtual void Draw() const override;

	//�I������
	virtual void Finalize() override;


	//���݂̃V�[���^�C�v (�I�[�o�[���C�h�K�{)
	virtual eSceneType GetNowSceneType() const override;
public:

};

