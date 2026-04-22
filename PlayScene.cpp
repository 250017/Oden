#include "PlayScene.h"
#include "Engine\\Model.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), hModel_(-1)
{
}

void PlayScene::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
	time_ = 0;
	ot_.position_ = { 0.0f, 0.0f, 0.0f };
}

void PlayScene::Update()
{
	time_++;
	ot_.scale_ = { 1.0f, 1.0f, 1.0f };
	ot_.rotate_.y += 0.1f;//回転させる
	if (time_ % 200 < 100) ot_.position_.x += 1.0f;//右に移動させる
	else ot_.position_.x -= 1.0f;//左に移動させる
}

void PlayScene::Draw()
{
	//Transform ot;//おでん用のトランスフォーム
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);

}

void PlayScene::Release()
{
}
