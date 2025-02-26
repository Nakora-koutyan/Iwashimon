#pragma once
#include "../SceneBase.h"

class TitleScene :public SceneBase
{
private:
	int title_image;
	int selectedIndex;
	int cursor_image;
	int cursor_position;
	int cursor_speed;
	int move_interval;
	int Sound_data;
public:
	TitleScene();
	virtual ~TitleScene();

	//初期化処理
	virtual void Initialize() override;

	virtual eSceneType Update(float delta_second);

	//描画処理
	virtual void Draw() const override;

	//終了処理
	virtual void Finalize() override;


	//現在のシーンタイプ (オーバーライド必須)
	virtual eSceneType GetNowSceneType() const override;
public:

};

