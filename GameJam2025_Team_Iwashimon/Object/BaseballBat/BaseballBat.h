#pragma once
#include "../ObjectBase.h"

class BaseballBat :public ObjectBase
{
private:
	Vector2D velocity;		//移動距離

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
};

