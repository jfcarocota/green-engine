#include "Tile.hh"

Tile::Tile(std::string textureUrl, float scale, int width, int height, int column, int row,
float posX, float posY, sf::RenderWindow*& window)
{
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
}

Tile::~Tile()
{

}

void Tile::Draw()
{
  window->draw(*sprite);
}