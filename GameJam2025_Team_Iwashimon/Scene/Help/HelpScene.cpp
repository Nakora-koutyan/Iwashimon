#include "HelpScene.h"
#include "../../Utility/InputManager.h"
#include "DxLib.h"
#include "../../Utility/ResourceManager.h"


HelpScene::HelpScene():
	helpimage(NULL),
	back_sound(NULL),
	button_click(NULL)
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
	back_sound = rm->GetSounds("Resource/Sound/BGM/イマジン・エマージェンシ.mp3");
	button_click = rm->GetSounds("Resource/Sound/SE/button_click.mp3");
	helpimage = tmp[0];
	PlaySoundMem(back_sound, DX_PLAYTYPE_BACK);

}

eSceneType HelpScene::Update(float delta_second)
{
	if (input->GetKeyPress(XINPUT_BUTTON_B) || input->GetKeyPress(KEY_INPUT_B))
	{
		PlaySoundMem(button_click, DX_PLAYTYPE_BACK);

		return eSceneType::eTitle;
	}
#if 1
	if (input->GetKeyPress(KEY_INPUT_A) || input->GetKeyPress(KEY_INPUT_A))
	{
		PlaySoundMem(button_click, DX_PLAYTYPE_BACK);
		return eSceneType::eInGame;
	}
#endif
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
