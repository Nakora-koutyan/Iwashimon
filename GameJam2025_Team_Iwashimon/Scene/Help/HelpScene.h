#pragma once
#include "../SceneBase.h"

class HelpScene :public SceneBase
{
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

