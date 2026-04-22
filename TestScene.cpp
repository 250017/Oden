#include "TestScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"), hTitlePic_(-1)
{
}

//初期化
void TestScene::Initialize()
{
	hTitlePic_ = Image::Load("title2.png");
	assert(hTitlePic_ >= 0);
}

//更新
void TestScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		//見つからない場合はnullptrを返すので、nullptrでないことを確認してから使う
		//SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TestScene::Draw()
{
	transform_.position_ = { 400.0f, 300.0f, 0.0f };//画像の位置を変更
	transform_.rotate_ = { 0.0f, 0.0f, 0.0f };//画像の向きを変更

	transform_.scale_ = { 1.5f, 1.5f, 1.0f };//画像の大きさを変更
	Image::SetTransform(hTitlePic_, transform_);//画像の行列をこのオブジェクトの行列にする
	Image::Draw(hTitlePic_);//画像を描画
}

//開放
void TestScene::Release()
{
}
