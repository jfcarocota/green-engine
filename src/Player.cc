#include "Player.hh"
#include "InputSystem.hh"

Player::Player(const char* textureUrl, float playerScale, float width, float height, int column, int row,
float posX, float posY, float playerSpeed, b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window) :
GameObject(textureUrl, playerScale, width, height, column, row, posX, posY, bodyType, world, window)
{
  this->playerSpeed = playerSpeed;
  stepsDelay = 0.3f;
  rigidbody->FreezeRotation(true);

  animationSystem = new AnimationSystem();
  audioSystem = new AudioSystem();

  //animationSystem->AddAnimation("idle", new Animation(drawable, "assets/animations/player/idle.json"));
  //animationSystem->AddAnimation("walk", new Animation(drawable, "assets/animations/player/walk.json"));

  audioSystem->AddAudioClip("steps", new AudioClip("assets/audio/steps.ogg", 4.f));
}

Player::~Player()
{
}

sf::Sprite* Player::GetSprite() const
{
  return drawable->GetSprite();
}

void Player::Update(float& deltaTime)
{
  //animationSystem->Update(deltaTime);
  GameObject::Update(deltaTime);
  Move();

  if(stepsTimer < stepsDelay)
  {
    stepsTimer += deltaTime;
  }

  if(std::abs(InputSystem::Axis().x) > 0 || std::abs(InputSystem::Axis().y) > 0)
  {
    if(stepsTimer >= stepsDelay)
    {
      audioSystem->Play("steps");
      stepsTimer = 0.f;
    }
    //animationSystem->Play("walk");
  }
  else
  {
    //animationSystem->Play("idle");
  }
}

void Player::Draw()
{
  GameObject::Draw();

}

void Player::Move()
{
  rigidbody->GetBody()->SetLinearVelocity(b2Vec2(InputSystem::Axis().x * playerSpeed,
  InputSystem::Axis().y * playerSpeed));

  FlipSprite();
}
void Player::FlipSprite()
{
  GetSprite()->setScale(InputSystem::Axis().x > 0 ? drawable->GetScale() : InputSystem::Axis().x < 0 ? -drawable->GetScale() :
  GetSprite()->getScale().x,
  drawable->GetScale());
}