#pragma once
#include<string>

class Map
{
private:
  std::string textureId;
  int scale;
  int tileSize;
public:
  Map(std::string textureId, int scale, int tileSize);
  ~Map();
  void AddTile(int sourceX, int sourceY, int x, int y);
  void LoadMap(std::string filePath, int mapSizeX, int mapSizeY);
};
