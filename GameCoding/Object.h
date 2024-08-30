#pragma once

enum class ObjectType
{
	Player,
	Monster,
	projectile,
	None
};

class Object
{
public:
	Object(ObjectType objecttype);
	virtual ~Object();

public:
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	ObjectType GetObjectType() { return _objectType; };

	POS GetPos() { return _pos; };
	void SetPos(POS pos) { _pos = pos; };

protected:
	ObjectType _objectType = ObjectType::None;
	POS _pos = {};
	Stat _stat = {};
};

