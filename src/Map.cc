#include "Map.hh"
#include "Entity.hh"
#include "EntityManager.hh"
#include "TileComponent.hh"
#include<fstream>
#include<iostream>

extern EntityManager manager;

Map::Map(std::string textureId, int scale, int tileSize)
{
  this->textueId = textueId;
  this->scale = scale;
  this->tileSize = tileSize;
}

Map::~Map()
{
}

void Map::Addtile(int sourceRectX, int sourceRectY, int x, int y)
{
  Entity& newTile{manager.AddEntity("Tile")};
  newTile.AddComponent<TileComponent>(sourceRectX, sourceRectY, x, y, tileSize, scale, textueId);
}

void Map::LoadMap(std::string filePath, int mapSizeX, int mapSizeY)
{
  std::fstream mapFile;
  mapFile.open(filePath);
  for(int y = 0; y < mapSizeY; y++)
  {
    for(int x = 0; x < mapSizeX; x++)
    {
      char ch;
      mapFile.get(ch);
      int sourceRectY = atoi(&ch) * tileSize;
      mapFile.get(ch);
      int sourceRectX = atoi(&ch) * tileSize;

      Addtile(sourceRectX, sourceRectY, x * (scale * tileSize), y * (scale * tileSize));
      mapFile.ignore();
    }
  }
  mapFile.close();
}