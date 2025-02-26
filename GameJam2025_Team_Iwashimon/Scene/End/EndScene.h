#pragma once
#include "../SceneBase.h"
#define MOVE_SPEED 7
class EndScene :public SceneBase
{
private:
	class InputControl* input;
	int Endimage;
	int Endrollimage[8];
	int g_WaitTime;
	int g_PosY;
	int end_BGM;
	int time[3];

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

