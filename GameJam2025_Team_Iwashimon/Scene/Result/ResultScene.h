#pragma once
#include "../SceneBase.h"

class ResultScene :public SceneBase
{
private:
	class InputControl* input;
	int resultimage;
	int result_SE;
	int result_button_flag;

public:
	ResultScene();
	~ResultScene();

public:
	void Initialize()override;
	eSceneType Update(float delta_second)override;
	void Draw()const override;
	void Finalize()override;

public:
	eSceneType GetNowSceneType()const override;
};

