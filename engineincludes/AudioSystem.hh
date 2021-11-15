#pragma once
#include<map>
#include<string>
#include "AudioClip.hh"

class AudioSystem
{
private:
  std::map<std::string, AudioClip*>* audioClips;
public:
  AudioSystem();
  ~AudioSystem();

  AudioClip* GetAudioClip(std::string audioClipName);

  void Play(std::string audioClipName);
  void AddAudioClip(std::string audioClipName, AudioClip* audioClip);
};