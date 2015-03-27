#ifndef __WIN32_FRAME_H__
#define __WIN32_FRAME_H__

#include <Windows.h>

class Win32Frame
{
public:
	Win32Frame();
	~Win32Frame();

	void Initialize();
	void Exit();

	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

private:
	HDC mHdc;

};

#endif 