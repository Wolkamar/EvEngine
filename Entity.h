#pragma once
#include "Components.h"

class Entity
{
	friend class EntityManager;

	const std::string	m_tag	= "DefaultTag";
	const size_t		m_id	= 0;
	bool				m_alive = true;

	Entity(const size_t id, const std::string& tag);

public:
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CShape> cShape;
	std::shared_ptr<CCollider> cCollider;
	std::shared_ptr<CName> cName;
	std::shared_ptr<CInput> cInput;
	std::shared_ptr<CScore> cScore;
	std::shared_ptr<CLifespan> cLifespan;

	const std::string&	tag()	const;
	const size_t		id()	const;
	bool				alive() const;

	void kill();
};