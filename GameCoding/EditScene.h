#pragma once
#include "Scene.h"

class EditScene : public Scene
{
public:
	EditScene();
	virtual ~EditScene();

	void Init() override;
	void Update() override;
	void Render(HDC hdc) override;

private:
	vector<pair<POINT, POINT>> _lines;

	POINT _lastPos = {};
	bool _isLastPos = true;

};

