#pragma once
#include "SceneBase.h"

class SceneManager
{
private:
	SceneBase* current_scene;	//現在シーン
	bool loop_flag;				//シーンループのフラグ
public:
	SceneManager();
	~SceneManager();
public:
	void Initialize();		//初期化
	void Update(float delta_second);	//更新
	void Finalize();		//終了時処理

public:
	bool LoopCheck()const;

private:
	void ChangeScene(eSceneType new_scene_type);	//シーン切り替え処理
	SceneBase* CreateScene(eSceneType new_scene_type);		//シーン生成
};