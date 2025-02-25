#include "TitleScene.h"
#include "../../Utility/InputManager.h"
#include "DxLib.h"
TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}
void TitleScene::Initialize()
{

}


eSceneType TitleScene::Update(float delta_second)
{
	//入力機能の取得
	InputControl* input = InputControl::GetInstance();

	//インゲーム画面に移動する
	if (input->GetKeyPress(KEY_INPUT_SPACE))
	{
		return eSceneType::eInGame;
	}

	if (input->GetButtonPress(XINPUT_BUTTON_START))
	{
		return eSceneType::eInGame;
	}
	
	return GetNowSceneType();
}


void TitleScene::Draw() const   //描画処理
{
	
	SetFontSize(60);
	DrawFormatString(120, 140, GetColor(255, 0, 0), "タイトル画面（仮）");
}


void TitleScene::Finalize()
{
	
}

eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}