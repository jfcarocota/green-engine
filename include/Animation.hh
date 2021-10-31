#pragma once
#include "SFML/Graphics.hpp"
#include "Drawable.hh"

class Animation
{
private:
  int animationIndex{};
  int startFrame{};
  int endFrame{};
  float animationDelay{};
  float currentTime{};
  int currentAnimation{};
  Drawable* drawable{};
public:
  Animation();
  Animation(Drawable*& drawable, int startFrame, int endFrame, float animationDelay, int currentAnimation);

  void Play(float& deltaTime);
  ~Animation();
};