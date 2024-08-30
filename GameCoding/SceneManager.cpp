#include "pch.h"
#include "SceneManager.h"
#include "DevScene.h"
#include "GameScene.h"
#include "EditScene.h"

void SceneManager::Init()
{
}

void SceneManager::Update()
{
	if (_scene)
	{
		_scene->Update();
	}
}

void SceneManager::Render(HDC hdc)
{
	if (_scene)
	{
		_scene->Render(hdc);
	}
}

void SceneManager::Clear()
{
	if (_scene)
	{
		delete _scene;
		_scene = nullptr;
	}
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_scenetype == sceneType)
	{
		return;
	}
	Scene* newScene = nullptr;

	switch (sceneType)
	{
	case SceneType::DevScene:
		newScene = new class DevScene();
		break;

	case SceneType::GameScene:
		newScene = new class GameScene();
		break;
	case SceneType::EditScene:
		newScene = new class EditScene();
		break;
	}

	if (_scene)
	{
		delete _scene;
		_scene = nullptr;
	}

	_scene = newScene;
	_scenetype = sceneType;

	newScene->Init();
}
