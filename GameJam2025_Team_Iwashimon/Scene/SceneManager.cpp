#include "SceneManager.h"

#include "GameMain/GameMain.h"
#include "Help/HelpScene.h"
#include "Result/ResultScene.h"
#include "Title/TitleScene.h"

SceneManager::SceneManager()
	:current_scene(nullptr)
	, loop_flag(true)
{
}

SceneManager::~SceneManager()
{
	this->Finalize();
}

void SceneManager::Initialize()
{
	//�^�C�g����ʂ���X�^�[�g
	ChangeScene(eSceneType::eInGame);
}

void SceneManager::Update(float delta_second)
{
	//���݂̃V�[����Update����
	eSceneType next_scene_type = current_scene->Update(delta_second);
	//���݂̃V�[���̕`��
	current_scene->Draw();

	//���̃V�[���^�C�v�ƌ��݂̃V�[���^�C�v���قȂ�ꍇ
	if (next_scene_type != current_scene->GetNowSceneType())
	{
		//�V�[����؂�ւ���
		ChangeScene(next_scene_type);
	}
}

void SceneManager::Finalize()
{
	if (current_scene != nullptr)
	{
		//���݃V�[���̏I���������̌Ăяo��
		current_scene->Finalize();
		//���݃V�[�����폜
		delete current_scene;
		//�V�[��������ɂ���
		current_scene = nullptr;
	}
}

bool SceneManager::LoopCheck() const
{
	return loop_flag;
}

void SceneManager::ChangeScene(eSceneType new_scene_type)
{
	//�V�[����End��ʂȂ�loop���I������
	if (new_scene_type == eSceneType::eEnd)
	{
		loop_flag = false;
		return;
	}

	//�V�����V�[���̏����擾
	SceneBase* new_scene = CreateScene(new_scene_type);

	//�V�[�������擾�ł��Ȃ������ꍇ�A�G���[���b�Z�[�W�𑗐M
	if (new_scene == nullptr)
	{
		throw("\n�V�����V�[���̐������ł��܂���ł���\n");
	}
	//���݃V�[����񂪎c���Ă���Ώ�������̏�Ԃɂ���
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
	}

	//�V�����V�[���̏������������Ăяo��
	new_scene->Initialize();

	//�V�[����V�����V�[���ɍX�V
	current_scene = new_scene;
}

SceneBase* SceneManager::CreateScene(eSceneType new_scene_type)
{
	//�V�[���؂�ւ�
	switch (new_scene_type)
	{
	case eSceneType::eTitle:	//�^�C�g�����
		return  dynamic_cast<SceneBase*> (new TitleScene());
		break;

	case eSceneType::eInGame:	//�Q�[�����C�����
		return dynamic_cast<SceneBase*> (new GameMain());
		break;

	case eSceneType::eHelp:		//�w���v���
		return  dynamic_cast<SceneBase*> (new HelpScene());
		break;

	case eSceneType::eResult:	//���U���g���
		return  dynamic_cast<SceneBase*> (new ResultScene());

	case eSceneType::eEnd:		//�G���h���
		return 0;

	default:
		return nullptr;
	}
}