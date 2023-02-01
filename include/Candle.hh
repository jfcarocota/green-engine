#pragma once
#include "Components/EntityManager.hh"
#include "Components/Component.hh"
#include<box2d/box2d.h>


class Candle : public Component
{
private:
  b2World* world;
public:
  Candle(b2World*& world);
  ~Candle();
  void Initialize() override;
};