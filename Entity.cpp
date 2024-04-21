#include <string>
#include <memory>

#include "CTransform.cpp"
#include "CName.cpp"
#include "CShape.cpp"
#include "CBBox.cpp"

class Entity
{
	const size_t		m_id	= 0;
	const std::string	m_tag	= "Default";
	bool				m_alive = true;

	Entity(size_t id, const std::string& tag)
		: m_id(id), m_tag(tag) {}

public:
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CName> cName;
	std::shared_ptr<CShape> cShape;
	std::shared_ptr<CBBox> cBBox;
};