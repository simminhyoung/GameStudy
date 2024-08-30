#pragma once
class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Upgrade();
	void Render();

private:
	HWND _hwnd = {};
	HDC _hdc = {};

private:
	HDC _hdcback = {};
	RECT _rect;
	HBITMAP _bmpback = {};
};