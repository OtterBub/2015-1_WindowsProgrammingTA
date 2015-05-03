#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__
#include "Scene.h"
#include "GDIButton.h"
#include "AnimateObject.h"

class AnimationTestScene : public Scene
{
public:
	AnimationTestScene();
	~AnimationTestScene();

	void Enter();
	void Exit();

	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

private:
	GDIButton mButton[6];
	BitmapObject mBitmap;
	AnimateObject mAnimObj;
};

#endif __MENU_SCENE_H__