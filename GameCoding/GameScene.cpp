#include "pch.h"
#include "GameScene.h"
#include "Player.h"
#include "ObjectManager.h"
#include "Monster.h"


GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
	player->SetPos(POS{100,100});
	GET_SINGLE(ObjectManager)->Add(player);

	for (int i = 0; i < 5; i++)
	{
		Monster* monster = GET_SINGLE(ObjectManager)->CreateObject<Monster>();
		monster->SetPos(POS{ static_cast<float>(i + 1) * 100, 100 });
		GET_SINGLE(ObjectManager)->Add(monster);
	}
}

void GameScene::Update()
{
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObject();
	for (Object* object : objects)
	{
		object->Update();
	}
}

void GameScene::Render(HDC hdc)
{
	const vector<Object*>& objects = GET_SINGLE(ObjectManager)->GetObject();
	for (Object* object : objects)
	{
		object->Render(hdc);
	}
}
