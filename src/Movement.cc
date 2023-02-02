#include "Movement.hh"
#include "InputSystem.hh"
#include "AnimationClip.hh"
#include "Components/EntityManager.hh"

Movement::Movement(float moveSpeed, float stepsDelay, AudioClip stepsAudio)
{
  this->moveSpeed = moveSpeed;
  this->stepsDelay = stepsDelay;
  this->stepsAudio = stepsAudio;
  stepsTimer = stepsDelay;
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
  audioListener = owner->GetComponent<AudioListenerComponent>();

  animator->AddAnimation("idle", AnimationClip("assets/animations/player/idle.json"));
  animator->AddAnimation("walk", AnimationClip("assets/animations/player/walk.json"));
}

void Movement::Update(float& deltaTime)
{
  sf::Vector2 direction = InputSystem::Axis() * moveSpeed;

  rigidbody->AddVelocity(b2Vec2(direction.x, direction.y));

  if(std::abs(direction.x) > 0 || std::abs(direction.y) > 0)
  {
    if(audioListener)
    {
      stepsTimer += deltaTime;
      if(stepsTimer >= stepsDelay)
      {
        audioListener->PlayOneShot(stepsAudio, 4.f);
        stepsTimer = 0.f;
      }
    }
    animator->Play("walk");
  }
  else
  {
    animator->Play("idle");
  }
}
