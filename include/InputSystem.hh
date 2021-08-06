#pragma once
#include "Game.hh"
#include<glm/glm.hpp>
#include<SDL2/SDL.h>

class InputSystem
{
private:
  static glm::vec2 axis;
public:
  InputSystem();
  ~InputSystem();

  static glm::vec2 GetAxis();
};