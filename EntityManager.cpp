#include "EntityManager.h"

void EntityManager::update()
{
	eraseDeadFromVector(m_entities);
	for (auto& [tag, entityVector] : m_entityMap)
	{
		eraseDeadFromVector(entityVector);
	}

	for (auto& e : m_toAdd)
	{
		m_entities.push_back(e);
		m_entityMap[e->tag()].push_back(e);
	}
	m_toAdd.clear();
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto e = std::shared_ptr<Entity>(new Entity(++m_totalEntities, tag));
	m_toAdd.push_back(e);

	return e;
}

EntityVector& EntityManager::getEntities()
{
	return m_entities;
}
EntityVector& EntityManager::getEntities(const std::string tag)
{
	return m_entityMap[tag];
}

void EntityManager::eraseDeadFromVector(EntityVector& vector)
{
	vector.erase(std::remove_if(vector.begin(), vector.end(), [](auto& e) { return !(e->alive()); }), vector.end());
}