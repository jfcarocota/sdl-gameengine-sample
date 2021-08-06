#pragma once
#include<SDL2/SDL.h>
#include "Game.hh"
#include "EntityManager.hh"
#include "TransformComponent.hh"
#include "SpriteComponent.hh"
#include "InputSystem.hh"
#include<glm/glm.hpp>
#include<string>

class KeyboardControlComponent : public Component
{
public:
  float moveSpeed;
  TransformComponent* transform;
  SpriteComponent* sprite;

  KeyboardControlComponent(float moveSpeed);
  ~KeyboardControlComponent();
  void Initialize() override
  {
    transform = owner->GetComponent<TransformComponent>();
    sprite = owner->GetComponent<SpriteComponent>();
  }

  void Update(float deltaTime) override
  {
    std::cout << InputSystem::GetAxis().x << InputSystem::GetAxis().y << std::endl;
    transform->velocity.x = InputSystem::GetAxis().x * moveSpeed;
    transform->velocity.y = InputSystem::GetAxis().y * moveSpeed;
    sprite->spriteFlip = InputSystem::GetAxis().x < 0.f ? SDL_FLIP_HORIZONTAL : InputSystem::GetAxis().x > 0.f ? SDL_FLIP_NONE : sprite->spriteFlip;
    if(InputSystem::GetAxis() != glm::vec2(0, 0))
    {
      sprite->Play("WalkAnimation");
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