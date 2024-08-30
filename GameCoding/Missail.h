#pragma once
#include "Object.h"
class Missail : public Object
{
public:
	Missail();
	virtual ~Missail();

	void Init() override;
	void Update() override;
	void Render(HDC hdc) override;

public:
};

