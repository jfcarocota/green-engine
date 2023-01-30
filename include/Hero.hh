#pragma once

#include "Components/EntityManager.hh"
#include "Components/Component.hh"

class Hero: public Component
{
private:
  
public:
  Hero();
  ~Hero();
  void Initialize() override;
};