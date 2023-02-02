#pragma once
#include "SFML/Audio.hpp"
#include<string>

class AudioClip
{
private:
  std::string audioUrl{};
  sf::Sound* sound{};
public:
  AudioClip();
  AudioClip(const char* audioUrl);
  ~AudioClip();

  void Play(sf::SoundBuffer& buffer);
  void SetVolume(float volume);
};