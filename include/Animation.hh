#pragma once
#include "SFML/Graphics.hpp"
#include "Components/SpriteComponent.hh"
#include "Components/TransformComponent.hh"
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
  SpriteComponent& sprite;
  TransformComponent& transform;
  std::ifstream* reader{};
  Json::Value root{};

public:
  Animation();
  Animation(SpriteComponent& sprite, TransformComponent& transform, const char* animUrl);

  void Play(float& deltaTime);
  ~Animation();
};