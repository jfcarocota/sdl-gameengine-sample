#include "Entity.hh"

Entity::Entity(EntityManager& entityManager) : entityManager(entityManager)
{
  isActive = true;
}

Entity::Entity(EntityManager& entityManager, std::string name) : entityManager(entityManager)
{
  this->name = name;
  isActive = true;
}

Entity::~Entity()
{
}

void Entity::Update(float deltaTime)
{

}
void Entity::Render()
{

}
void Entity::Destroy()
{

}
bool Entity::IsActive() const
{
  return isActive;
}