#pragma once

class Utils
{
public:
	static void DrowText(HDC hdc,POS pos, const wstring& str);

	static void DrowRect(HDC hdc, POS pos, int w, int h);

	static void DrowCircle(HDC hdc, POS pos, int radius);

	static void DrowLine(HDC hdc, POS from, POS to);
};

