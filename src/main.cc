#include<iostream>
#include "Game.hh"
#include "json/json.h"

int main()
{

  Game* game{new Game()};
  game->Initialize();

  delete game;

  return EXIT_SUCCESS;
}
