#include "BaseballBat.h"
#include "../../Utility/InputManager.h"
#include <math.h>
#include "../../Utility/ResourceManager.h"

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

	world_pos = Vector2D(200.0f, 400.0f);
	obj_size = Vector2D(40.0f);				//�I�u�W�F�N�g�̃T�C�Y�ݒ�

	obj_type = ObjectType::eBat;
	ResourceManager* rs = ResourceManager::GetInstance();
	int SE;
	SE = rs->GetSounds("Resource/Sound/SE/hit_SE.mp3");
	Hit_SE = SE;
	SE = rs->GetSounds("Resource/Sound/SE/bakuha.mp3");
	Bakuhatu_SE = SE;
}

void BaseballBat::Update(float delta_second)
{
	if (input->GetKeyPress(KEY_INPUT_SPACE))
	{
		PlaySoundMem(Hit_SE, DX_PLAYTYPE_BACK, TRUE);
		PlaySoundMem(Bakuhatu_SE, DX_PLAYTYPE_BACK, TRUE);
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

	float af = (VEC_ANGLE * (DX_PI_F / 180.0f));												//��]�̎��̊p�x
	Vector2D m = { (float)(cos(af) * length.x),(float)(sin(af) * length.y) };

	velocity.x = world_pos.x + (cos(frequency) * m.x);											//�U��q�̓�����x���W
	velocity.y = world_pos.y + (cos(frequency) * m.y) + (float)(sin(frequency) * length.y);		//�U��q�̓�����y���W 
}

void BaseballBat::Pendulum()
{
}