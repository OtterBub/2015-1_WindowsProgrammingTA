#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__
#include "Scene.h"

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

};

#endif 