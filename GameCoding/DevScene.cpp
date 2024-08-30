#include "pch.h"
#include "DevScene.h"
#include "Utils.h"
#include "InputManager.h"
#include "TimeManager.h"

DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
}

void DevScene::Update()
{
	float _deltatime = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::A))
	{
		_playerPos.x -= _speed * _deltatime;
	}
	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::D))
	{
		_playerPos.x += _speed * _deltatime;
	}
	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::W))
	{
		_playerPos.y -= _speed * _deltatime;
	}
	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::S))
	{
		_playerPos.y += _speed * _deltatime;
	}
}

void DevScene::Render(HDC hdc)
{
	Utils::DrowCircle(hdc, _playerPos, 10);
}
