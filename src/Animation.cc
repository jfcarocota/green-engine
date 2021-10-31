#include "Animation.hh"

Animation::Animation(){}

Animation::Animation(Drawable*& drawable, int startFrame, int endFrame, float animationDelay, int currentAnimation)
{
  this->drawable = drawable;
  this->startFrame = startFrame;
  this->endFrame = endFrame;
  this->animationDelay = animationDelay;
  this->currentAnimation = currentAnimation;
  animationIndex = startFrame;
}

void Animation::Play(float& deltaTime)
{
  currentTime += deltaTime;

  drawable->RebindRect(animationIndex * drawable->GetWidth(),
  currentAnimation * drawable->GetHeight(), drawable->GetWidth(), 
  drawable->GetHeight());

  if(currentTime >= animationDelay)
  {
    if(animationIndex == endFrame)
    {
      animationIndex = startFrame;
    }
    else
    {
      animationIndex++;
    }
    currentTime = 0.f;
  }
}

Animation::~Animation()
{
}