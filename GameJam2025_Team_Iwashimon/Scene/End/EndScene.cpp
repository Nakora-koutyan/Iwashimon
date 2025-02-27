#include "EndScene.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

EndScene::EndScene()
{
	g_WaitTime = 0;
	time[0] = 4500;
	time[1] = 4800;
	time[2] = 5000;
}

EndScene::~EndScene()
{
}

void EndScene::Initialize()
{
	input = InputControl::GetInstance();
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("Resource/Image/end_background.png");
	Endimage = tmp[0];
	tmp = rm->GetImages("Resource/Image/end_moji.png");
	Endrollimage[0] = tmp[0];
	tmp = rm->GetImages("Resource/Image/end_moji1.png");
	Endrollimage[1] = tmp[0];
	tmp = rm->GetImages("Resource/Image/end_moji2.png");
	Endrollimage[2] = tmp[0];
	tmp = rm->GetImages("Resource/Image/end_moji3.png");
	Endrollimage[3] = tmp[0];
	tmp = rm->GetImages("Resource/Image/end_moji4.png");
	Endrollimage[4] = tmp[0];
	tmp = rm->GetImages("Resource/Image/end_moji5.png");
	Endrollimage[5] = tmp[0];
	tmp = rm->GetImages("Resource/Image/end_moji6.png");
	Endrollimage[6] = tmp[0];
	tmp = rm->GetImages("Resource/Image/end_moji7.png");
	Endrollimage[7] = tmp[0];

	ResourceManager* rs = ResourceManager::GetInstance();
	int BGM;
	BGM = rs->GetSounds("Resource/Sound/BGM/end_BGM.mp3");
	end_BGM = BGM;
}

eSceneType EndScene::Update(float delta_second)
{
	if (CheckSoundMem(end_BGM) == 0)
	{
		PlaySoundMem(end_BGM, DX_PLAYTYPE_BACK, TRUE);
	}
	if (++g_WaitTime < time[0])g_PosY = 600 - g_WaitTime / 2;
	
	if (++g_WaitTime > time[1])
	{
		if (g_PosY >= 600 || g_WaitTime >=time[2])
		{
			return eSceneType::eGameEnd;
		}
	}
	return eSceneType();
}

void EndScene::Draw() const
{
	DrawGraph(0, 0, Endimage, TRUE);
	DrawGraph(0, 1700 + g_PosY, Endrollimage[0], TRUE);
	DrawGraph(50, 300 + g_PosY, Endrollimage[1], TRUE);
	DrawGraph(50, 500 + g_PosY, Endrollimage[2], TRUE);
	DrawGraph(50, 700 + g_PosY, Endrollimage[3], TRUE);
	DrawGraph(50, 900 + g_PosY, Endrollimage[4], TRUE);
	DrawGraph(50, 1500 + g_PosY, Endrollimage[5], TRUE);
	DrawGraph(0, 1100 + g_PosY, Endrollimage[6], TRUE);
	DrawGraph(0, 1300 + g_PosY, Endrollimage[7], TRUE);
}

void EndScene::Finalize()
{
}

eSceneType EndScene::GetNowSceneType() const
{
	return eSceneType();
}
