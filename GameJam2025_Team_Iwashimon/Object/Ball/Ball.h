#pragma once
#include "../ObjectBase.h"
#define D_GRAVITY  (9.897f)					//define gravity

class Ball:public ObjectBase
{
private:
	Vector2D speed;							//uniform speed
	class InputControl* input;
	float g_velocity;						//simulate gravity
	double angle;							//radian conversion
	double startangle;						//launch angle(start)
	double time;								
	double x, y;
	double dt;
	double speed1;

	const float max_a = 500.0f;
	const float min_a = 0.0f;

	bool is_air;

	float target_length;
	float target_height;

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

	//ヒットした際の処理
	void OnCollisionEnter(ObjectBase* obj)override;

	//高さ目標の長さを設定する
	void SetTargetHeight(float length);

	bool GetIsAir()const { return is_air; }
};