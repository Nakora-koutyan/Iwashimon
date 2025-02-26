#include "SceneBase.h"
#include "DxLib.h"

SceneBase::SceneBase() 
	:background_image(NULL)
	,score(0.0f)
{
}

SceneBase::~SceneBase()
{
	this->Finalize();
}

void SceneBase::Initialize()
{
}

eSceneType SceneBase::Update(float delta_second)
{
	return GetNowSceneType();
}

void SceneBase::Draw() const
{
}

void SceneBase::Finalize()
{
}