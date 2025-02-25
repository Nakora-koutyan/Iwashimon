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
	input = InputControl::GetInstance();	//�C���X�^���X�擾

	obj_size = Vector2D(40.0f);				//�I�u�W�F�N�g�̃T�C�Y�ݒ�

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
		//��]���W
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
	amplitude += ANGLE_VELOCITY;							//�p�x�ɒl�����Z��������
	frequency = (amplitude * (DX_PI_F / 180.0f));			//�p�x�����W�A���l�ɕϊ�

	Vector2D length = Vector2D(10.0f, 2.0f);

	float af = (VEC_ANGLE * (DX_PI_F / 180.0f));	//��]�̎��̊p�x
	Vector2D m = { (float)(cos(af) * length.x),(float)(sin(af) * length.y) };

	velocity.x = world_pos.x + (cos(frequency) * m.x);											//�U��q�̓�����x���W
	velocity.y = world_pos.y + (cos(frequency) * m.y) + (float)(sin(frequency) * length.y);		//�U��q�̓�����y���W 
}

void BaseballBat::Pendulum()
{
}