#include "DxLib.h"
#include "Scene/SceneManager.h"
#include "Utility/ResourceManager.h"
#include "Utility/InputManager.h"

#include <string>

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	//ウインドモードで起動
	ChangeWindowMode(TRUE);

	//DxLibの初期化
	if (DxLib_Init() == -1)
	{
		//失敗した場合はエラー
		return -1;
	}

	//裏画面に描画
	SetDrawScreen(DX_SCREEN_BACK);

	int result = 0;
	//マネージャークラスの初期化
	SceneManager* manager = nullptr;
	ResourceManager* resource = ResourceManager::GetInstance();

	//開始時間を取得
	LONGLONG start_time = GetNowHiPerformanceCount();

	try
	{
		//クラスを生成
		manager = new SceneManager();

		//初期化
		manager->Initialize();

		//インスタンスを取得
		InputControl* input = InputControl::GetInstance();

		//メッセージループに代わる処理をする
		while (ProcessMessage() != -1 && manager->LoopCheck())
		{
			//1フレーム当たりの時間を計算する
			float delta_second = static_cast<float>(GetNowHiPerformanceCount() - start_time) * 0.000001f;

			//開始時間の更新
			start_time = GetNowHiPerformanceCount();

			//入力処理の更新
			input->Update();

			//画面に描かれたものを消去する
			ClearDrawScreen();

			//シーンの更新
			manager->Update(delta_second);

			//裏画面の内容を表画面に表示する
			ScreenFlip();
		}
	}
	catch (std::string& error_text)
	{
		//エラー内容を出力
		OutputDebugString(error_text.c_str());
		result = -1;
	}

	//インスタンスを削除
	InputControl::DeleteInstance();

	//保存した画像と音源データを削除
	resource->UnloadResourceAll();
	resource->UnloadSoundsAll();

	//シーンマネージャーがnullptrでないなら
	if (manager != nullptr)
	{
		//終了時処理
		manager->Finalize();
		//削除する
		delete manager;
	}
	//DxLib終了時処理
	DxLib_End();

	return 0;
}