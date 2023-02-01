#include "Components/AnimatorComponent.hh"

AnimatorComponent::AnimatorComponent(SpriteComponent& sprite, TransformComponent& transform):
sprite(sprite), transform(transform)
{
}

AnimatorComponent::~AnimatorComponent()
{
}

void AnimatorComponent::Play(std::string animationName)
{
  AnimationClip anim = animations.at(animationName);

  if(animationName != currentAnimationName)
  {
    currentAnimationName = animationName;
    currentAnimationClip = currentAnimationClip;

    animationIndex = currentAnimationClip.animationIndex;
    startFrame = currentAnimationClip.startFrame;
    endFrame = currentAnimationClip.endFrame;
    animationDelay = currentAnimationClip.animationDelay;
    currentAnimation = currentAnimationClip.currentAnimation;
  }
}

void AnimatorComponent::AddAnimation(std::string animationName, AnimationClip animationClip)
{
  if(currentAnimationName.empty())
  {
    currentAnimationName = animationName;
    currentAnimationClip = animationClip;

    animationIndex = currentAnimationClip.animationIndex;
    startFrame = currentAnimationClip.startFrame;
    endFrame = currentAnimationClip.endFrame;
    animationDelay = currentAnimationClip.animationDelay;
    currentAnimation = currentAnimationClip.currentAnimation;
  }
  animations.insert({animationName, animationClip});
}

void AnimatorComponent::Update(float& deltaTime)
{
  if(animations.size() > 0 && !currentAnimationName.empty())
  {
    currentTime += deltaTime;
    sprite.RebindRectTexture(animationIndex * transform.GetWidth(),
    currentAnimation * transform.GetHeight(), transform.GetWidth(),
    transform.GetHeight());

    if(currentTime > animationDelay)
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
}