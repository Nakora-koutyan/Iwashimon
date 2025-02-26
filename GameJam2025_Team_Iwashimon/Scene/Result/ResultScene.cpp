#include "ResultScene.h"
#include "../../Utility/InputManager.h"
#include "DxLib.h"
#include "../../Utility/ResourceManager.h"

ResultScene::ResultScene()
{
	input = nullptr;
	score = 0.0f;
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
	int SE;
	SE = rm->GetSounds("Resource/Sound/SE/button_click.mp3");
	result_SE = SE;
}

eSceneType ResultScene::Update(float delta_second)
{
	if (input->GetKeyPress(XINPUT_BUTTON_A) || input->GetKeyPress(KEY_INPUT_A))
	{
		PlaySoundMem(result_SE, DX_PLAYTYPE_BACK, TRUE);
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
	DrawFormatString(10, 10, 0x000000, "%lf", score);
}

void ResultScene::Finalize()
{
}

eSceneType ResultScene::GetNowSceneType() const
{
	return eSceneType::eResult;
}
