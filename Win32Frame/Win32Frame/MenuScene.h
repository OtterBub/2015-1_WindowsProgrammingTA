#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__
#include "Scene.h"
#include "GDIButton.h"

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	void Enter();
	void Exit();

	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

private:
	GDIButton mButton[6];
};

#endif __MENU_SCENE_H__