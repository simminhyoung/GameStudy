#include "pch.h"
#include "Missail.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Utils.h"
#include "ObjectManager.h"

Missail::Missail() : Object(ObjectType::projectile)
{
}

Missail::~Missail()
{
}

void Missail::Init()
{
	_stat.hp = 1;
	_stat.maxHp = 1;
	_stat.speed = 50;
}

void Missail::Update()
{
	//생성
	float _deltatime = GET_SINGLE(TimeManager)->GetDeltaTime();

	_pos.y -= _stat.speed * _deltatime;

	if (_pos.y < 0)
	{
		GET_SINGLE(ObjectManager)->Remove(this);
		return;
	}

	//충돌
	vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObject();
	for (Object* object : objects)
	{
		if (this == object)
		{
			continue;
		}

		if (object->GetObjectType() != ObjectType::Monster)
		{
			continue;
		}

		POS p1 = this->GetPos();
		POS p2 = object->GetPos();

		float dx = p1.x - p2.x;
		float dy = p1.y - p2.y;

		float dist = sqrt(dx * dx + dy * dy);

		if (dist < 10)
		{
			GET_SINGLE(ObjectManager)->Remove(this);
			GET_SINGLE(ObjectManager)->Remove(object);
			return;
		}
	}
}

void Missail::Render(HDC hdc)
{
	Utils::DrowCircle(hdc, _pos, 5);
}
