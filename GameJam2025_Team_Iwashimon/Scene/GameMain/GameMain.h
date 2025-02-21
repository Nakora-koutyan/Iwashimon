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
		//templateインスタンスを生成
		T* new_instance = new T();

		//ObjectBaseのポインタを取得
		ObjectBase* new_object = dynamic_cast<ObjectBase*>(new_instance);

		if (new_object == nullptr)
		{
			delete new_instance;
			throw("ゲームオブジェクトが生成できませんでした。\n");
		}

		//オブジェクトの初期化関数呼び出す
		new_object->Initialize();

		//オブジェクト用の動的配列に格納
		objects.push_back(new_object);

		return new_instance;
	}
};

