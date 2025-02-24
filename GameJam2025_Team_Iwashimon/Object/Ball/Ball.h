#pragma once
#include "../ObjectBase.h"
#define D_GRAVITY  (9.897f)					//define gravity

class Ball:public ObjectBase
{
private:
	int ballflag;							//spacebarActivationFlag
	Vector2D speed;							//uniform speed
	int WaitTime;							//manipulate time
	class InputControl* input;
	float g_velocity;						//simulate gravity

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