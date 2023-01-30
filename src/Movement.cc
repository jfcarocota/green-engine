#include "Movement.hh"
#include "InputSystem.hh"

Movement::Movement(float moveSpeed, TransformComponent& transform): transform(transform)
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
  transform.Translate(InputSystem::Axis() * moveSpeed * deltaTime);
}
