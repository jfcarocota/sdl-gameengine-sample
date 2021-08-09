#pragma once
#include "Component.hh"
#include<SDL2/SDL_mixer.h>

class AudioListenerComponent : public Component
{
private:

public:
  AudioListenerComponent();
  ~AudioListenerComponent();

  void Play(Mix_Chunk*&  audio);

  void Initialize() override
  {

  }

  void Update(float deltaTime) override
  {

  }

  void Render() override
  {

  }
};
