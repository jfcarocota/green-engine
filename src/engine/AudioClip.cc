#include "AudioClip.hh"

AudioClip::AudioClip(const char* audioUrl, float audioVolume)
{
  soundBuffer = new sf::SoundBuffer();
  sound = new sf::Sound();
  soundBuffer->loadFromFile(audioUrl);
  sound->setBuffer(*soundBuffer);
  sound->setVolume(audioVolume);
}

AudioClip::~AudioClip()
{
}

void AudioClip::Play()
{
  sound->play();
}