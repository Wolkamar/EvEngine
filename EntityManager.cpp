#include <vector>
#include <memory>
#include <map>
#include <string>
#include <algorithm>

#include "Entity.cpp"

typedef std::vector	<std::shared_ptr<Entity>> EntityVector;
typedef std::map	<std::string, EntityVector> EntityMap;

class EntityManager
{
	EntityVector	m_entities;
	EntityMap		m_entityMap;
	EntityVector	m_toAdd;
	size_t			m_totalEntities = -1;

	void init()
	{

	}

public:
	EntityManager() {}


	void update()
	{
		eraseDeadFromVector(m_entities);
		for (auto& [key, val] : m_entityMap)
		{
			eraseDeadFromVector(val);
		}

		for (auto& e : m_toAdd)
		{
			m_entities.push_back(e);
			m_entityMap[e->tag()].push_back(e);
		}
		m_toAdd.clear();
	}

	void eraseDeadFromVector(EntityVector& vector)
	{
		vector.erase(std::remove_if(vector.begin(), vector.end(), [](auto& e) { return !(e->alive()); }), vector.end());
	}

	std::shared_ptr<Entity> addEntity(const std::string& tag)
	{
		auto e = std::make_shared<Entity>(tag, ++m_totalEntities);
		//auto e = std::shared_ptr<Entity>(new Entity(tag, ++m_totalEntities));
		m_toAdd.push_back(e);

		return e;
	}

	EntityVector& getEntities()							{ return m_entities; }
	EntityVector& getEntities(const std::string tag)	{ return m_entityMap[tag]; }
};