#include<iostream>
#include "Game.hh"

int main()
{

  Game* game{new Game()};
  game->Initialize();

  delete game;

  return EXIT_SUCCESS;
}
