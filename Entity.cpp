#include "Entity.h"

Entity::Entity(const size_t id, const std::string& tag)
	: m_tag(tag), m_id(id) {}

const std::string& Entity::tag() const
{
	return m_tag;
}

const size_t Entity::id() const
{
	return m_id;
}

bool Entity::alive() const
{
	return m_alive;
}

void Entity::kill()
{
	m_alive = false;
}
