#pragma once
#include "../SceneBase.h"

class ResultScene :public SceneBase
{
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

