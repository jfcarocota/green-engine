#include "AnimationSystem.hh"

AnimationSystem::AnimationSystem()
{
  animations = new std::map<std::string, Animation*>();
}

AnimationSystem::~AnimationSystem()
{
}

Animation* AnimationSystem::GetAnimation(std::string animationName)
{
  return animations->at(animationName);
}

void AnimationSystem::Play(std::string animationName)
{
  GetAnimation(animationName)->Play(deltaTime);
}

void AnimationSystem::AddAnimation(std::string animationName, Animation* animation)
{
  animations->insert({animationName, animation});
}

void AnimationSystem::Update(float& deltaTime)
{
  this->deltaTime = deltaTime;
}