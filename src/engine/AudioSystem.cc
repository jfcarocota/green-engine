#include "AudioSystem.hh"

AudioSystem::AudioSystem()
{
  audioClips = new std::map<std::string, AudioClip*>();
}

AudioSystem::~AudioSystem()
{
}

AudioClip* AudioSystem::GetAudioClip(std::string audioClipName)
{
  return audioClips->at(audioClipName);
}

void AudioSystem::Play(std::string audioClipName)
{
  GetAudioClip(audioClipName)->Play();
}
void AudioSystem::AddAudioClip(std::string audioClipName, AudioClip* audioClip)
{
  audioClips->insert({audioClipName, audioClip});
}