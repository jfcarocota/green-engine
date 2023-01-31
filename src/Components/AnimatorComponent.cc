#include "Components/AnimatorComponent.hh"

AnimatorComponent::AnimatorComponent()
{
  this->currentAnimation = currentAnimation;
}

AnimatorComponent::~AnimatorComponent()
{
}

Animation* AnimatorComponent::GetAnimation(std::string animation)
{
  return animations->at(animation);
}

void AnimatorComponent::Play(std::string animationName)
{
  currentAnimation = animationName;
}

void AnimatorComponent::AddAnimation(std::string animationName, Animation* animation)
{
  animations->insert({animationName, animation});
}

void AnimatorComponent::Update(float& deltaTime)
{
  if(animations->size() > 0)
  {
    GetAnimation(currentAnimation)->Play(deltaTime);
  }
}