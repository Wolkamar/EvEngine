#include <string>
#include <memory>

#include "CTransform.cpp"
#include "CShape.cpp"
#include "CCollider.cpp"
#include "CName.cpp"
#include "CInput.cpp"
#include "CScore.cpp"
#include "CLifespan.cpp"

class Entity
{
	const std::string	m_tag	= "Default";
	const size_t		m_id	= 0;
	bool				m_alive = true;

	Entity(const std::string& tag, size_t id)
		: m_tag(tag), m_id(id) {}

public:
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CShape> cShape;
	std::shared_ptr<CCollider> cCollider;
	std::shared_ptr<CName> cName;
	std::shared_ptr<CInput> cInput;
	std::shared_ptr<CScore> cScore;
	std::shared_ptr<CLifespan> cLifespan;

	const std::string&	tag()	{ return m_tag; }
	size_t				id()	{ return m_id; }
	bool				alive() { return m_alive; }

	void kill() { m_alive = false; }
};