#include "Movement.hh"
#include "InputSystem.hh"
#include "AnimationClip.hh"
#include "Components/EntityManager.hh"

Movement::Movement(float moveSpeed)
{
  this->moveSpeed = moveSpeed;
}

Movement::~Movement()
{
}

void Movement::Initialize()
{
  animator = owner->GetComponent<AnimatorComponent>();
  sprite = owner->GetComponent<SpriteComponent>();
  transform = owner->GetComponent<TransformComponent>();
  rigidbody = owner->GetComponent<RigidBodyComponent>();

  animator->AddAnimation("idle", AnimationClip("assets/animations/player/idle.json"));
  animator->AddAnimation("walk", AnimationClip("assets/animations/player/walk.json"));
}

void Movement::Update(float& deltaTime)
{
  sf::Vector2 direction = InputSystem::Axis() * moveSpeed;

  rigidbody->AddVelocity(b2Vec2(direction.x, direction.y));

  if(std::abs(direction.x) > 0 || std::abs(direction.y) > 0)
  {
    /*if(stepsTimer >= stepsDelay)
    {
      audioSystem->Play("steps");
      stepsTimer = 0.f;
    }*/
    animator->Play("walk");
  }
  else
  {
    animator->Play("idle");
  }
}
