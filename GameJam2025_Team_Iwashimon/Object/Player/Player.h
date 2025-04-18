#pragma once
#include "../ObjectBase.h"

class Player:public ObjectBase
{
private:
	int player_image[2];
	class InputControl* input;

public:
	Player();
	~Player();

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

