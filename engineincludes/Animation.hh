#pragma once
#include "SFML/Graphics.hpp"
#include "Drawable.hh"
#include<fstream>
#include "GameObject.hh"

class Animation
{
private:
  int animationIndex{};
  int startFrame{};
  int endFrame{};
  float animationDelay{};
  float currentTime{};
  int currentAnimation{};
  std::ifstream* reader{};
  GameObject* gameObject{};
public:
  Animation();
  Animation(GameObject*& gameObject, const char* animUrl);

  void Play(float& deltaTime);
  ~Animation();
};