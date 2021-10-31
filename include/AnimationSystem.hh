#pragma once
#include "Animation.hh"
#include<map>
#include<string>

class AnimationSystem
{
private:
  std::map<std::string, Animation*>* animations;
  float deltaTime{};
public:
  AnimationSystem();
  ~AnimationSystem();
  Animation* GetAnimation(std::string animation);

  void Play(std::string animationName);
  void AddAnimation(std::string animationName, Animation* animation);
  void Update(float& deltaTime);
};