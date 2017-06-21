#pragma once
#include <map>

template <typename Enum, typename Resource>
class ResourceManager
{
public:
	const Resource& get(Enum name) const
	{
		return m_resources.at(name);
	}

protected:
	virtual void addResource(Enum name, const std::string fileName)
	{
		Resource res;
		res.loadFromFile(fileName);
		m_resources.insert(std::make_pair(name, res));
	}

	std::map<Enum, Resource> m_resources;

};
