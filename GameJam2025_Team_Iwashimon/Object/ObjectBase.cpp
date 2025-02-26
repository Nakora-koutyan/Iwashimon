#include "ObjectBase.h"
#include "DxLib.h"
#include <math.h>

ObjectBase::ObjectBase()
	:world_pos(0.0f)
	,obj_size(0.0f)
	,image(NULL)
	,reverse_image(TRUE)
	, obj_type(ObjectType::eOther)
{
}

ObjectBase::~ObjectBase()
{
}

void ObjectBase::Initialize()
{
}

void ObjectBase::Update(float delta_second)
{
}

void ObjectBase::Draw(Vector2D target_pos) const
{
	//追尾対象を決定
	Vector2D camera_pos = target_pos;

	//カメラがステージの一番上からはみ出さなようにする
	if ((camera_pos.y - (SCREEN_HEIGHT * 0.5f)) <= 0)
	{
		camera_pos.y = (SCREEN_HEIGHT * 0.5f);
	}
	//カメラがステージの底より下にならないようにする
	if (STAGE_HEIGHT <= (camera_pos.y + (SCREEN_HEIGHT * 0.5f)))
	{
		camera_pos.y = STAGE_HEIGHT - (SCREEN_HEIGHT * 0.5f);
	}

	//カメラ座標からスクリーン座標の原点に変換する
	Vector2D screen_origin_pos;
	screen_origin_pos.x = camera_pos.x - (SCREEN_WIDTH * 0.5f);
	screen_origin_pos.y = camera_pos.y - (SCREEN_HEIGHT * 0.5f);

	//オブジェクト自身のワールドでの座標をスクリーンの座標に変換
	Vector2D screen_pos;
	screen_pos.x = world_pos.x - screen_origin_pos.x;
	screen_pos.y = world_pos.y - screen_origin_pos.y;

	/*DrawBoxAA(screen_pos.x - (obj_size.x * 0.5f), screen_pos.y - (obj_size.y * 0.5f),
		screen_pos.x + (obj_size.x * 0.5f), screen_pos.y + (obj_size.y * 0.5f),
		GetColor(255, 0, 0), TRUE);*/
	DrawRotaGraphF(screen_pos.x, screen_pos.y, 1.0f, 0, image, reverse_image);
}

void ObjectBase::Finalize()
{
}

void ObjectBase::OnCollisionEnter(ObjectBase* obj)
{
}

bool ObjectBase::CollisionHit(ObjectBase* obj)
{
	bool result = false;

	//自身のObjの座標と半径を取得
	Vector2D a = Vector2D(this->GetLocation());
	float a_r = (this->obj_size.x);
	//対象のObjの座標と半径を取得
	Vector2D b = Vector2D(obj->GetLocation());
	float b_r = (obj->obj_size.x);

	//半径の距離を求める
	float r_direct = a_r + b_r;

	//a²+b²＝c²(ルートでcの実際の長さを取得する所まで)
	float loc_direct = sqrt(powf((a.x - b.x), 2.0f) + powf((a.x - b.x), 2.0f));

	if (loc_direct <= r_direct)
	{
		result = true;
	}

	return result;
}

void ObjectBase::SetLocation(Vector2D location)
{
	world_pos = location;
}