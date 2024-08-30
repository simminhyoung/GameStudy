#pragma once

class Object;

class ObjectManager
{
	DECLARE_SINGLE(ObjectManager)
public:
	~ObjectManager();

	void Add(Object* object);
	void Remove(Object* object);
	void Clear();

	const vector<Object*>& GetObject() { return _object; }

	template<typename T>
	T* CreateObject()
	{
		T* object = new T();
		object->Init();

		return object;
	}

private:
	vector<Object*> _object;

};

