#include "Drawable.hh"

Drawable::Drawable(const char* textureUrl, sf::Vector2f position, float scale, float width, float height, int col, int row)
{
  this->position = position;
  this->scale = scale;
  this->width = width;
  this->height = height;
  this->width = width;
  this->col = col;
  this->row = row;

  texture = new sf::Texture();
  texture->loadFromFile(textureUrl);
  sprite = new sf::Sprite(*texture, sf::IntRect(col * width, row * height, width, height));
  sprite->setPosition(position);
  sprite->setScale(sf::Vector2f(scale, scale));
  sprite->setColor(sf::Color::White);
}

Drawable::~Drawable()
{
  delete sprite;
  delete texture;
}

sf::Sprite* Drawable::GetSprite() const
{
  return sprite;
}
sf::Vector2f Drawable::GetPosition() const
{
  return position;
}
void Drawable::SetPosition(sf::Vector2f position)
{
  this->position = position;
  sprite->setPosition(position);
}
float Drawable::GetScale() const
{
  return scale;
}
void Drawable::SetScale(float scale)
{
  this->scale = scale;
  sprite->setScale(scale, scale);
}
float Drawable::GetWidth() const
{
  return width;
}
void Drawable::SetWidth(float width)
{
  this->width = width;
}
float Drawable::GetHeight() const
{
  return height;
}
void Drawable::SetHeight(float height)
{
  this->height = height;
}

void Drawable::RebindRect()
{
  sprite->setTextureRect(sf::IntRect(col * width, row * height, width, height));
}

void Drawable::RebindRect(int col, int row, float width, float height)
{
  sprite->setTextureRect(sf::IntRect(col, row, width, height));
}