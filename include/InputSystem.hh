#include<SFML/Graphics.hpp>

class InputSystem
{
public:
  InputSystem(){}
  ~InputSystem(){}

  static sf::Vector2f Axis()
  {
    sf::Vector2f axis{};

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) | sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
      axis.x = 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) | sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
      axis.x = -1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) | sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
      axis.y = -1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) | sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
      axis.y = 1;
    }

    return axis;
  }
};
