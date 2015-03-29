#ifndef __MENUSCENE_H__
#define __MENUSCENE_H__

#include "Scene.h"

class MenuScene : public Scene
{
public:
	MenuScene( Win32Frame* frame );
	~MenuScene();

	void Enter();
	void Exit();
	
	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

	void KeyDown( WPARAM wParam, LPARAM lParam );

private:

};

#endif