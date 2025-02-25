#include "SceneManager.h"

#include "GameMain/GameMain.h"
#include "Help/HelpScene.h"
#include "Result/ResultScene.h"
#include "Title/TitleScene.h"

SceneManager::SceneManager()
	:current_scene(nullptr)
	, loop_flag(true)
{
}

SceneManager::~SceneManager()
{
	this->Finalize();
}

void SceneManager::Initialize()
{
	//タイトル画面からスタート
	ChangeScene(eSceneType::eInGame);
}

void SceneManager::Update(float delta_second)
{
	//現在のシーンのUpdate処理
	eSceneType next_scene_type = current_scene->Update(delta_second);
	//現在のシーンの描画
	current_scene->Draw();

	//次のシーンタイプと現在のシーンタイプが異なる場合
	if (next_scene_type != current_scene->GetNowSceneType())
	{
		//シーンを切り替える
		ChangeScene(next_scene_type);
	}
}

void SceneManager::Finalize()
{
	if (current_scene != nullptr)
	{
		//現在シーンの終了時処理の呼び出し
		current_scene->Finalize();
		//現在シーンを削除
		delete current_scene;
		//シーン情報を空にする
		current_scene = nullptr;
	}
}

bool SceneManager::LoopCheck() const
{
	return loop_flag;
}

void SceneManager::ChangeScene(eSceneType new_scene_type)
{
	//シーンがEnd画面ならloopを終了する
	if (new_scene_type == eSceneType::eEnd)
	{
		loop_flag = false;
		return;
	}

	//新しいシーンの情報を取得
	SceneBase* new_scene = CreateScene(new_scene_type);

	//シーン情報を取得できなかった場合、エラーメッセージを送信
	if (new_scene == nullptr)
	{
		throw("\n新しいシーンの生成ができませんでした\n");
	}
	//現在シーン情報が残っていれば消去し空の状態にする
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
	}

	//新しいシーンの初期化処理を呼び出す
	new_scene->Initialize();

	//シーンを新しいシーンに更新
	current_scene = new_scene;
}

SceneBase* SceneManager::CreateScene(eSceneType new_scene_type)
{
	//シーン切り替え
	switch (new_scene_type)
	{
	case eSceneType::eTitle:	//タイトル画面
		return  dynamic_cast<SceneBase*> (new TitleScene());
		break;

	case eSceneType::eInGame:	//ゲームメイン画面
		return dynamic_cast<SceneBase*> (new GameMain());
		break;

	case eSceneType::eHelp:		//ヘルプ画面
		return  dynamic_cast<SceneBase*> (new HelpScene());
		break;

	case eSceneType::eResult:	//リザルト画面
		return  dynamic_cast<SceneBase*> (new ResultScene());

	case eSceneType::eEnd:		//エンド画面
		return 0;

	default:
		return nullptr;
	}
}