#pragma once
#include<SDL2/SDL.h>
#include "Game.hh"
#include "EntityManager.hh"
#include "TransformComponent.hh"
#include "SpriteComponent.hh"
#include<string>

class KeyboardControlComponent
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
  KeyboardControlComponent(std::string upKey, std::string downKey, std::string leftKey, std::string rightKey, std::string shootKey);
  ~KeyboardControlComponent();

  std::string GetSDLKeyStringCode(std::string key);
};