#include "pch.h"
#include "EditScene.h"
#include "InputManager.h"
#include "Utils.h"
#include "fstream"

EditScene::EditScene()
{
}

EditScene::~EditScene()
{
}

void EditScene::Init()
{
}

void EditScene::Update()
{
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::LeftMouse))
	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();

		if (_isLastPos)
		{
			_lastPos = mousePos;
			_isLastPos = false;
		}
		else
		{
			_lines.push_back(make_pair(_lastPos, mousePos));
			_lastPos = mousePos;
		}
	}
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::RightMouse))
	{
		_isLastPos = true;
	}
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::S))
	{
		wofstream file;

		file.open(L"Unit.txt");

		file << static_cast<int>(_lines.size()) << endl;//줄 개수

		for (auto& line : _lines)
		{
			POINT from = line.first;
			POINT to = line.second;

			wstring str = std::format(L"({0},{1})->({2},{3})", from.x, from.y, to.x, to.y);
			file << str << endl;
		}

		file.close();

	}
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::W))
	{
		wifstream file;

		file.open(L"Unit.txt");

		//줄 개수
		int count;
		file >> count;

		for (int i = 0; i < count; i++)
		{
			POINT from;
			POINT to;

			wstring str;
			file >> str;

			swscanf_s(str.c_str(), L"(%d,%d)->(%d,%d)", &from.x, &from.y, &to.x, &to.y);

			_lines.push_back(make_pair(from, to));
			_isLastPos = true;
		}
		
	}
}

void EditScene::Render(HDC hdc)
{
	for (auto& line : _lines)
	{
		POINT pt1 = line.first;
		POINT pt2 = line.second;

		POS pos1;
		POS pos2;
		pos1.x = pt1.x;
		pos1.y = pt1.y;
		pos2.x = pt2.x;
		pos2.y = pt2.y;

		Utils::DrowLine(hdc, pos1, pos2);
	}
}
