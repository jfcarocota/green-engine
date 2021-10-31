#include "Animation.hh"

Animation::Animation(){}

Animation::Animation(Drawable*& drawable, const char* animUrl)
{
  reader = new std::ifstream();
  reader->open(animUrl);

  this->drawable = drawable;
  *reader >> startFrame;
  *reader >> endFrame;
  *reader >> animationDelay;
  *reader >> currentAnimation;
  animationIndex = startFrame;

  reader->close();
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