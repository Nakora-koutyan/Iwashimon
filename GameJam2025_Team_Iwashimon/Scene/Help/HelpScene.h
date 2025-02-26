#pragma once
#include "../SceneBase.h"

class HelpScene :public SceneBase
{
private:
	class InputControl* input;
	int helpimage;
	int back_sound;
	int button_click;
	int help_moji[2];

public:
	HelpScene();
	~HelpScene();

public:
	void Initialize()override;
	eSceneType Update(float delta_second)override;
	void Draw()const override;
	void Finalize()override;

public:
	eSceneType GetNowSceneType()const override;
};

