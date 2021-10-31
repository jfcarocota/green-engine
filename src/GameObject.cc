#include "GameObject.hh"
#include "Game.hh"

class Game;

GameObject::GameObject(const char* textureUrl, float scale, float width, float height, int column, int row, 
float posX, float posY, b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window)
{
  this->world = world;
  this->window = window;
  tagName = "Default";

  drawable = new Drawable(textureUrl, sf::Vector2f(posX, posY), scale, width, height, column, row);

  rigidbody = new Rigidbody(world, bodyType,
  new b2Vec2(drawable->GetPosition().x, drawable->GetPosition().y),
  width * scale, height * scale, 1, 0, 0, new b2Vec2(drawable->GetSprite()->getOrigin().x, drawable->GetSprite()->getOrigin().y),
  0.f, (void*) this);

  drawable->GetSprite()->setOrigin(width / 2, height / 2);

  //Game::AddGameObject(this);
}

GameObject::~GameObject()
{
  delete rigidbody;
  delete drawable;
}

void GameObject::Start()
{

}

void GameObject::Update(float& deltaTime)
{
  drawable->SetPosition(rigidbody->GetPositionSFML());
}

void GameObject::Draw()
{
  window->draw(*drawable->GetSprite());
}

void GameObject::Input()
{

}

sf::Sprite* GameObject::GetSprite() const
{
  return drawable->GetSprite();
}

std::string GameObject::GetTagName() const
{
  return tagName;
}

void GameObject::SetTagName(std::string tagName)
{
  this->tagName = tagName;
}