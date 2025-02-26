#include "TitleScene.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"
TitleScene::TitleScene():

	title_image(NULL),
	cursor_image(NULL),
	cursor_position(0),
    cursor_speed(0.1)
{
	
}

TitleScene::~TitleScene()
{
	
}
void TitleScene::Initialize()
{
	ResourceManager* rm = ResourceManager::GetInstance();

	title_image = LoadGraph("Resource/Image/Title.png");
	cursor_image = LoadGraph("Resource/Image/ball.png");
}


eSceneType TitleScene::Update(float delta_second)
{
	//���͋@�\�̎擾
	InputControl* input = InputControl::GetInstance();

    // �J�[�\���ړ�
    if (input->GetKeyPress(KEY_INPUT_UP) || input->GetButtonPress(XINPUT_BUTTON_DPAD_UP))
    {
        cursor_position = (cursor_position - 1 + 3) % 3; // ��Ɉړ�
    }

    // ���L�[�܂��̓Q�[���p�b�h�̉��{�^���������ꂽ�ꍇ
    if (input->GetKeyPress(KEY_INPUT_DOWN) || input->GetButtonPress(XINPUT_BUTTON_DPAD_DOWN))
    {
        cursor_position = (cursor_position + 1) % 3; // ���Ɉړ�
    }


    // �I�����̌���
    if (input->GetKeyPress(KEY_INPUT_SPACE) || input->GetButtonPress(XINPUT_BUTTON_A))
    {
        if (cursor_position == 0)
        {
            return eSceneType::eInGame;
        }
        else if (cursor_position == 1)
        {
            return eSceneType::eHelp;
        }
        else if (cursor_position == 2)
        {
            return eSceneType::eEnd;
        }
    }



	return GetNowSceneType();
}


void TitleScene::Draw() const   
{

	DrawRotaGraph(320, 240, 1, 0.0, title_image, FALSE);

    float cursor_scale = 0.05f;
    int cursor_y = 280;  // �����ʒu: �C���Q�[��

    // �J�[�\���ʒu�ɉ�����Y���W�̌���
    switch (cursor_position)
    {
    case 0: // �C���Q�[��
        cursor_y = 280;
        break;
    case 1: // �w���v
        cursor_y = 340;
        break;
    case 2: // �G���h
        cursor_y = 430;
        break;
    }

    // �J�[�\���̕`��
    DrawRotaGraph(400, cursor_y, cursor_scale, 0.0, cursor_image, FALSE);
	
}


void TitleScene::Finalize()
{
	
}

eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}