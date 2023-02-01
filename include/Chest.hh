#pragma once
#include "Components/Component.hh"
#include "Components/EntityManager.hh"
#include<box2d/box2d.h>

class Chest: public Component
{
private:
  b2World*& world;
public:
  Chest(b2World*& world);
  ~Chest();
  void Initialize() override;
};
