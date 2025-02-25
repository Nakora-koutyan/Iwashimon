#pragma once
#include "../SceneBase.h"
class EndScene :public SceneBase
{
private:
	class InputControl* input;
	int Endimage;
	int Endrollimage[6];
	int g_WaitTime;
	int g_PosY;
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

