#pragma once
#include "../Object/ObjectBase.h"

class Blast:public ObjectBase
{
private:
	bool bom_flg;
	float alpha_time;

public:
	Blast();
	~Blast();

public:
	//初期化処理
	void Initialize();
	//更新処理
	void Update(float delta_second);
	//描画
	void Draw(Vector2D target)const;
	//終了時処理
	void Finalize();
};