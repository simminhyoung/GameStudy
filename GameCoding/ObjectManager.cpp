#include "pch.h"
#include "ObjectManager.h"
#include "Object.h"

ObjectManager::~ObjectManager()
{
	Clear();
}

void ObjectManager::Add(Object* object)
{
	if (object == nullptr)
	{
		return;
	}
	auto findIt = std::find(_object.begin(), _object.end(), object);

	if (findIt != _object.end())
	{
		return;
	}
	_object.push_back(object);

}

void ObjectManager::Remove(Object* object)
{
	auto findIt = std::remove(_object.begin(), _object.end(), object);
	_object.erase(findIt, _object.end());
	
	delete object;//ªË¡¶
}

void ObjectManager::Clear()
{
	std::for_each(_object.begin(), _object.end(), [](Object* obj) {delete obj; });
	
	_object.clear();
}
