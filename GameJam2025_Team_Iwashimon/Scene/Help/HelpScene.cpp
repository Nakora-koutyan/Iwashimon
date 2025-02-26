#include "HelpScene.h"
#include "../../Utility/InputManager.h"
#include "DxLib.h"
#include "../../Utility/ResourceManager.h"


HelpScene::HelpScene():
	helpimage(NULL)
{
	input = nullptr;
}

HelpScene::~HelpScene()
{
}

void HelpScene::Initialize()
{
	input = InputControl::GetInstance();
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("Resource/Image/help.png");
	helpimage = tmp[0];
}

eSceneType HelpScene::Update(float delta_second)
{
	if (input->GetKeyPress(XINPUT_BUTTON_A) || input->GetKeyPress(KEY_INPUT_A))
	{
		return eSceneType::eTitle;
	}
	else
	{
		return GetNowSceneType();
	}

}

void HelpScene::Draw() const
{
	DrawGraph(0, 0, helpimage, TRUE);
}

void HelpScene::Finalize()
{
}

eSceneType HelpScene::GetNowSceneType() const
{
	return eSceneType::eHelp;
}
