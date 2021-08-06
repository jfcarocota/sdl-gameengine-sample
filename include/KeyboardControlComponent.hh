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
  std::string upKey;
  std::string downKey;
  std::string leftKey;
  std::string rightKey;
  std::string shootKey;
  TransformComponent* transform;
  SpriteComponent* sprite;

  KeyboardControlComponent();
  ~KeyboardControlComponent();
  void Initialize() override
  {
    transform = owner->GetComponent<TransformComponent>();
    sprite = owner->GetComponent<SpriteComponent>();
  }

  void Update(float deltaTime) override
  {
    std::cout << InputSystem::GetAxis().x << InputSystem::GetAxis().y << std::endl;
    transform->velocity.x = InputSystem::GetAxis().x * 100;
    transform->velocity.y = InputSystem::GetAxis().y * 100;
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