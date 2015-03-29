#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__

#include "Scene.h"

class TestScene : public Scene
{
public:
	TestScene( Win32Frame* frame );
	~TestScene();

	void Enter();
	void Exit();
	
	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

	void KeyDown( WPARAM wParam, LPARAM lParam );
	/*void KeyUp( WPARAM wParam, LPARAM lParam );
	void KeyChar( WPARAM wParam, LPARAM lParam );*/


private:

};

#endif __TEST_SCENE_H__