#include "ContactEventManager.hh"
#include<iostream>
#include "Components/Component.hh"
#include "Components/Entity.hh"
#include "Components/EntityManager.hh"
#include "Components/RigidBodyComponent.hh"

ContactEventManager::ContactEventManager()
{

}

ContactEventManager::~ContactEventManager()
{
}

void ContactEventManager::BeginContact(b2Contact* contact)
{
  Entity* actorA{(Entity*)contact->GetFixtureA()->GetBody()->GetUserData().pointer};
  Entity* actorB{(Entity*)contact->GetFixtureB()->GetBody()->GetUserData().pointer};

  if(actorA && actorB)
  {
    std::cout << "Collision: " << actorA->name << ", " << actorB->name << std::endl;
    if(actorB->name.compare("chest") == 0)
    {
      actorB->Destroy();
    }
  }
}
void ContactEventManager::EndContact(b2Contact* contact)
{

}