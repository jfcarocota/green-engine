#pragma once
#include "Component.hh"
#include "Animation.hh"
#include<map>
#include<string>

class AnimatorComponent : public Component
{
private:
  std::string currentAnimation{};
  std::map<std::string, Animation*>* animations;
public:
  AnimatorComponent();
  ~AnimatorComponent();

  Animation* GetAnimation(std::string animation);

  void Play(std::string animationName);
  void AddAnimation(std::string animationName, Animation* animation);
  void Update(float& deltaTime) override;
};