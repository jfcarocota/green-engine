#include "Rectangle.hh"

Rectangle::Rectangle(int w, int h, int x, int y, sf::Color color)
{
  rectangleShape = new sf::RectangleShape(sf::Vector2f(w, h));
  rectangleShape->setPosition(sf::Vector2f(x, y));
  rectangleShape->setFillColor(color);
}

Rectangle::~Rectangle()
{
}

sf::RectangleShape* Rectangle::GetShape() const
{
  return rectangleShape;
}