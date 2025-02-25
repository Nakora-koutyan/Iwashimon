#include "ObjectBase.h"
#include "DxLib.h"

ObjectBase::ObjectBase()
	:world_pos(0.0f)
	,obj_size(0.0f)
	,image(NULL)
	,reverse_image(NULL)
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
	//�ǔ��Ώۂ�����
	Vector2D camera_pos = target_pos;

	//�J�������X�e�[�W�̈�ԏォ��͂ݏo���Ȃ悤�ɂ���
	if ((camera_pos.y - (SCREEN_HEIGHT * 0.5f)) <= 0)
	{
		camera_pos.y = (SCREEN_HEIGHT * 0.5f);
	}
	//�J�������X�e�[�W�̒��艺�ɂȂ�Ȃ��悤�ɂ���
	if (STAGE_HEIGHT <= (camera_pos.y + (SCREEN_HEIGHT * 0.5f)))
	{
		camera_pos.y = STAGE_HEIGHT - (SCREEN_HEIGHT * 0.5f);
	}

	//�J�������W����X�N���[�����W�̌��_�ɕϊ�����
	Vector2D screen_origin_pos;
	screen_origin_pos.x = camera_pos.x - (SCREEN_WIDTH * 0.5f);
	screen_origin_pos.y = camera_pos.y - (SCREEN_HEIGHT * 0.5f);

	//�I�u�W�F�N�g���g�̃��[���h�ł̍��W���X�N���[���̍��W�ɕϊ�
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
	bool result = false;

	//���g��Obj�̍��W�Ɣ��a���擾
	Vector2D a = Vector2D(this->GetLocation());
	float a_r = (this->obj_size.x);
	//�Ώۂ�Obj�̍��W�Ɣ��a���擾
	Vector2D b = Vector2D(obj->GetLocation());
	float b_r = (obj->obj_size.x);

	//���a�̋��������߂�
	float r_direct = a_r + b_r;



	return result;
}

void ObjectBase::SetLocation(Vector2D location)
{
}