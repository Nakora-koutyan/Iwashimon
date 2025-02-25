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
	if (input->GetKeyPress(XINPUT_BUTTON_A) || input->GetKeyPress(KEY_INPUT_A))
	{
		return eSceneType::eTitle;
	}
#if 1
	if(input->GetKeyPress(KEY_INPUT_E))
	{
		return eSceneType::eEnd;
	}
#endif
	else
	{
		return GetNowSceneType();
	}
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
	return eSceneType::eResult;
}
