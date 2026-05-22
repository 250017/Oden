#include "ClearScene.h"
#include "Engine/Image.h"

Clear::Clear(GameObject* parent)
:GameObject(parent, "ClearScene"), hClearPic_(-1)
{
}

void Clear::Initialize()
{
	hClearPic_ = Image::Load("clear.png");
	assert(hClearPic_ >= 0);
}

void Clear::Update()
{
}

void Clear::Draw()
{
	Image::SetTransform(hClearPic_, transform_);
	Image::Draw(hClearPic_);
}

void Clear::Release()
{
}
