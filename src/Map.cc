#include "Map.hh"
#include "Entity.hh"
#include "EntityManager.hh"
#include "TileComponent.hh"
#include<fstream>

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

void Map::Addtile(int sourcex, int sourceY, int x, int y)
{
  Entity& entity{manager.AddEntity("tile")};
  entity.AddComponent<TileComponent>(sourcex, sourceY, x, y, tileSize, scale, textueId);
}

void Map::LoadMap(std::string filePath, int mapSizeX, int mapSizeY)
{
  std::fstream mapFile;
  mapFile.open(filePath);
  for(int y{}; y < mapSizeY; y++)
  {
    for(int x; x < mapSizeX; x++)
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