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
	tmp = rm->GetImages("Resource/Image/help_moji1.png");
	help_moji[0] = tmp[0];
	tmp = rm->GetImages("Resource/Image/help_moji2.png");
	help_moji[1] = tmp[0];
	PlaySoundMem(back_sound, DX_PLAYTYPE_BACK);

}

eSceneType HelpScene::Update(float delta_second)
{
	if (input->GetButtonPress(XINPUT_BUTTON_B) || input->GetKeyPress(KEY_INPUT_B))
	{
		PlaySoundMem(button_click, DX_PLAYTYPE_BACK);
		StopSoundMem(back_sound);

		return eSceneType::eTitle;
	}
#if 1
	if (input->GetButtonPress(XINPUT_BUTTON_A) || input->GetKeyPress(KEY_INPUT_A))
	{
		PlaySoundMem(button_click, DX_PLAYTYPE_BACK);
		StopSoundMem(back_sound);

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
	DrawGraph(240, 402, help_moji[0], TRUE);
	DrawGraph(400, 400, help_moji[1], TRUE);
}

void HelpScene::Finalize()
{
}

eSceneType HelpScene::GetNowSceneType() const
{
	return eSceneType::eHelp;
}
