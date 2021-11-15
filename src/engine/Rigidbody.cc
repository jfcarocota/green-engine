#include "Rigidbody.hh"

Rigidbody::Rigidbody(b2World*& world, b2BodyType bodyType, b2Vec2* position,
float width, float height, float density, float friction, float restitution,
b2Vec2* origin, float angle, void* userData)
{

  this->world = world;

  //init body
  bodyDef = new b2BodyDef();
  bodyDef->type = bodyType;
  bodyDef->position = *position;
  body = world->CreateBody(bodyDef);

  //define polygon shape
  polygonShape = new b2PolygonShape();
  polygonShape->SetAsBox(width / 2, height / 2, *origin, angle);

  //init fixture
  fixtureDef = new b2FixtureDef();
  fixtureDef->shape = polygonShape;
  fixtureDef->density = density;
  fixtureDef->friction = friction;
  fixtureDef->restitution = restitution;
  fixture = body->CreateFixture(fixtureDef);

  body->GetUserData().pointer = reinterpret_cast<uintptr_t>(userData);
}

Rigidbody::~Rigidbody()
{
  world->DestroyBody(body);
}

b2Body* Rigidbody::GetBody() const
{
  return body;
}

void Rigidbody::FreezeRotation(bool freeze)
{
  body->SetFixedRotation(freeze);
}

b2Vec2 Rigidbody::GetPosition() const
{
  return body->GetPosition();
}

sf::Vector2f Rigidbody::GetPositionSFML() const
{
  return sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
}
