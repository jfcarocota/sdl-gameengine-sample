#pragma once
#include<SDL2/SDL.h>
#include "Game.hh"
#include "EntityManager.hh"
#include "TransformComponent.hh"
#include "SpriteComponent.hh"
#include "AudioListenerComponent.hh"
#include "SDL2/SDL_mixer.h"
#include "InputSystem.hh"
#include<glm/glm.hpp>
#include<string>

class KeyboardControlComponent : public Component
{
public:
  float moveSpeed;
  TransformComponent* transform;
  SpriteComponent* sprite;
  AudioListenerComponent* audioListener;
  Mix_Chunk* footSteps{};
  float footspesTimer{};
  float footestepsDelay{0.3f};

  KeyboardControlComponent(float moveSpeed);
  ~KeyboardControlComponent();
  void Initialize() override
  {
    transform = owner->GetComponent<TransformComponent>();
    sprite = owner->GetComponent<SpriteComponent>();
    audioListener = owner->GetComponent<AudioListenerComponent>();
    footSteps = Mix_LoadWAV("assets/audio/stepsfx.wav");
  }

  void Update(float deltaTime) override
  {
    //std::cout << InputSystem::GetAxis().x << InputSystem::GetAxis().y << std::endl;
    transform->velocity.x = InputSystem::GetAxis().x * moveSpeed;
    transform->velocity.y = InputSystem::GetAxis().y * moveSpeed;
    sprite->spriteFlip = InputSystem::GetAxis().x < 0.f ? SDL_FLIP_HORIZONTAL : InputSystem::GetAxis().x > 0.f ? SDL_FLIP_NONE : sprite->spriteFlip;
    if(InputSystem::GetAxis() != glm::vec2(0, 0))
    {
      footspesTimer += deltaTime;
      sprite->Play("WalkAnimation");
      if(footspesTimer >= footestepsDelay)
      {
        footspesTimer = 0.f;
        audioListener->Play(footSteps);
      }
    }
    else
    {
      sprite->Play("IdleAnimation");
    }
  }

  void Render() override
  {

  }
};