#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Utils.h"
#include "Missail.h"
#include "ObjectManager.h"


Player::Player() : Object(ObjectType::Player)
{
}

Player::~Player()
{
}

void Player::Init()
{
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 100;

	_pos.x = 100;
	_pos.y = 100;

}

void Player::Update()
{
	float _deltatime = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::A))
	{
		_pos.x -= _stat.speed * _deltatime;
	}
	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::D))
	{
		_pos.x += _stat.speed * _deltatime;
	}
	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::W))
	{
		_pos.y -= _stat.speed * _deltatime;
	}
	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::S))
	{
		_pos.y += _stat.speed * _deltatime;
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::Space))
	{
		//미사일 발사
		Missail* missail = GET_SINGLE(ObjectManager)->CreateObject<Missail>();
		missail->SetPos(_pos);
		GET_SINGLE(ObjectManager)->Add(missail);
	}
}

void Player::Render(HDC hdc)
{
	Utils::DrowCircle(hdc, _pos, 10);
	//wstring str = std::format(L"({0})", _stat.hp);
	//::TextOut(hdc, _pos.x, _pos.y, str.c_str(), static_cast<int>(str.size()));
}
