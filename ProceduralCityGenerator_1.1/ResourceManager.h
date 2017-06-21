#pragma once
#include <map>

template <typename Enum, typename Resource>
class ResourceManager
{
public:
	const Resource& get(Enum name)
	{
		return m_resources.at(name);
	}

protected:
	void addResource(Enum name, const std::string fileName)
	{
		Resource res;
		res.loadFromFile(fileName);
		m_resources.insert(std::make_pair(name, res));
	}

private:
	std::map<Enum, Resource> m_resources;
};
