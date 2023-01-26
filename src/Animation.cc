#include "Animation.hh"
#include<iostream>

Animation::Animation(){}

Animation::Animation(Drawable*& drawable, const char* animUrl)
{
  reader = new std::ifstream();
  reader->open(animUrl);
  root = Json::Value();

  this->drawable = drawable;
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