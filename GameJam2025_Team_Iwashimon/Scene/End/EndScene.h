#pragma once
#include "../SceneBase.h"
#define MOVE_SPEED 7
class EndScene :public SceneBase
{
private:
	class InputControl* input;
	int Endimage;
	int Endrollimage[7];
	int g_WaitTime;
	int g_PosY;
	int end_BGM;

public:
	EndScene();
	~EndScene();

public:
	void Initialize()override;
	eSceneType Update(float delta_second)override;
	void Draw()const override;
	void Finalize()override;

public:
	eSceneType GetNowSceneType()const override;
};

