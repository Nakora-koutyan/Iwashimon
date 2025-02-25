#include "EndScene.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

EndScene::EndScene()
{
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
	return eSceneType();
}

void EndScene::Draw() const
{
	DrawGraph(0, 0, Endimage, TRUE);
	DrawGraph(0, 10, Endrollimage[0], TRUE);
}

void EndScene::Finalize()
{
}

eSceneType EndScene::GetNowSceneType() const
{
	return eSceneType();
}
