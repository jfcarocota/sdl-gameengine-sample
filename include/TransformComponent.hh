#pragma once
#include "EntityManager.hh"
#include<glm/glm.hpp>
#include<SDL2/SDL.h>
#include "Component.hh"
#include "Game.hh"

class TransformComponent : public Component
{
public:
  glm::vec2 position;
  glm::vec2 velocity;
  float width, height, scale;

  TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s)
  {
    position = glm::vec2(posX, posY);
    velocity = glm::vec2(velX, velY);
    width = w;
    height = h;
    scale = s;
  }

  void Initialize() override
  {

  }

  void Update(float deltaTime) override
  {
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
  }

  void Render() override
  {

  }
};
