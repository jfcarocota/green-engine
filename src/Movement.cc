#include "Movement.hh"
#include "InputSystem.hh"
#include "AnimationClip.hh"

Movement::Movement(float moveSpeed, RigidBodyComponent& rigidbody,
  AnimatorComponent& animator, TransformComponent& transform,
  SpriteComponent& sprite):
rigidbody(rigidbody), animator(animator), transform(transform), sprite(sprite)
{
  this->moveSpeed = moveSpeed;
}

Movement::~Movement()
{
}

void Movement::Initialize()
{
  animator.AddAnimation("idle", AnimationClip("assets/animations/player/idle.json"));
  animator.AddAnimation("walk", AnimationClip("assets/animations/player/walk.json"));
}

void Movement::Update(float& deltaTime)
{
  sf::Vector2 direction = InputSystem::Axis() * moveSpeed;

  rigidbody.AddVelocity(b2Vec2(direction.x, direction.y));

  if(std::abs(direction.x) > 0 || std::abs(direction.y) > 0)
  {
    /*if(stepsTimer >= stepsDelay)
    {
      audioSystem->Play("steps");
      stepsTimer = 0.f;
    }*/
    animator.Play("walk");
  }
  else
  {
    animator.Play("idle");
  }
}
