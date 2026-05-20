#include "PlayScene.h"
#include "Engine\\Model.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), hModel_(-1), hModel_2(-1)
{
}

void PlayScene::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	hModel_2 = Model::Load("test.fbx");
	assert(hModel_ >= 0);
	assert(hModel_2 >= 0);
}

void PlayScene::Update()
{
	static float time = 0.0f;



	ot_.position_ = { 0.0f, 0.0f, 10.0f };
	ot_.scale_ = { 0.5f, 0.5f, 0.5f };
	ot_.rotate_ = { 0.0f, 0.0f, 0.0f };


	//ot_.rotate_.y += 0.1f;//回転させる
	time += 0.025f;
	ot_.position_.x = 6.0f * sin(time);
	//float posx = 6.0*sin(0.2f*time);//右に移動させる
	// float posy = cos(3.0f * time);
	// ot_.position_.x = posx;
	// ot_.position_.y = posy;
}

void PlayScene::Draw()
{
	//Transform ot;//おでん用のトランスフォーム
	Model::SetTransform(hModel_, ot_);
	Model::SetTransform(hModel_2, ot_);
	Model::Draw(hModel_);
	//Model::Draw(hModel_2);
}

void PlayScene::Release()
{
}
