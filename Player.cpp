#include "Player.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Bullet.h"
#include "Egg.h"


Player::Player(GameObject* parent)
//親のポインタ、オブジェクトの名前
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	//hModel_ = Model::Load("Player.fbx");
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = { 0.0f,0.0f,0.0f };
	transform_.scale_ = { 1.0f, 1.0f, 1.0f };
	transform_.rotate_ = { 0.0f,180.0f,0.0f };

	// プレイヤー用の球形コライダーを生成する
	SphereCollider* collider =
		new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);

	// プレイヤーにコライダーを追加する
	AddCollider(collider);
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		//左に移動
		transform_.position_.x += -0.2f;
	}
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
		//右に移動
		transform_.position_.x += 0.2f;
	}
	if (Input::IsKey(DIK_UP) || Input::IsKey(DIK_W))
	{
		//上に移動
		transform_.position_.y += 0.2f;
	}
	if (Input::IsKey(DIK_DOWN) || Input::IsKey(DIK_S))
	{
		//下に移動
		transform_.position_.y += -0.2f;
	}

	if (Input::IsKeyDown(DIK_SPACE))
	{
		Bullet *pBullet = Instantiate<Bullet>(this->GetParent());
		pBullet->SetPosition(transform_.position_);
	}
	// 画面外に出ないように制限
	if (transform_.position_.x > 15) {
		transform_.position_.x = 15;
	}
	if (transform_.position_.x < -15) {
		transform_.position_.x = -15;
	}
	if (transform_.position_.y > 8) {
		transform_.position_.y = 8;
	}
	if (transform_.position_.y < -8) {
		transform_.position_.y = -8;
	}
}

void Player::Draw()
{
	if (hModel_ < 0)
	{
		return;
	}

	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Egg")
	{
		pTarget->KillMe();
		KillMe();
	}
}
