#pragma once
#include "Entity.hh"
#include "Component.hh"
#include<string>
#include<vector>

class Entity;

class EntityManager
{
private:
  std::vector<Entity*> entities;
public:
  EntityManager();
  ~EntityManager();
  void Update(float deltaTime);
  void Render();
  bool HasNoEntities();
  Entity& AddEntity(std::string name);
  std::vector<Entity*> GetEntities() const;
  unsigned int GetEntityCount();
  void ClearData();
};
