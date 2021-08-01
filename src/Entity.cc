#include "Entity.hh"

Entity::Entity(EntityManager& entityManager) : entityManager(entityManager)
{
  isActive = true;
}

Entity::Entity(EntityManager& entityManager, std::string name) : entityManager(entityManager), name(name)
{
  isActive = true;
}

Entity::~Entity()
{
}

void Entity::Update(float deltaTime)
{
  for(auto& component : components)
  {
    component->Update(deltaTime);
  }
}

void Entity::Render()
{
  for(auto& component : components)
  {
    component->Render();
  }
}

void Entity::Destroy()
{
  isActive = false;
}

bool Entity::IsActive() const
{
  return isActive;
}