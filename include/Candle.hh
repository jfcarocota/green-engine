#pragma once
#include "GameObject.hh"
#include "AnimationSystem.hh"

class Candle : public GameObject
{
private:
  AnimationSystem* animationSystem{};
public:
  Candle(const char* textureUrl, float scale, float width, float height, int column, int row, float posX, float posY,
  b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window);
  ~Candle();

  void Update(float& deltaTime) override;
  void Draw() override;
};