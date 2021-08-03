#pragma once
#include<map>
#include<string>
#include "TextureManager.hh"
#include "EntityManager.hh"

class AssetManager
{
  private:
    EntityManager* manager;
    std::map<std::string, SDL_Texture*> textures;
  public:
    AssetManager(EntityManager* manager);
    ~AssetManager();
    void ClearData();
    void AddTexture(std::string textureId, const char* filePath);
    
};
