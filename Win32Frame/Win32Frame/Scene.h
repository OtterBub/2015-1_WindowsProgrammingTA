#ifndef __SCENE_H__
#define __SCENE_H__

#include <Windows.h>
#include <memory>

class Win32Frame;

class Scene
{
public:
	Scene( Win32Frame* frame ){ mFrame = frame; };
	virtual ~Scene(){ };

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	virtual void Update( double dt ) {}
	virtual void Draw( HWND hwnd, HDC hdc ) {}

	virtual void KeyDown( WPARAM wParam, LPARAM lParam ) {}
	virtual void KeyUp( WPARAM wParam, LPARAM lParam ) {}
	virtual void KeyChar( WPARAM wParam, LPARAM lParam ) {}


protected:
	Win32Frame* mFrame;
};

#endif __SCENE_H__