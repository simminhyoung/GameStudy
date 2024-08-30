#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	BYTE askiiKeys[KEY_TYPE_COUNT] = { };
	if (::GetKeyboardState(askiiKeys) == false)
	{
		return;
	}
	for (unsigned int key = 0; key < KEY_TYPE_COUNT; key++)
	{
		if (askiiKeys[key] & 0x80)
		{
			KeyState& state = _states[key];
			if (state == KeyState::Press || state == KeyState::Down)
			{
				state = KeyState::Press;
			}
			else
			{
				state = KeyState::Down;
			}

		}
		else
		{
			KeyState& state = _states[key];
			if (state == KeyState::Press || state == KeyState::Down)
			{
				state = KeyState::Up;
			}
			else
			{
				state = KeyState::None;
			}
		}
	}

	//Mouse
	::GetCursorPos(&_mousePos);
	::ScreenToClient(_hwnd, &_mousePos);

}
