#ifndef __MENUSCENE_H__
#define __MENUSCENE_H__

#include "Scene.h"
#include "GDIRect.h"
#include <string>

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	void Enter();
	void Exit();
	
	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

	void KeyDown( WPARAM wParam, LPARAM lParam );
	void KeyChar( WPARAM wParam, LPARAM lParam );

private:
	GDIRect mRect, mRect2;
	std::wstring mStr[5];
	int mLineCount;
};

#endif