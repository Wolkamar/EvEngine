#pragma once

#include "Common.h"
#include "Entity.h"

typedef std::vector	<std::shared_ptr<Entity>>	EntityVector;
typedef std::map	<std::string, EntityVector> EntityMap;

class EntityManager
{
	EntityVector	m_entities;
	EntityMap		m_entityMap;
	EntityVector	m_toAdd;
	size_t			m_totalEntities = -1;

	void eraseDeadFromVector(EntityVector& vector); //delete all dead entities from vector

public:
	EntityManager() {}

	void update(); //delete what's need to be deleted, add what's need to be added

	std::shared_ptr<Entity> addEntity(const std::string& tag);

	EntityVector& getEntities();
	EntityVector& getEntities(const std::string tag);
};