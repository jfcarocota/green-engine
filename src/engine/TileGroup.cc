#include "TileGroup.hh"
#include<iostream>

TileGroup::TileGroup(sf::RenderWindow*& window, int COLS, int ROWS, const char* filePath, 
float scale, float tileWidth, float tileHeight, const char* textureUrl)
{
  this->textureUrl = textureUrl;
  this->tileWidth = tileWidth;
  this->tileHeight = tileHeight;
  this->scale = scale;
  this->COLS = COLS;
  this->ROWS = ROWS;
  this->filePath = filePath;
  reader = new std::ifstream();
  this->window = window;
  tiles = new std::vector<Tile*>();

  GenerateMap();
}

TileGroup::~TileGroup()
{

}

void TileGroup::GenerateMap()
{
  reader->open(filePath);
  for(int y{}; y < ROWS; y++)
  {
    for(int x{}; x < COLS; x++)
    {
      float posX{scale * tileWidth * x};
      float posY{scale * tileHeight * y};

      int coord{};
      *reader >> coord;
      int col{coord};
      *reader >> coord;
      int row{coord};

      tiles->push_back(new Tile(textureUrl, scale, tileWidth, tileHeight, col, row, posX, posY, window));
    }
  }
  reader->close();
}

void TileGroup::Draw()
{
  for(auto& tile : *tiles)
  {
    tile->Draw();
  }
}