#include "EndScene.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

EndScene::EndScene()
{
	g_WaitTime = 0;
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
}

eSceneType EndScene::Update(float delta_second)
{
	if (++g_WaitTime < 7400)g_PosY = 600 - g_WaitTime / 4;
	
	if (++g_WaitTime > 7500)
	{
		if (g_PosY >= 600 || g_WaitTime >= 8000)
		{
			return eSceneType::eGameEnd;
		}
	}
	return eSceneType();
}

void EndScene::Draw() const
{
	DrawGraph(0, 0, Endimage, TRUE);
	DrawGraph(0, 1300 + g_PosY, Endrollimage[0], TRUE);
	DrawGraph(50, 300 + g_PosY, Endrollimage[1], TRUE);
	DrawGraph(50, 500 + g_PosY, Endrollimage[2], TRUE);
	DrawGraph(50, 700 + g_PosY, Endrollimage[3], TRUE);
	DrawGraph(50, 900 + g_PosY, Endrollimage[4], TRUE);
	DrawGraph(50, 1100 + g_PosY, Endrollimage[5], TRUE);
}

void EndScene::Finalize()
{
}

eSceneType EndScene::GetNowSceneType() const
{
	return eSceneType();
}
