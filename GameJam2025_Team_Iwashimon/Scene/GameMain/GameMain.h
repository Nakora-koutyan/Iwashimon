#pragma once
#include "../SceneBase.h"
#include "../../Utility/Vector2D.h"
#include "../../Object/ObjectBase.h"

#include "../../Performance/Gauge.h"

class GameMain :public SceneBase
{
private:
	Gauge* gauge;

	class InputControl* input;
	std::vector<ObjectBase*>objects;

public:
	GameMain();
	~GameMain();

public:
	void Initialize()override;
	eSceneType Update(float delta_second)override;
	void Draw()const override;
	void Finalize()override;

public:
	eSceneType GetNowSceneType()const override;

private:
	template <class T>
	T* CreateObject()
	{
		//template�C���X�^���X�𐶐�
		T* new_instance = new T();

		//ObjectBase�̃|�C���^���擾
		ObjectBase* new_object = dynamic_cast<ObjectBase*>(new_instance);

		if (new_object == nullptr)
		{
			delete new_instance;
			throw("�Q�[���I�u�W�F�N�g�������ł��܂���ł����B\n");
		}

		//�I�u�W�F�N�g�̏������֐��Ăяo��
		new_object->Initialize();

		//�I�u�W�F�N�g�p�̓��I�z��Ɋi�[
		objects.push_back(new_object);

		return new_instance;
	}
};

