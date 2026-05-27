#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"

Clear::Clear(GameObject* parent)
:GameObject(parent, "ClearScene"), hClearPic_(-1)
{
}

void Clear::Initialize()
{
	hClearPic_ = Image::Load("clear.png");
	assert(hClearPic_ >= 0);
	timer = 0;
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
}

void Clear::Release()
{
}
