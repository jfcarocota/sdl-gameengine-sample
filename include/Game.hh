#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "Constants.hh"
#include "EntityManager.hh"
#include "AssetManager.hh"
#include<glm/glm.hpp>

class AssetManager;

class Game
{
  private:
    bool isRunning{false};
    SDL_Window* window{};
    int ticksLastFrame{};
  public:
    static SDL_Renderer* renderer;
    static AssetManager* assetManager;
    Game();
    ~Game();
    void Initialize(unsigned int windowWidth, unsigned int windowHeight);
    bool IsRunning() const;
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
    void LoadLevel(int level);
};
