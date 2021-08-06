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

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

glm::vec2 InputSystem::axis;

glm::vec2 InputSystem::GetAxis()
{
  if(Game::event.type == SDL_KEYUP)
  {
    switch (Game::event.key.keysym.sym)
    {
      case SDLK_UP:
        axis.y = 0;
        break;
      case SDLK_DOWN:
        axis.y = 0;
        break;
      case SDLK_RIGHT:
        axis.x = 0;
        break;
      case SDLK_LEFT:
        axis.x = 0;
        break;
      default:
        axis.x = 0;
        axis.y = 0;
        break;
    }
  }
  else
  {
    switch (Game::event.key.keysym.sym)
    {
      case SDLK_UP:
        axis.y = 1;
        break;
      case SDLK_DOWN:
        axis.y = -1;
        break;
      case SDLK_RIGHT:
        axis.x = 1;
        break;
      case SDLK_LEFT:
        axis.x = -1;
        break;
      default:
        axis.x = 0;
        axis.y = 0;
        break;
    }
  }
  return axis;
}
