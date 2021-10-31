#pragma once
#include "SFML/Graphics.hpp"
#include "Drawable.hh"
#include<fstream>

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
  std::ifstream* reader{};
public:
  Animation();
  Animation(Drawable*& drawable, const char* animUrl);

  void Play(float& deltaTime);
  ~Animation();
};