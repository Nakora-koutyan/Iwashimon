#include "BaseballBat.h"
#include "../../Utility/InputManager.h"
#include <math.h>

#define ANGLE_VELOCITY (10.0f)
#define VEC_ANGLE (180.0f)

BaseballBat::BaseballBat()
	:velocity(0.0f)
	, amplitude(0.0f)
	, frequency(0.0f)
	, is_swinging(false)
	, input(nullptr)
{
}

BaseballBat::~BaseballBat()
{
}

void BaseballBat::Initialize()
{
	input = InputControl::GetInstance();	//インスタンス取得

	obj_size = Vector2D(40.0f);				//オブジェクトのサイズ設定

	obj_type = ObjectType::eBat;
}

void BaseballBat::Update(float delta_second)
{
	if (input->GetKeyPress(KEY_INPUT_SPACE))
	{
		is_swinging = true;
	}

	if (is_swinging)
	{
		//回転座標
		Rolling();
		world_pos = velocity;
	}
}

void BaseballBat::Draw(Vector2D target) const
{
	DrawFormatStringF(200, 300, GetColor(255, 255, 255), "%lf %lf", world_pos.x, world_pos.y);
	__super::Draw(target);
}

void BaseballBat::Finalize()
{
}

void BaseballBat::Rolling()
{
	amplitude += ANGLE_VELOCITY;							//角度に値を加算し続ける
	frequency = (amplitude * (DX_PI_F / 180.0f));			//角度をラジアン値に変換

	Vector2D length = Vector2D(10.0f, 2.0f);

	float af = (VEC_ANGLE * (DX_PI_F / 180.0f));	//回転の軸の角度
	Vector2D m = { (float)(cos(af) * length.x),(float)(sin(af) * length.y) };

	velocity.x = world_pos.x + (cos(frequency) * m.x);											//振り子の動きのx座標
	velocity.y = world_pos.y + (cos(frequency) * m.y) + (float)(sin(frequency) * length.y);		//振り子の動きのy座標 
}

void BaseballBat::Pendulum()
{
}