#pragma once
#include "Engine\\GameObject.h"
class Egg :
    public GameObject
{
public:
    Egg(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void OnCollision(GameObject* pTarget) override;
private:
    int hModel_;//モデルのハンドル
    float time = 0.0f;


};

