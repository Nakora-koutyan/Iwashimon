#pragma once
#include "SceneBase.h"

class SceneManager
{
private:
	SceneBase* current_scene;	//���݃V�[��
	bool loop_flag;				//�V�[�����[�v�̃t���O
public:
	SceneManager();
	~SceneManager();
public:
	void Initialize();		//������
	void Update(float delta_second);	//�X�V
	void Finalize();		//�I��������

public:
	bool LoopCheck()const;

private:
	void ChangeScene(eSceneType new_scene_type);	//�V�[���؂�ւ�����
	SceneBase* CreateScene(eSceneType new_scene_type);		//�V�[������
};