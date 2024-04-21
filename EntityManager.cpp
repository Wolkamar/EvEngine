#include <vector>
#include <memory>
#include <map>
#include <string>

#include "Entity.cpp"

typedef std::vector	<std::shared_ptr<Entity>> EntityVector;
typedef std::map	<std::string, EntityVector> EntityMap;

class EntityManager
{
	EntityVector	m_entities;
	EntityMap		m_entityMap;
	size_t			m_totalEntities = 0;
};