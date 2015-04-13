#ifndef __COLLISION_TEST_SCENE_H__
#define __COLLISION_TEST_SCENE_H__

#include "Scene.h"
#include "GDIRect.h"
#include "GDIButton.h"
#include <string>

class CollisionTestScene : public Scene
{
public:
	CollisionTestScene();
	~CollisionTestScene();

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
	GDIButton mButton;
};

#endif