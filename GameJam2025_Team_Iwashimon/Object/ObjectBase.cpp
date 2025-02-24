#include "ObjectBase.h"
#include "DxLib.h"

ObjectBase::ObjectBase()
	:world_pos(0.0f)
	,obj_size(0.0f)
	,image(NULL)
	,reverse_image(NULL)
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

	DrawBoxAA(screen_pos.x - (obj_size.x * 0.5f), screen_pos.y - (obj_size.y * 0.5f),
		screen_pos.x + (obj_size.x * 0.5f), screen_pos.y + (obj_size.y * 0.5f),
		GetColor(255, 0, 0), TRUE);
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
	return false;
}

void ObjectBase::SetLocation(Vector2D location)
{
}