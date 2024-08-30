#pragma once
#include "Scene.h"

class DevScene : public Scene
{
public:
	DevScene();
	virtual ~DevScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	//TEST
	POS _playerPos = { 100,100 };
	float _speed = 100;
};

