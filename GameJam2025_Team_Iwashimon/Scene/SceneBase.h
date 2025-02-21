#pragma once

#include <vector>

enum class eSceneType
{
	eTitle,
	eInGame,
	eResult,
	eHelp,
	eEnd
};

class SceneBase
{
protected:
	int background_image;

public:
	SceneBase();
	virtual ~SceneBase();

public:
	virtual void Initialize();
	virtual eSceneType Update(float delta_second);
	virtual void Draw()const;
	virtual void Finalize();

public:
	virtual eSceneType GetNowSceneType()const = 0;
};