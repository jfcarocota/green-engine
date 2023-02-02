#pragma once
#include "Component.hh"
#include "AudioClip.hh"
#include "SFML/Audio.hpp"

class AudioListenerComponent: public Component
{
private:
  AudioClip* audioClip{};
  sf::SoundBuffer soundBuffer{};
public:
  AudioListenerComponent();
  ~AudioListenerComponent();

  AudioClip* GetAudioClip() const;
  void Play();
  void PlayOneShot(AudioClip& audioClip);
  void PlayOneShot(AudioClip& audioClip, float audioVolume);
  void Initialize() override;
};
