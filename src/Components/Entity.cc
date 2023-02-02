#include "Components/Entity.hh"
#include "Components/Component.hh"

 Entity::Entity(EntityManager& entityManager): entityManager(entityManager)
{
   this->isActive = true;
}
Entity::Entity(EntityManager& entityManager, std::string name): entityManager(entityManager), name(name)
{
   this->isActive = true;
}

Entity::~Entity()
{
   for(auto& component : components)
   {
      delete component;
   }
}

 void Entity::Update(float& deltaTime)
 {
   for(auto& component : components)
   {
      component->Update(deltaTime);
   }
 }

 void Entity::Destroy()
 {
   this->isActive = false;
 }

 void Entity::Render(sf::RenderWindow& window)
 {
   for(auto& component : components)
   {
      component->Render(window);
   }
 }

 bool Entity::IsActive() const
 {
   return this->isActive;
 }