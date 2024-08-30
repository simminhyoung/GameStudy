#pragma once
enum class KeyType
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Down = VK_DOWN,
	RIght = VK_RIGHT,
	Left = VK_LEFT,

	Space = VK_SPACE,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D'
};

enum class KeyState
{
	None,
	//누르는 중
	Press,
	//누름
	Down,
	//땜
	Up,

	End
};

enum
{
	KEY_TYPE_COUNT = 256,
	KEY_STATE_COUNT = static_cast<unsigned int>(KeyState::End)
};

class InputManager
{
	DECLARE_SINGLE(InputManager)

public:
	void Init(HWND hwnd);
	void Update();
	//버튼을 누르는중
	bool GetButtonPress(KeyType key) { return GetState(key) == KeyState::Press; }
	//버튼을 처음 누름
	bool GetButtonDown(KeyType key) { return GetState(key) == KeyState::Down; }
	//버튼을 눌렀다가 땔때
	bool GetButtonUp(KeyType key) { return GetState(key) == KeyState::Up; }

	POINT GetMousePos() { return _mousePos; }
private:
	KeyState GetState(KeyType key) { return _states[static_cast<unsigned __int8>(key)]; }

private:
	HWND _hwnd = 0;
	vector<KeyState> _states;
	POINT _mousePos;
};

