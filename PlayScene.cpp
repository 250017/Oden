#include "PlayScene.h"
#include "Engine\\Model.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void PlayScene::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
	Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	Enemy* enemy = Instantiate<Enemy>(this);
	Camera::SetPosition(XMFLOAT3(0, 0, -25));
	CameraTargetPos = { 0, 0, 50 };

	//Enemy* e1 = Instantiate<Enemy>(this);
	//e1->SetPosition(0, 0, 30);
	//Enemy* e2 = Instantiate<Enemy>(this);
	//e2->SetPosition(0, 0, 50);
	//spawnTimer = 0;
	//Instantiate<Bullet>(this);
}

void PlayScene::Update()
{
	spawnTimer++;
	Camera::SetTarget(CameraTargetPos);

	if (spawnTimer / 60 > 5) {
		Enemy* enemy = Instantiate<Enemy>(this);
		enemy->SetPosition(rand() % 30 - 15, rand() % 16 - 8, rand() % 100);
		spawnTimer = 0;
	}
	if (FindObject("Enemy") == nullptr) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
	//視点の移動
	//if (Input::IsKey(DIK_UP)) {
	//	CameraTargetPos.y -= 1;
	//}
	//if (Input::IsKey(DIK_DOWN)) {
	//	CameraTargetPos.y += 1;
	//}
	//if (Input::IsKey(DIK_RIGHT)) {
	//	CameraTargetPos.x += 1;
	//}
	//if (Input::IsKey(DIK_LEFT)) {
	//	CameraTargetPos.x -= 1;
	//}
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
