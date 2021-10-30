#pragma once
#include "SFML/Graphics.hpp"

class Animation
{
private:
  sf::Sprite* sprite;
  int animationIndex{};
  int startFrame{};
  int endFrame{};
  float animationDelay{};
  float currentTime{};
  int currentAnimation{};
public:
  Animation();
  Animation(sf::Sprite* sprite, int startFrame, int endFrame, float animationDelay, int currentAnimation);

  void Play(float& deltaTime);
  ~Animation();
};