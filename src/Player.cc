#include "Player.hh"
#include "InputSystem.hh"

Player::Player(const char* textureUrl, float playerScale, float width, float height, int column, int row,
float posX, float posY, float playerSpeed, b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window) :
GameObject(textureUrl, playerScale, width, height, column, row, posX, posY, bodyType, world, window)
{
  this->playerSpeed = playerSpeed;
  rigidbody->FreezeRotation(true);
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
  GameObject::Update(deltaTime);
  Move();
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
  drawable->GetSprite()->setScale(InputSystem::Axis().x > 0 ? drawable->GetScale() : InputSystem::Axis().x < 0 ? -drawable->GetScale() :
  drawable->GetSprite()->getScale().x,
  drawable->GetScale());
}