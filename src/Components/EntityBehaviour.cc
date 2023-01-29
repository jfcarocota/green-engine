#include "Components/EntityBehaviour.hh"

EntityBehaviour::EntityBehaviour(EntityManager& entityManager, std::string entityName): entityManager(entityManager),
entityName(entityName),
entity(entityManager.AddEntity(entityName))
{
}

EntityBehaviour::~EntityBehaviour()
{
}
