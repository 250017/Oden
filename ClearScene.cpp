#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "PlayScene.h"
#include "Engine/Text.h"

namespace
{
	Text* resultText_;
}

Clear::Clear(GameObject* parent)
:GameObject(parent, "ClearScene"), hClearPic_(-1)
{
}

void Clear::Initialize()
{
	hClearPic_ = Image::Load("OdenResult.png");
	assert(hClearPic_ >= 0);
	timer = 0;

	transform_.position_ = { 0.0f,0.0f,0.0f };
	transform_.rotate_ = { 0.0f,0.0f,0.0f };
	transform_.scale_ = { 1.5f,1.5f,1.0f };
	score_ = PlayScene::GetScore();

	// テキスト初期化
	resultText_ = new Text();
	resultText_->Initialize();
}

void Clear::Update()
{
	timer++;
	if (timer / 60 > 3) {
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}

}

void Clear::Draw()
{
	Image::SetTransform(hClearPic_, transform_);
	Image::Draw(hClearPic_);

	resultText_->Draw(550.0f, 350.0f, score_);
}

void Clear::Release()
{
	delete resultText_;
}
