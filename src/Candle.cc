#include "Candle.hh"

Candle::Candle(const char* textureUrl, float scale, float width, float height, int column, int row, float posX, float posY,
b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window) :
GameObject(textureUrl, scale, width, height, column, row, posX, posY, bodyType, world, window)
{
  animationSystem = new AnimationSystem();
  //animationSystem->AddAnimation("idle", new Animation(drawable, "assets/animations/candle/idle.anim"));
  //animationSystem->AddAnimation("idle", new Animation(drawable, "assets/animations/candle/idle.json"));
}

Candle::~Candle()
{
}

void Candle::Update(float& deltaTime)
{
  //animationSystem->Update(deltaTime);
  GameObject::Update(deltaTime);

  //animationSystem->Play("idle");
}

void Candle::Draw()
{
  GameObject::Draw();
}