#include "Bullet.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Player.h"
#include "Engine\\SphereCollider.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1), speed_(0.5)
{
}

void Bullet::Initialize()
{
	//hModel_ = Model::Load("Bullet.fbx");
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 0.25f, 0.25f, 0.25f };
	//Player* player = (Player*)FindObject("Player");
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 0.5f);
	AddCollider(collider);

}

void Bullet::Update()
{
	transform_.position_.z += speed_;
	if (transform_.position_.z > 50.0f)
	{
		KillMe();//自分を削除する
	}
}

void Bullet::Draw()
{
	if (hModel_ < 0)
	{
		return;
	}

	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
