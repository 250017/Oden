#include "Egg.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Engine\\SphereCollider.h"
#include <cmath>

// Eggを生成
Egg::Egg(GameObject* parent)
	: GameObject(parent, "Egg"),
	hModel_(-1)
{}

// Eggの初期化
void Egg::Initialize()
{
	// Eggの3Dモデルを読み込む
	hModel_ = Model::Load("Egg.fbx");

	// モデルの読み込みに成功したか確認する
	assert(hModel_ >= 0);

	// プレイヤーより奥側の位置から開始する
	transform_.position_ = { 0.0f, 0.0f, 400.0f };

	// モデルの大きさを設定する
	transform_.scale_ = { 0.5f, 0.5f, 0.5f };

	// モデルの回転角度を設定する
	transform_.rotate_ = { 0.0f, 0.0f, 0.0f };

	// Egg用の球形コライダーを生成する
	SphereCollider* collider =
		new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);

	// Eggにコライダーを追加する
	AddCollider(collider);
}

// Eggを毎フレーム更新
void Egg::Update()
{
	// 左右移動に使用する時間を進める
	time += 0.025f;

	// Sin波を使ってEggを左右に動かす
	//transform_.position_.x = 6.0f * sin(time);

	// Eggを奥から手前方向へ移動させる
	transform_.position_.z -= 0.45f;

	// プレイヤーより後ろまで移動したか判定する
	if (transform_.position_.z < -20.0f)
	{
		// Eggを削除する
		KillMe();

		// 削除後は残りの更新処理を行わない
		return;
	}
}

// Eggを描画
void Egg::Draw()
{
	// モデルが読み込まれていない場合は描画しない
	if (hModel_ < 0)
	{
		return;
	}

	// Eggの座標・回転・大きさをモデルに反映する
	Model::SetTransform(hModel_, transform_);

	// Eggのモデルを描画する
	Model::Draw(hModel_);
}

// Eggを解放
void Egg::Release()
{}

// Eggがほかのオブジェクトと衝突したときの処理
void Egg::OnCollision(GameObject* pTarget)
{
	// 衝突した相手がBulletか判定する
	if (pTarget->GetObjectName() == "Bullet")
	{
		// 衝突したBulletを削除する
		pTarget->KillMe();

		// Egg自身を削除する
		KillMe();
	}
}