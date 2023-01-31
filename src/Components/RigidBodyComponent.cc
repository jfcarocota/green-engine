#include "Components/RigidBodyComponent.hh"

RigidBodyComponent::RigidBodyComponent(b2World*& world, b2BodyType bodyType, float density, float friction,
float restitution, float angle, void* userData,  TransformComponent& transform, SpriteComponent& spriteComponent):
transform(transform), spriteComponent(spriteComponent)
{
  this->world = world;

  sf::Vector2f spritePos{transform.GetPosition().x, transform.GetPosition().y};
  sf::Vector2f size{transform.GetWidth() * transform.GetScale(), transform.GetHeight() * transform.GetScale()};

  //init body
  bodyDef = new b2BodyDef();
  bodyDef->type = bodyType;
  bodyDef->position = b2Vec2(spritePos.x, spritePos.y);
  body = world->CreateBody(bodyDef);

  //define polygon shape
  polygonShape = new b2PolygonShape();
  polygonShape->SetAsBox(size.x * 0.5f - b2_polygonRadius, size.y * 0.5f - b2_polygonRadius);

  //init fixture
  fixtureDef = new b2FixtureDef();
  fixtureDef->shape = polygonShape;
  fixtureDef->density = density;
  fixtureDef->friction = friction;
  fixtureDef->restitution = restitution;
  fixture = body->CreateFixture(fixtureDef);

  body->GetUserData().pointer = reinterpret_cast<uintptr_t>(userData);
}

RigidBodyComponent::~RigidBodyComponent()
{
  world->DestroyBody(body);
}

b2Body* RigidBodyComponent::GetBody() const
{
  return body;
}

void RigidBodyComponent::FreezeRotation(bool freeze)
{
  body->SetFixedRotation(freeze);
}

b2Vec2 RigidBodyComponent::GetPosition() const
{
  return body->GetPosition();
}

sf::Vector2f RigidBodyComponent::GetPositionSFML() const
{
  return sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
}

void RigidBodyComponent::AddVelocity(b2Vec2 velocity)
{
  body->SetLinearVelocity(velocity);
}

void RigidBodyComponent::Update(float& deltaTime)
{
  bodyPos = body->GetPosition();
  trsPos = sf::Vector2f(bodyPos.x, bodyPos.y);
  transform.SetPosition(trsPos);
}