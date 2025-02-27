#include "Player.h"
#include "../../Utility/ResourceManager.h"
#include "../../Utility/InputManager.h"

Player::Player()
	:player_image{}
	,input(nullptr)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	world_pos = Vector2D(200.0f, 400.0f);
	obj_size = Vector2D(50.0f, 120.0f);

	input = InputControl::GetInstance();

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("Resource/Image/Batter_Animation.png", 2, 2, 1, 200, 160);
	player_image[0] = tmp[0];
	player_image[1] = tmp[1];

	image = player_image[0];
}

void Player::Update(float delta_second)
{
	if (input->GetButtonPress(XINPUT_BUTTON_A))
	{
		image = player_image[1];
	}
}

void Player::Draw(Vector2D target) const
{
	__super::Draw(target);
}

void Player::Finalize()
{
}