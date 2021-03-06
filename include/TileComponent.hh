#pragma once
#include<SDL2/SDL.h>
#include "EntityManager.hh"
#include "AssetManager.hh"
#include "Game.hh"
#include<glm/glm.hpp>
#include<string>

class TileComponent : public Component
{
public:

  SDL_Texture* texture;
  SDL_Rect sourceRectangle;
  SDL_Rect destinationRectangle;
  glm::vec2 position;

  TileComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string assetTextureId)
  {
    texture = Game::assetManager->GetTexture(assetTextureId);

    sourceRectangle.x = sourceRectX;
    sourceRectangle.y = sourceRectY;
    sourceRectangle.w = tileSize;
    sourceRectangle.h = tileSize;

    destinationRectangle.x = x;
    destinationRectangle.y = y;
    destinationRectangle.w = tileSize * tileScale;
    destinationRectangle.h = tileSize * tileScale;

    position.x = x;
    position.y = y;
  }
  ~TileComponent()
  {
    SDL_DestroyTexture(texture);
  }

  void Update(float deltaTime) override
  {

  }

  void Render() override
  {
    TextureManager::Draw(texture, sourceRectangle, destinationRectangle, SDL_FLIP_NONE);
  }
};
