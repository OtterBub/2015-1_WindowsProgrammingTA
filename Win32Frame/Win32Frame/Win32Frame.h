#ifndef __WIN32_FRAME_H__
#define __WIN32_FRAME_H__

#include "Scene.h"
#include "InputSystem.h"

class Win32Frame
{
public:
	Win32Frame();
	~Win32Frame();

	void Initialize();
	void Exit();

	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

	void KeyDown( WPARAM wParam, LPARAM lParam );
	void KeyUp( WPARAM wParam, LPARAM lParam );
	void KeyChar( WPARAM wParam, LPARAM lParam );

	void ChangeScene( Scene* scene );

private:
	Scene* mCurrentScene;

};

#endif __WIN32_FRAME_H__