#include "Components/AnimatorComponent.hh"
#include "Components/EntityManager.hh"

AnimatorComponent::AnimatorComponent()
{
}

AnimatorComponent::~AnimatorComponent()
{
}

void AnimatorComponent::Initialize()
{
  sprite = owner->GetComponent<SpriteComponent>();
  transform = owner->GetComponent<TransformComponent>();
}

void AnimatorComponent::RefreshAnimationClip()
{
  animationIndex = currentAnimationClip.animationIndex;
  startFrame = currentAnimationClip.startFrame;
  endFrame = currentAnimationClip.endFrame;
  animationDelay = currentAnimationClip.animationDelay;
  currentAnimation = currentAnimationClip.currentAnimation;
}

void AnimatorComponent::Play(std::string animationName)
{
  AnimationClip anim = animations.at(animationName);

  if(animationName != currentAnimationName)
  {
    currentAnimationName = animationName;
    currentAnimationClip = anim;

    RefreshAnimationClip();
  }
}

void AnimatorComponent::AddAnimation(std::string animationName, AnimationClip animationClip)
{
  if(currentAnimationName.empty())
  {
    currentAnimationName = animationName;
    currentAnimationClip = animationClip;

    RefreshAnimationClip();
  }
  animations.insert({animationName, animationClip});
}

void AnimatorComponent::Update(float& deltaTime)
{
  if(&sprite && &transform)
  {
    if(animations.size() > 0 && !currentAnimationName.empty())
    {
      currentTime += deltaTime;
      sprite->RebindRectTexture(animationIndex * transform->GetWidth(),
      currentAnimation * transform->GetHeight(), transform->GetWidth(),
      transform->GetHeight());

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
}