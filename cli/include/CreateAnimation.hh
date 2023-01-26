#pragma once
#include<iostream>
#include<string>
#include<fstream>

void CreateAnimation(std::string assetName)
{
  std::ofstream* writer{new std::ofstream()};
  writer->open("assets/animations/" + assetName + ".hh");
}