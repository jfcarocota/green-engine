#pragma once
#include "Components/Component.hh"
#include "Components/RigidBodyComponent.hh"
#include "Components/AnimatorComponent.hh"
#include "Components/TransformComponent.hh"
#include "Components/SpriteComponent.hh"
#include "Components/AudioListenerComponent.hh"
#include "AudioClip.hh"

class Movement: public Component
{
private:
  float moveSpeed;
  RigidBodyComponent* rigidbody;
  AnimatorComponent* animator;
  TransformComponent* transform;
  SpriteComponent* sprite;
  AudioListenerComponent* audioListener;

  AudioClip stepsAudio;

  float stepsTimer{};
  float stepsDelay{};
public:
  Movement(float moveSpeed, float stepsDelay, AudioClip stepsAudio);
  ~Movement();
  void Initialize() override;
  void Update(float& deltaTime) override;
};