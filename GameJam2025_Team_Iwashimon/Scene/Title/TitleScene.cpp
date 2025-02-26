#include "TitleScene.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include <chrono>
#include <thread>
#include "DxLib.h"

TitleScene::TitleScene():

	title_image(NULL),
	cursor_image(NULL),
    ClickSound(0),
	cursor_position(0),
    cursor_speed(0.1),
    move_interval()
{
	
}

TitleScene::~TitleScene()
{

}
void TitleScene::Initialize()
{
	ResourceManager* rm = ResourceManager::GetInstance();
    std::vector<int> tmp;
    tmp = rm->GetImages("Resource/Image/ball.png");
    cursor_image = tmp[0];

    tmp = rm->GetImages("Resource/Image/Title.png");
    title_image = tmp[0];
	

    
   

}


eSceneType TitleScene::Update(float delta_second)
{

    InputControl* input = InputControl::GetInstance();


    




    // �J�[�\���ړ��̒x������
    const float move_delay = 0.2f;  
    static auto last_move_time = std::chrono::steady_clock::now();  

    // �J�[�\���ړ�����
    auto current_time = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsed_time = current_time - last_move_time;

    if (elapsed_time.count() >= move_delay) {  

        //�\���L�[�ł̈ړ�
        if (input->GetKeyPress(KEY_INPUT_UP) || input->GetButtonPress(XINPUT_BUTTON_DPAD_UP)) {
            cursor_position = (cursor_position - 1 + 3) % 3; // ��Ɉړ�
            last_move_time = current_time;  
        }

        if (input->GetKeyPress(KEY_INPUT_DOWN) || input->GetButtonPress(XINPUT_BUTTON_DPAD_DOWN)) {
            cursor_position = (cursor_position + 1) % 3; // ���Ɉړ�
            last_move_time = current_time;  
        }


        // ���X�e�B�b�N�ł̈ړ� (�㉺����)
        Vector2D left_stick = input->GetLStickPos(); 
        if (left_stick.y < -0.5f) {  //��ɓ|������
            cursor_position = (cursor_position + 1 ) % 3; // ��Ɉړ�
            last_move_time = current_time;
        }
        else if (left_stick.y > 0.5f) { // ���ɓ|���₽
            cursor_position = (cursor_position - 1 + 3) % 3; // ���Ɉړ�
            last_move_time = current_time;
        }


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

    float cursor_scale = 1.0f;
    int cursor_y = 280;  // �����ʒu: �C���Q�[��

    // �J�[�\���ʒu�ɉ�����Y���W�̌���
    switch (cursor_position)
    {
    case 0: // �C���Q�[��
        cursor_y = 280;
        break;
    case 1: // �w���v
        cursor_y = 350;
        break;
    case 2: // �G���h
        cursor_y = 430;
        break;
    }

    // �J�[�\���̕`��
    DrawRotaGraph(420, cursor_y, cursor_scale, 0.0, cursor_image, TRUE);
	
}


void TitleScene::Finalize()
{
	
}

eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}