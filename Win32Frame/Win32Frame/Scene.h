#ifndef __SCENE_H__
#define __SCENE_H__

#include <Windows.h>

class Scene
{
public:
	Scene();
	~Scene();

	void Enter();
	void Exit();

	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

	void KeyDown( WPARAM wParam, LPARAM lParam );
	void KeyUp( WPARAM wParam, LPARAM lParam );
	void KeyChar( WPARAM wParam, LPARAM lParam );


private:

};

#endif __SCENE_H__