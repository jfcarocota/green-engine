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

 void Entity::Render()
 {
   for(auto& component : components)
   {
      component->Render();
   }
 }

 bool Entity::IsActive() const
 {
   return this->isActive;
 }