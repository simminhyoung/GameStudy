#include "pch.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Game::Game()
{
}

Game::~Game()
{
	GET_SINGLE(SceneManager)->Clear();
	_CrtDumpMemoryLeaks();
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_hdc = ::GetDC(hwnd);
	::GetClientRect(hwnd, &_rect);

	_hdcback = ::CreateCompatibleDC(_hdc); // 화면dc(그릴 윈도우) 기반 메모리 DC생성 
	_bmpback = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom); // 비트맵 생성
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcback, _bmpback); // 비트맵 선택
	::DeleteObject(prev);
	

	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(hwnd);
	GET_SINGLE(SceneManager)->Init();

	GET_SINGLE(SceneManager)->ChangeScene(EditScene);
}

void Game::Upgrade()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	GET_SINGLE(SceneManager)->Update();
}

void Game::Render()
{
	unsigned int fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	{
		wstring str = std::format(L"FPS({0}), DT({1} ms)", fps, static_cast<unsigned int>(deltaTime * 1000));

		::TextOut(_hdcback, 650, 10, str.c_str(), static_cast<int>(str.size()));
	}

	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"X({0}), Y({1})", mousePos.x, mousePos.y);
		::TextOut(_hdcback, 20, 10, str.c_str(), static_cast<int>(str.size()));
	}

	GET_SINGLE(SceneManager)->Render(_hdcback);

	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcback, 0, 0, SRCCOPY); // 고속복사 hMemdc->hdc
	::PatBlt(_hdcback, 0, 0, _rect.right, _rect.bottom, WHITENESS);

}
