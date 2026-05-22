#pragma once
#include "Engine\\GameObject.h"
class Clear :
    public GameObject
{
public:
    Clear(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
private:
    int hClearPic_;//モデルのハンドル

};

