#include "pch.h"
#include "Monster.h"
#include "ObjectManager.h"
#include "Utils.h"

Monster::Monster() : Object(ObjectType::Monster)
{
}

Monster::~Monster()
{
}

void Monster::Init()
{
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 10;
}

void Monster::Update()
{
	
}

void Monster::Render(HDC hdc)
{
	Utils::DrowRect(hdc, _pos, 10, 10);
}
