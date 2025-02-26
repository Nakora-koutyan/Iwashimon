#include "TitleScene.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"
TitleScene::TitleScene():

	title_image(NULL),
	cursor_image(NULL),
	cursor_position(0),
    cursor_speed(0.1)
{
	
}

TitleScene::~TitleScene()
{
	
}
void TitleScene::Initialize()
{
	ResourceManager* rm = ResourceManager::GetInstance();

	title_image = LoadGraph("Resource/Image/Title.png");
	cursor_image = LoadGraph("Resource/Image/ball.png");
}


eSceneType TitleScene::Update(float delta_second)
{
	//入力機能の取得
	InputControl* input = InputControl::GetInstance();

    // カーソル移動
    if (input->GetKeyPress(KEY_INPUT_UP) || input->GetButtonPress(XINPUT_BUTTON_DPAD_UP))
    {
        cursor_position = (cursor_position - 1 + 3) % 3; // 上に移動
    }

    // 下キーまたはゲームパッドの下ボタンが押された場合
    if (input->GetKeyPress(KEY_INPUT_DOWN) || input->GetButtonPress(XINPUT_BUTTON_DPAD_DOWN))
    {
        cursor_position = (cursor_position + 1) % 3; // 下に移動
    }


    // 選択肢の決定
    if (input->GetKeyPress(KEY_INPUT_SPACE) || input->GetButtonPress(XINPUT_BUTTON_A))
    {
        if (cursor_position == 0)
        {
            return eSceneType::eInGame;
        }
        else if (cursor_position == 1)
        {
            return eSceneType::eHelp;
        }
        else if (cursor_position == 2)
        {
            return eSceneType::eEnd;
        }
    }



	return GetNowSceneType();
}


void TitleScene::Draw() const   
{

	DrawRotaGraph(320, 240, 1, 0.0, title_image, FALSE);

    float cursor_scale = 0.05f;
    int cursor_y = 280;  // 初期位置: インゲーム

    // カーソル位置に応じたY座標の決定
    switch (cursor_position)
    {
    case 0: // インゲーム
        cursor_y = 280;
        break;
    case 1: // ヘルプ
        cursor_y = 340;
        break;
    case 2: // エンド
        cursor_y = 430;
        break;
    }

    // カーソルの描画
    DrawRotaGraph(400, cursor_y, cursor_scale, 0.0, cursor_image, FALSE);
	
}


void TitleScene::Finalize()
{
	
}

eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}