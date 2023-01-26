#include<iostream>
#include<string>
#include<fstream>
#include "CreateGameObject.hh"


void ErrorCommand();
void ValidateCommand(std::string& command, char* argv[]);

int main(int argc, char* argv[])
{
  std::string command{argv[1]};

  switch (argc)
  {
  case 3:
    ValidateCommand(command, argv);
    break;
  case 7:
    ValidateCommand(command, argv);
    break;
  default:
    ErrorCommand();
    break;
  }
  return 0;
}

void ErrorCommand()
{
  std::cout << "command not recognized" << std::endl;
}

void ValidateCommand(std::string& command, char* argv[])
{
  std::string assetName = argv[2];
  if(command == "gameobject")
  {
    //std::cout << "commans" << argv[0] << " " << argv[1] << " " << argv[2] << std::endl;
    CreateGameObject(assetName);
    return;
  }

  if(command == "animation")
  {
    std::cout << "commands" << argv[0] << " " << argv[1] << " " << argv[2] << std::endl;
    CreateGameObject(assetName);
    return;
  }
  std::cout << "command not found" << std::endl;
}
