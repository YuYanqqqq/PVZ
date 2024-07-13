#include "Animation.h"

Animation* Animation::Create()
{
	Animation* NewAnimation = new Animation;
	NewAnimation->Init();
	if (NewAnimation && NewAnimation->Init())
		return NewAnimation;

	if (NewAnimation)
		delete NewAnimation;
	return nullptr;
}

bool Animation::Init()
{
    return true;
}

void Animation::Addimage(const char* Filename)
{
	IMAGE* NewImage = new IMAGE;
	loadimage(NewImage,Filename);
	m_AnimationImageVector.push_back(NewImage);
}
