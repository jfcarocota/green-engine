#pragma once
#include "SFML/Graphics.hpp"
#include "Drawable.hh"
#include<fstream>
#include "json/json.h"

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
  Json::Value root{};

public:
  Animation();
  Animation(Drawable*& drawable, const char* animUrl);

  void Play(float& deltaTime);
  ~Animation();
};