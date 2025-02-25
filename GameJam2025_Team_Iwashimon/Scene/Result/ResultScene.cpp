#include "ResultScene.h"
#include "../../Utility/InputManager.h"
#include "DxLib.h"
#include "../../Utility/ResourceManager.h"

ResultScene::ResultScene()
{
	input = nullptr;
}

ResultScene::~ResultScene()
{
}

void ResultScene::Initialize()
{
	input = InputControl::GetInstance();
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("Resource/Image/result.png");
	resultimage = tmp[0];
}

eSceneType ResultScene::Update(float delta_second)
{
	return GetNowSceneType();
}

void ResultScene::Draw() const
{
	DrawGraph(0, 0, resultimage, TRUE);
}

void ResultScene::Finalize()
{
}

eSceneType ResultScene::GetNowSceneType() const
{
	if (input->GetKeyPress(KEY_INPUT_A))
	{
		return eSceneType::eTitle;
	}
	return eSceneType::eResult;
}
