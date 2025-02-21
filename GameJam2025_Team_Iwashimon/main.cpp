#include "DxLib.h"
#include "Scene/SceneManager.h"
#include "Utility/ResourceManager.h"
#include "Utility/InputManager.h"

#include <string>

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	//�E�C���h���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//DxLib�̏�����
	if (DxLib_Init() == -1)
	{
		//���s�����ꍇ�̓G���[
		return -1;
	}

	//����ʂɕ`��
	SetDrawScreen(DX_SCREEN_BACK);

	int result = 0;
	//�}�l�[�W���[�N���X�̏�����
	SceneManager* manager = nullptr;
	ResourceManager* resource = ResourceManager::GetInstance();

	//�J�n���Ԃ��擾
	LONGLONG start_time = GetNowHiPerformanceCount();

	try
	{
		//�N���X�𐶐�
		manager = new SceneManager();

		//������
		manager->Initialize();

		//�C���X�^���X���擾
		InputControl* input = InputControl::GetInstance();

		//���b�Z�[�W���[�v�ɑ��鏈��������
		while (ProcessMessage() != -1 && manager->LoopCheck())
		{
			//1�t���[��������̎��Ԃ��v�Z����
			float delta_second = static_cast<float>(GetNowHiPerformanceCount() - start_time) * 0.000001f;

			//�J�n���Ԃ̍X�V
			start_time = GetNowHiPerformanceCount();

			//���͏����̍X�V
			input->Update();

			//��ʂɕ`���ꂽ���̂���������
			ClearDrawScreen();

			//�V�[���̍X�V
			manager->Update(delta_second);

			//����ʂ̓��e��\��ʂɕ\������
			ScreenFlip();
		}
	}
	catch (std::string& error_text)
	{
		//�G���[���e���o��
		OutputDebugString(error_text.c_str());
		result = -1;
	}

	//�C���X�^���X���폜
	InputControl::DeleteInstance();

	//�ۑ������摜�Ɖ����f�[�^���폜
	resource->UnloadResourceAll();
	resource->UnloadSoundsAll();

	//�V�[���}�l�[�W���[��nullptr�łȂ��Ȃ�
	if (manager != nullptr)
	{
		//�I��������
		manager->Finalize();
		//�폜����
		delete manager;
	}
	//DxLib�I��������
	DxLib_End();

	return 0;
}