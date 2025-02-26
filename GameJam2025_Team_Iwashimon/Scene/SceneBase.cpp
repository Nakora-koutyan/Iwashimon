#include "SceneBase.h"
#include "DxLib.h"

SceneBase::SceneBase() 
	:background_image(NULL)
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