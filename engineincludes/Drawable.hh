#pragma once
#include<SFML/Graphics.hpp>

class Drawable
{
protected:
  sf::Sprite* sprite{};
  sf::Vector2f position{};
  float scale{};
  float width{};
  float height{};
  int col{}, row{};
  sf::Texture* texture;
public:
  Drawable(const char* textureUrl, sf::Vector2f position, float scale, float width, float height, int col, int row);
  ~Drawable();

  sf::Sprite* GetSprite() const;
  sf::Vector2f GetPosition() const;
  void SetPosition(sf::Vector2f position);
  float GetScale() const;
  float GetWidth() const;
  float GetHeight() const;
  void SetScale(float scale);
  void SetWidth(float width);
  void SetHeight(float height);
  void RebindRect();
  void RebindRect(int col, int row, float width, float height);
};