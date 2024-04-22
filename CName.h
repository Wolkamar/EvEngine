#include <string>

class CName
{
	std::string name = "DefaultName";

	CName(std::string& name)
		: name(name) {}
};