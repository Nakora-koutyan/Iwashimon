#pragma once
#include "../SceneBase.h"

class TitleScene :public SceneBase
{
private:

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

