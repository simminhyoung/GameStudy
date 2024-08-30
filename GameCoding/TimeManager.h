#pragma once
class TimeManager
{
	DECLARE_SINGLE(TimeManager)
public:
	void Init();
	void Update();

	float GetDeltaTime() { return _deltaTime; }
	unsigned int GetFps() { return _fps; }

private:
	unsigned __int64 _frequency = 0;
	unsigned __int64 _prevCount = 0;
	float _deltaTime = 0.f;

private:
	unsigned int _frameCount = 0;
	float _frameTime = 0.f;
	unsigned int _fps = 0;
};

