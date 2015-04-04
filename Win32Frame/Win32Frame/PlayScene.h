#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include "Scene.h"
#include "StageDisplayObject.h"
#include <string>

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	void Enter();
	void Exit();
	
	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

	void KeyDown( WPARAM wParam, LPARAM lParam );

private:
	StageDisplayObject mBoard;
	std::wstring mStr[5];
	int mLineCount;
};

#endif 