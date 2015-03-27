#include "Win32Frame.h"

Win32Frame::Win32Frame()
{
}
Win32Frame::~Win32Frame()
{
}


void Win32Frame::Initialize()
{
}

void Win32Frame::Exit()
{
}


void Win32Frame::Update( double dt )
{
}

void Win32Frame::Draw( HWND hwnd, HDC hdc )
{
	TextOut( hdc, 100, 100, L"Hello World", wcslen( L"Hello World" ) );
}