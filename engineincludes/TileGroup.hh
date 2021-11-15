#pragma once
#include "Tile.hh"
#include<fstream>

class TileGroup
{
private:
  sf::RenderWindow* window;
  std::vector<Tile*>* tiles;
  int COLS{}, ROWS{};
  std::ifstream* reader{};
  const char* filePath{};
  float scale;
  float tileWidth{}, tileHeight{};
  const char* textureUrl{};
public:
  TileGroup(sf::RenderWindow*& window, int COLS, int ROWS, const char* filePath, 
  float scale, float tileWidth, float tileHeight, const char* textureUrl);
  ~TileGroup();

  void GenerateMap();
  void Draw();
};