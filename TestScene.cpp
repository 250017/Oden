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
	hTitlePic_ = Image::Load("OdenTitle.png");
	assert(hTitlePic_ >= 0);


	transform_.position_ = { 0.0f,0.0f,0.0f };
	transform_.rotate_ = { 0.0f,0.0f,0.0f };
	transform_.scale_ = { 1.5f,1.5f,1.0f };
}

//更新
void TestScene::Update()
{
	printf("Update\n");
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
	Image::SetTransform(hTitlePic_, transform_);//画像の行列をこのオブジェクトの行列にする
	Image::Draw(hTitlePic_);//画像を描画
}
//開放
void TestScene::Release()
{
}
