#pragma once
#include "Component.hh"
#include "AnimationClip.hh"
#include<map>
#include<string>
#include "SpriteComponent.hh"
#include "TransformComponent.hh"

class AnimatorComponent : public Component
{
private:
  SpriteComponent* sprite;
  TransformComponent* transform;
  std::string currentAnimationName{};
  std::map<std::string, AnimationClip> animations;
  AnimationClip currentAnimationClip;

  int animationIndex{};
  int startFrame{};
  int endFrame{};
  float animationDelay{};
  int currentAnimation{};
  float currentTime{};

public:
  AnimatorComponent();
  ~AnimatorComponent();


  void Play(std::string animationName);
  void AddAnimation(std::string animationName, AnimationClip animationClip);
  void Initialize() override;
  void Update(float& deltaTime) override;
  void RefreshAnimationClip();
};