#include "AudioListenerComponent.hh"

AudioListenerComponent::AudioListenerComponent()
{
}

AudioListenerComponent::~AudioListenerComponent()
{
}

void AudioListenerComponent::Play(Mix_Chunk*& audio)
{
  Mix_PlayChannel(-1, audio, 0);
}