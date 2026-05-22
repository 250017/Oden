#include "PlayScene.h"
#include "Engine\\Model.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void PlayScene::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
	Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	Instantiate<Enemy>(this);
	//Instantiate<Bullet>(this);
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
	////Transform ot;//おでん用のトランスフォーム
	//Model::SetTransform(hModel_, ot_);
	//Model::Draw(hModel_);
	////Model::Draw(hModel_2);
}

void PlayScene::Release()
{
}
