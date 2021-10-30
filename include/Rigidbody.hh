#pragma once
#include<box2d/box2d.h>
#include<SFML/Graphics.hpp>

class Rigidbody
{
private:
  b2BodyDef* bodyDef{};
  b2Body* body{};
  b2PolygonShape* polygonShape{};
  b2FixtureDef* fixtureDef{};
  b2Fixture* fixture;
  b2World* world;
public:
  Rigidbody(b2World*& world, b2BodyType bodyType, b2Vec2* position, 
  float width, float height, float density, float friction, float restitution, 
  b2Vec2* origin, float angle, void* userData);
  ~Rigidbody();

  b2Body* GetBody() const;
  void FreezeRotation(bool freeze);
  sf::Vector2f GetPositionSFML() const;
  b2Vec2 GetPosition() const;
};