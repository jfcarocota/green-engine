#include "Components/AudioListenerComponent.hh"

AudioListenerComponent::AudioListenerComponent()
{
  this->soundBuffer = sf::SoundBuffer();
}

AudioListenerComponent::~AudioListenerComponent()
{
}

void AudioListenerComponent::Initialize()
{

}

AudioClip* AudioListenerComponent::GetAudioClip() const
{
  return audioClip;
}

void AudioListenerComponent::Play()
{
  if(audioClip)
  {
    audioClip->SetVolume(1.f);
    audioClip->Play(soundBuffer);
  }
}

void AudioListenerComponent::PlayOneShot(AudioClip& audioClip, float audioVolume)
{
  audioClip.SetVolume(audioVolume);
  audioClip.Play(soundBuffer);
}

void AudioListenerComponent::PlayOneShot(AudioClip& audioClip)
{
  audioClip.SetVolume(1.f);
  audioClip.Play(soundBuffer);
}