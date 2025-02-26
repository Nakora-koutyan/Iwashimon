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
    image = blast_image[0];
}

void Blast::Update(float delta_second)
{
}

void Blast::Draw(Vector2D target) const
{
    __super::Draw(target);
}

void Blast::Finalize()
{
}
