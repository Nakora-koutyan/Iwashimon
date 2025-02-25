#include "Blast.h"
#include "DxLib.h"
Blast::Blast()
    :bom_flg(false)
    ,alpha_time(255.0f)
{
}

Blast::~Blast()
{
}

void Blast::Initialize()
{
	
}

void Blast::Update(float delta_second)
{
    //スペースキーが押されたらtrueにする
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        bom_flg = true;
    }

    if (bom_flg)
    {
        alpha_time -= 0.5f;
    }
}

void Blast::Draw(Vector2D target) const
{
    if (bom_flg) 
    {
        DrawBox(50, 50, 250, 150, GetColor(255, 0, 0),true);
        DrawString(100, 100, "爆発しました", GetColor(255, 255, 0));

        //SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_time);
        DrawBox(50, 50, 250, 150, GetColor(255, 0, 0), false);
        //SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
   
}

void Blast::Finalize()
{
}
