#pragma once

#include<SFML/Graphics.hpp>
#include "ContactEventManager.hh"
#include "DrawPhysics.hh"
#include<box2d/box2d.h>
#include<queue>

class Game
{
private:
  sf::RenderWindow* window{};
  sf::Event* event{};
  ContactEventManager* contactEventManager{};
  b2Vec2* gravity{};
  b2World* world{};
  b2Draw* drawPhysics{};
  bool debugPhysics{};

  void Update();
  void Render();
  void MainLoop();
  void Destroy();
  void UpdatePhysics();

public:
  Game();
  ~Game();
  void Initialize();

};
