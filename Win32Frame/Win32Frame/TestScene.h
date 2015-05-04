#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__
#include "Scene.h"
#include "GameBoardObject.h"
#include <string>

class TestScene : public Scene
{
public:
	TestScene();
	~TestScene();

	void Enter();
	void Exit();

	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

private:
	GameBoardObject mBoard;
	std::wstring mDebug;
};

#endif 