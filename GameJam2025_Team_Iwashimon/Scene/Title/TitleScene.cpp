#include "TitleScene.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include <chrono>
#include <thread>
#include "DxLib.h"

TitleScene::TitleScene():

	title_image(NULL),
	cursor_image(NULL),
    ClickSound(NULL),
	cursor_position(0),
    cursor_speed(0.1),
    move_interval(),
    ClickSoundInitialized(false)
{
	
}

TitleScene::~TitleScene()
{

}
void TitleScene::Initialize()
{
	ResourceManager* rm = ResourceManager::GetInstance();
    std::vector<int> tmp;
    tmp = rm->GetImages("Resource/Image/ball.png");
    cursor_image = tmp[0];

    tmp = rm->GetImages("Resource/Image/Title.png");
    title_image = tmp[0];
	
     BGM = rm->GetSounds("Resource/Sound/BGM/イマジン・エマージェンシ.mp3");
    PlaySoundMem(BGM, DX_PLAYTYPE_BACK);
    
   

    if (!ClickSoundInitialized) {
        ClickSound = rm->GetSounds("Resource/Sound/SE/button_click.mp3");
        ClickSoundInitialized = true;  // 初期化済みフラグを立てる
    }
   
}


eSceneType TitleScene::Update(float delta_second)
{

    InputControl* input = InputControl::GetInstance();

   
 




    // カーソル移動の遅延時間
    const float move_delay = 0.2f;  
    static auto last_move_time = std::chrono::steady_clock::now();  

    // カーソル移動処理
    auto current_time = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsed_time = current_time - last_move_time;

    if (elapsed_time.count() >= move_delay) {  

        //十字キーでの移動
        if (input->GetKeyPress(KEY_INPUT_UP) || input->GetButtonPress(XINPUT_BUTTON_DPAD_UP)) {
            cursor_position = (cursor_position - 1 + 3) % 3; // 上に移動
            last_move_time = current_time;  
            PlaySoundMem(ClickSound, DX_PLAYTYPE_BACK);
        }

        if (input->GetKeyPress(KEY_INPUT_DOWN) || input->GetButtonPress(XINPUT_BUTTON_DPAD_DOWN)) {
            cursor_position = (cursor_position + 1) % 3; // 下に移動
            last_move_time = current_time;  
            PlaySoundMem(ClickSound, DX_PLAYTYPE_BACK);
        }


        // 左スティックでの移動 (上下方向)
        Vector2D left_stick = input->GetLStickPos(); 
        if (left_stick.y < -0.5f) {  //上に倒したら
            cursor_position = (cursor_position + 1 ) % 3; // 上に移動
            last_move_time = current_time;
            PlaySoundMem(ClickSound, DX_PLAYTYPE_BACK);
        }
        else if (left_stick.y > 0.5f) { // 下に倒しやた
            cursor_position = (cursor_position - 1 + 3) % 3; // 下に移動
            last_move_time = current_time;
            PlaySoundMem(ClickSound, DX_PLAYTYPE_BACK);
        }


    }

    // 選択肢の決定
    if (input->GetKeyPress(KEY_INPUT_SPACE) || input->GetButtonPress(XINPUT_BUTTON_A))
    {
        if (cursor_position == 0)
        {
            PlaySoundMem(ClickSound, DX_PLAYTYPE_BACK);
            StopSoundMem(BGM); // BGMを停止
            return eSceneType::eInGame;
            // BGMを停止する処理
           

        }
        else if (cursor_position == 1)
        {
            PlaySoundMem(ClickSound, DX_PLAYTYPE_BACK);
            StopSoundMem(BGM);
            return eSceneType::eHelp;
        }
        else if (cursor_position == 2)
        {
            PlaySoundMem(ClickSound, DX_PLAYTYPE_BACK);
            StopSoundMem(BGM);
            return eSceneType::eEnd;
            
        }
    }



	return GetNowSceneType();
}


void TitleScene::Draw() const   
{

	DrawRotaGraph(320, 240, 1, 0.0, title_image, FALSE);

    float cursor_scale = 1.0f;
    int cursor_y = 270;  // 初期位置: インゲーム

    // カーソル位置に応じたY座標の決定
    switch (cursor_position)
    {
    case 0: // インゲーム
        cursor_y = 270;
        break;
    case 1: // ヘルプ
        cursor_y = 340;
        break;
    case 2: // エンド
        cursor_y = 410;
        break;
    }

    // カーソルの描画
    DrawRotaGraph(420, cursor_y, cursor_scale, 0.0, cursor_image, TRUE);
	
}


void TitleScene::Finalize()
{
	
}

eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}