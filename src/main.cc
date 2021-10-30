#include<iostream>
#include "Game.hh"

int main()
{

  /*sf::RectangleShape* rectangleShape{new sf::RectangleShape(sf::Vector2f(100, 100))};
  rectangleShape->setPosition(sf::Vector2f(200, 50));
  rectangleShape->setFillColor(sf::Color::Red);
*/

  Game* game{new Game()};
  game->Initialize();

  delete game;

  return EXIT_SUCCESS;
}
