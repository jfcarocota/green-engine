#include "GameObject.hh"
#include "Game.hh"

class Game;

GameObject::GameObject(std::string textureUrl, float scale, int width, int height, int column, int row, 
float posX, float posY, b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window)
{
  this->world = world;
  this->window = window;
  this->scale = scale;
  this->width = width;
  this->height = height;
  this->column = column;
  this->row = row;
  this->posX = posX;
  this->posY = posY;

  texture = new sf::Texture();
  texture->loadFromFile(textureUrl);
  sprite = new sf::Sprite(*texture, sf::IntRect(column * width, row * height, width, height));
  sprite->setPosition(posX, posY);
  sprite->setColor(sf::Color::White);
  sprite->setScale(scale, scale);

  rigidbody = new Rigidbody(world, bodyType,
  new b2Vec2(sprite->getPosition().x, sprite->getPosition().y),
  width * scale, height * scale, 1, 0, 0, new b2Vec2(sprite->getOrigin().x, sprite->getOrigin().y),
  0.f, (void*) this);

  sprite->setOrigin(width / 2, height / 2);

  //Game::AddGameObject(this);
}

GameObject::~GameObject()
{
  delete rigidbody;
  delete sprite;
  delete texture;
}

void GameObject::Start()
{

}

void GameObject::Update(float& deltaTime)
{
  sprite->setPosition(rigidbody->GetPositionSFML());
}

void GameObject::Draw()
{
  window->draw(*sprite);
}

void GameObject::Input()
{

}

sf::Sprite* GameObject::GetSprite() const
{
  return sprite;
}

std::string GameObject::GetTagName() const
{
  return tagName;
}

void GameObject::SetTagName(std::string tagName)
{
  this->tagName = tagName;
}