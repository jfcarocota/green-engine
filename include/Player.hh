#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
#include "Rigidbody.hh"
#include "GameObject.hh"

class Player : public GameObject
{
private:
  float playerSpeed{};

  void FlipSprite();
public:
  Player(std::string textureUrl, float playerScale, int width, int height, int column, int row, float posX, float posY, float playerSpeed, 
  b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window);
  ~Player();
  sf::Sprite* GetSprite() const;
  void Move();

  void Update(float& deltaTime) override;
  void Draw() override;
};