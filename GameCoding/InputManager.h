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
	//������ ��
	Press,
	//����
	Down,
	//��
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
	//��ư�� ��������
	bool GetButtonPress(KeyType key) { return GetState(key) == KeyState::Press; }
	//��ư�� ó�� ����
	bool GetButtonDown(KeyType key) { return GetState(key) == KeyState::Down; }
	//��ư�� �����ٰ� ����
	bool GetButtonUp(KeyType key) { return GetState(key) == KeyState::Up; }

	POINT GetMousePos() { return _mousePos; }
private:
	KeyState GetState(KeyType key) { return _states[static_cast<unsigned __int8>(key)]; }

private:
	HWND _hwnd = 0;
	vector<KeyState> _states;
	POINT _mousePos;
};

