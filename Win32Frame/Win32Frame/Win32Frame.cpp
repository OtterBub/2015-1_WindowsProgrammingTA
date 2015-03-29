#include "Win32Frame.h"

Win32Frame::Win32Frame()
{
	mRect = {0, 0, 50, 50};
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


void KeyDown( WPARAM wParam, LPARAM lParam )
{
	 
}

void KeyUp( WPARAM wParam, LPARAM lParam )
{

}

void KeyChar( WPARAM wParam, LPARAM lParam )
{

}