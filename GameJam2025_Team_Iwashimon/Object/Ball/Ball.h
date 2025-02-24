#pragma once
#include "../ObjectBase.h"

class Ball:public ObjectBase
{
private:
	int ballflag;						//スペースキーが押されたらボールが飛ぶためのフラグ
	int speed;							//固定速度
	int ballx[5], bally[5];				//ボールが飛んでいるように見える変数
	int WaitTime;						//時間を制御する
	int ballX;							//一定時間その場でとどまるようにする変数

public:
	Ball();
	~Ball();

public:
	//初期化処理
	void Initialize();
	//更新処理
	void Update(float delta_second);
	//描画
	void Draw(Vector2D target)const;
	//終了時処理
	void Finalize();
};