#pragma once

#include<SFML/Graphics.hpp>

class Tile
{
private:
  float scale{};
  int width{};
  int height{};
  int column{};
  int row{};
  float posX{};
  float posY{};
  sf::Sprite* sprite;
  sf::Texture* texture;
  sf::RenderWindow* window;
public:
  Tile(std::string textureUrl, float scale, int width, int height, int column, int row, 
  float posX, float posY, sf::RenderWindow*& window);
  ~Tile();

  void Draw();
};