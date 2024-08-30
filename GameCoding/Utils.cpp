#include "pch.h"
#include "Utils.h"


void Utils::DrowText(HDC hdc, POS pos, const wstring& str)
{
	::TextOut(hdc, static_cast<int>(pos.x), static_cast<int>(pos.y), str.c_str(), static_cast<int>(str.size()));
}

void Utils::DrowRect(HDC hdc, POS pos, int w, int h)
{
	::Rectangle(hdc, static_cast<int>(pos.x - w/2), static_cast<int>(pos.y - h/2), static_cast<int>(pos.x + w / 2), static_cast<int>(pos.y + h / 2));
}


void Utils::DrowCircle(HDC hdc, POS pos, int radius)
{
	::Ellipse(hdc, static_cast<int>(pos.x - radius), static_cast<int>(pos.y - radius), static_cast<int>(pos.x + radius), static_cast<int>(pos.y + radius));
}

void Utils::DrowLine(HDC hdc, POS from, POS to)
{
	::MoveToEx(hdc, static_cast<int>(from.x), static_cast<int>(from.y), nullptr);
	::LineTo(hdc, static_cast<int>(to.x), static_cast<int>(to.y));
}
