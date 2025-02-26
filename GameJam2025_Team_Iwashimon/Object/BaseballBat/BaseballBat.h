#pragma once
#include "../ObjectBase.h"

class BaseballBat :public ObjectBase
{
private:
	class InputControl* input;	//入力インスタンスを取得

	Vector2D velocity;		//移動距離

	float amplitude;		//角度
	float frequency;		//ラジアン値

	bool is_swinging;		//バットを振った？

	int Hit_SE;
	int Bakuhatu_SE;

public:
	BaseballBat();
	~BaseballBat();

public:
	//初期化処理
	void Initialize()override;
	//更新処理
	void Update(float delta_second)override;
	//描画
	void Draw(Vector2D target)const override;
	//終了時処理
	void Finalize()override;

private:
	//回転処理
	void Rolling();

	//振子処理
	void Pendulum();
};

