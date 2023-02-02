#include "Components/RigidBodyComponent.hh"
#include "Components/EntityManager.hh"

RigidBodyComponent::RigidBodyComponent(b2World*& world, b2BodyType bodyType, float density, float friction,
float restitution, float angle, bool frezeRotation, void* userData)
{
  this->world = world;

  bodyDef = new b2BodyDef();
  bodyDef->type = bodyType;
  polygonShape = new b2PolygonShape();
  fixtureDef = new b2FixtureDef();

  this->density = density;
  this->friction = friction;
  this->restitution = restitution;
  this->angle = angle;
  this->frezeRotation = frezeRotation;
  this->userData = userData;
}

void RigidBodyComponent::Initialize()
{
  transform = owner->GetComponent<TransformComponent>();
  spriteComponent = owner->GetComponent<SpriteComponent>();

  sf::Vector2f spritePos{transform->GetPosition().x, transform->GetPosition().y};
  sf::Vector2f size{transform->GetWidth() * transform->GetScale(), transform->GetHeight() * transform->GetScale()};

  //init body
  bodyDef->position = b2Vec2(spritePos.x, spritePos.y);
  body = world->CreateBody(bodyDef);

  //define polygon shape
  polygonShape->SetAsBox(size.x * 0.5f - b2_polygonRadius, size.y * 0.5f - b2_polygonRadius);

  //init fixture
  fixtureDef->shape = polygonShape;
  fixtureDef->density = density;
  fixtureDef->friction = friction;
  fixtureDef->restitution = restitution;
  fixture = body->CreateFixture(fixtureDef);
  body->SetFixedRotation(frezeRotation);

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
  if(&spriteComponent && &transform)
  {
    bodyPos = body->GetPosition();
    trsPos = sf::Vector2f(bodyPos.x, bodyPos.y);
    transform->SetPosition(trsPos);
  }
}