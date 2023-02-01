#include "Animation.hh"
#include<iostream>

Animation::Animation(SpriteComponent& sprite, TransformComponent& transform, const char* animUrl):
sprite(sprite), transform(transform)
{
  reader = new std::ifstream();
  reader->open(animUrl);
  root = Json::Value();

  *reader >> root;
  startFrame = root["animation"]["startFrame"].asInt();
  endFrame = root["animation"]["endFrame"].asInt();
  animationDelay = root["animation"]["delay"].asFloat();
  currentAnimation = root["animation"]["row"].asInt();
  animationIndex = startFrame;

  reader->close();
}

void Animation::Play(float& deltaTime)
{
  currentTime += deltaTime;
  sprite.RebindRectTexture(animationIndex * transform.GetWidth(),
  currentAnimation * transform.GetHeight(), transform.GetWidth(),
  transform.GetHeight());

  if(currentTime > animationDelay)
  {
    std::cout << "index: " << animationIndex;
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