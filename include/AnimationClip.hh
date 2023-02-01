#pragma once
#include<fstream>
#include "json/json.h"

class AnimationClip
{
private:
  std::ifstream* reader{};
  Json::Value root{};
public:
  int animationIndex{};
  int startFrame{};
  int endFrame{};
  float animationDelay{};
  int currentAnimation{};
  AnimationClip(){}
  AnimationClip(const char* animUrl)
  {
    reader = new std::ifstream();
    reader->open(animUrl);
    root = Json::Value();

    *reader >> root;
    startFrame = root["animation"]["startFrame"].asInt();
    endFrame = root["animation"]["endFrame"].asInt();
    animationDelay = root["animation"]["delay"].asFloat();
    currentAnimation = root["animation"]["row"].asInt();
    animationIndex = startFrame;

    reader->close();
  }
  ~AnimationClip(){}
};
