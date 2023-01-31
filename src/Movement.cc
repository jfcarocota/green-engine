#include "Movement.hh"
#include "InputSystem.hh"
#include "Animation.hh"

Movement::Movement(float moveSpeed, RigidBodyComponent& rigidbody, AnimatorComponent& animator):
rigidbody(rigidbody), animator(animator)
{
  this->moveSpeed = moveSpeed;
}

Movement::~Movement()
{
}

void Movement::Initialize()
{
  //animator.AddAnimation("idle", new Animation());
}

void Movement::Update(float& deltaTime)
{
  sf::Vector2 direction = InputSystem::Axis() * moveSpeed;

  rigidbody.AddVelocity(b2Vec2(direction.x, direction.y));
}
