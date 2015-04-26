#ifndef __WIN32_FRAME_H__
#define __WIN32_FRAME_H__

#define BODY_MAX 901
#define GROUND_BODY 900

#include "Scene.h"
#include "InputSystem.h"

class Win32Frame
{
public:
	~Win32Frame();
	static Win32Frame& GetInstance();

	void Initialize();
	void Exit();

	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

	void KeyDown( WPARAM wParam, LPARAM lParam );
	void KeyUp( WPARAM wParam, LPARAM lParam );
	void KeyChar( WPARAM wParam, LPARAM lParam );

	void ChangeScene( Scene* scene );

	void SethWnd( HWND hwnd );

	RECT GetClientRectbyFrame();

private:
	Win32Frame();
	void ChangeScene();

private:
	HWND mhwnd;
	RECT mClientRect;
	Scene* mCurrentScene;
	Scene* mChangeScene;
	bool mChange;
};

#define WIN32FRAME Win32Frame::GetInstance()

#endif __WIN32_FRAME_H__