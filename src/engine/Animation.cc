#include "Animation.hh"

Animation::Animation(){}

Animation::Animation(GameObject*& gameObject, const char* animUrl)
{
  reader = new std::ifstream();
  reader->open(animUrl);

  this->gameObject = gameObject;
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

  gameObject->GetDrawable()->RebindRect(animationIndex * gameObject->GetDrawable()->GetWidth(),
  currentAnimation * gameObject->GetDrawable()->GetHeight(), gameObject->GetDrawable()->GetWidth(),
  gameObject->GetDrawable()->GetHeight());

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