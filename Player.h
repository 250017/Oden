#pragma once
#include "Engine\\GameObject.h"

class Player :
	public GameObject
{
public:
	Player(GameObject* parent);

	void Initialize() override;
	//
	void Update() override;
	//描画
	void Draw() override;
	//解放
	void Release() override;
	
	void OnCollision(GameObject* pTarget) override;
private:
	int hModel_; //モデルのハンドル



};