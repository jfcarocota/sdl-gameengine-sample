#pragma once
#include<string>

class Map
{
private:
  std::string textueId;
  int scale{1};
  int tileSize{1};
public:
  Map(std::string textureId, int scale, int tileSize);
  ~Map();
  void Addtile(int sourcex, int sourceY, int x, int y);
  void LoadMap(std::string filePath, int mapSizeX, int mapSizeY);
};
