#pragma once
#include "../Object/ObjectBase.h"

class SpeedBoost :public ObjectBase
{
private:

public:
	SpeedBoost();
	~SpeedBoost();

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