#pragma once
#include "EntityManager.hh"
#include "Component.hh"
#include "EntityManager.hh"
#include<vector>
#include<map>
#include<string>

class Component;
class EntityManager;

class Entity
{
private:
  EntityManager& entityManager;
  bool isActive;
  std::vector<Component*> components{};
  std::map<const std::type_info*, Component*> componentTypeMap;
public:
  std::string name;

  Entity(EntityManager& entityManager);
  Entity(EntityManager& entityManager, std::string name);
  ~Entity();
  void Update(float deltaTime);
  void Render();
  void Destroy();
  bool IsActive() const;
  template <typename T, typename... TArgs>
  T& AddComponent(TArgs&&... args)
  {
    T* newComponent{new T(std::forward<TArgs>(args)...)};
    newComponent->owner = this;
    components.emplace_back(newComponent);
    componentTypeMap[&typeid(*newComponent)] = newComponent;
    newComponent->Initialize();
    return *newComponent;
  }

  template<typename T>
  T* GetComponent()
  {
    return static_cast<T*>(componentTypeMap[&typeid(T)]);
  }
};