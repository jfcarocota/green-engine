#include "Player.hh"
#include "InputSystem.hh"

Player::Player(const char* textureUrl, float playerScale, float width, float height, int column, int row,
float posX, float posY, float playerSpeed, b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window) :
GameObject(textureUrl, playerScale, width, height, column, row, posX, posY, bodyType, world, window)
{
  this->playerSpeed = playerSpeed;
  rigidbody->FreezeRotation(true);

  animationSystem = new AnimationSystem();

  animationSystem->AddAnimation("idle", new Animation(drawable, "assets/animations/player/idle.anim"));
  animationSystem->AddAnimation("walk", new Animation(drawable, "assets/animations/player/walk.anim"));
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
  animationSystem->Update(deltaTime);
  GameObject::Update(deltaTime);
  Move();

  if(std::abs(InputSystem::Axis().x) > 0 || std::abs(InputSystem::Axis().y) > 0)
  {
    animationSystem->Play("walk");
  }
  else
  {
    animationSystem->Play("idle");
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