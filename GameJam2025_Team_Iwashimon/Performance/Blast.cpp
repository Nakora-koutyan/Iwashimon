#include "Blast.h"
#include "DxLib.h"
#include "../../Utility/ResourceManager.h"

Blast::Blast()
    :bom_flg(false)
    ,alpha_time(255.0f)
    , blast_image{}
{
}

Blast::~Blast()
{
}

void Blast::Initialize()
{
    ResourceManager* rm = ResourceManager::GetInstance();
    std::vector<int> tmp;
    tmp = rm->GetImages("Resource/Image/Explosion animation.png", 2, 2, 1, 75, 64);
    blast_image[0] = tmp[0];
    blast_image[1] = tmp[1];
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
        DrawBox(world_pos.x, world_pos.y, world_pos.x+75, world_pos.y+64, GetColor(255, 0, 0),true);
        DrawString(100, 100, "爆発しました", GetColor(255, 255, 0));

        DrawBox(50, 50, 250, 150, GetColor(255, 0, 0), false);
    }
   
}

void Blast::Finalize()
{
}
