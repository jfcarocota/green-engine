#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
#include "Rigidbody.hh"
#include "GameObject.hh"
#include "Animation.hh"
#include "AnimationSystem.hh"
#include "AudioSystem.hh"

class Player : public GameObject
{
private:
  float playerSpeed{};
  float stepsDelay{};
  float stepsTimer{};

  void FlipSprite();
  AnimationSystem* animationSystem{};
  AudioSystem* audioSystem{};
public:
  Player(const char* textureUrl, float playerScale, float width, float height, int column, int row, float posX, float posY, float playerSpeed, 
  b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window);
  ~Player();
  sf::Sprite* GetSprite() const;
  void Move();

  void Update(float& deltaTime) override;
  void Draw() override;
};