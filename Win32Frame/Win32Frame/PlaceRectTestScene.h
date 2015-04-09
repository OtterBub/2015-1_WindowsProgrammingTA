#ifndef __RECT_PLACE_TEST_SCENE_H__
#define __RECT_PLACE_TEST_SCENE_H__

#include "Scene.h"
#include "StageDisplayObject.h"
#include <string>
#include "GDIButton.h"

class PlaceRectTestScene : public Scene
{
public:
	PlaceRectTestScene();
	~PlaceRectTestScene();

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
	GDIButton mButton;
};

#endif 