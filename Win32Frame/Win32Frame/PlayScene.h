#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include "Scene.h"

class PlayScene : public Scene
{
public:
	PlayScene( Win32Frame* frame );
	~PlayScene();

	void Enter();
	void Exit();
	
	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

	void KeyDown( WPARAM wParam, LPARAM lParam );

private:

};

#endif 