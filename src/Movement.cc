#include "Movement.hh"
#include "InputSystem.hh"

Movement::Movement(float moveSpeed, RigidBodyComponent& rigidbody): rigidbody(rigidbody)
{
  this->moveSpeed = moveSpeed;
}

Movement::~Movement()
{
}

void Movement::Initialize()
{

}

void Movement::Update(float& deltaTime)
{
  sf::Vector2 direction = InputSystem::Axis() * moveSpeed;

  rigidbody.AddVelocity(b2Vec2(direction.x, direction.y));
  //transform.Translate(InputSystem::Axis() * moveSpeed * deltaTime);
  //rigidbody->GetBody()->SetLinearVelocity(b2Vec2(InputSystem::Axis().x * playerSpeed, InputSystem::Axis().y * playerSpeed));
}
