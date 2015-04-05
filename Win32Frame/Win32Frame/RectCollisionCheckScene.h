#ifndef __RECT_COLLISION_CHECK_SCENE_H__
#define __RECT_COLLISION_CHECK_SCENE_H__

#include "Scene.h"
#include "StageDisplayObject.h"
#include <string>

class RectCollisionCheckScene : public Scene
{
public:
	RectCollisionCheckScene();
	~RectCollisionCheckScene();

	void Enter();
	void Exit();
	
	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

	void KeyDown( WPARAM wParam, LPARAM lParam );

private:
	StageDisplayObject mBoard;
	GDIRect mRect;
	std::wstring mStr[5];
	int mLineCount;
};

#endif 