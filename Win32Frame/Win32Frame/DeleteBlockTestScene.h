#ifndef __DELETE_BLOCK_TEST_SCENE_H__
#define __DELETE_BLOCK_TEST_SCENE_H__

#include "Scene.h"
#include "GameStageObject.h"
#include "GDIRect.h"

class DeleteBlockTestScene : public Scene
{
public:
	DeleteBlockTestScene();
	~DeleteBlockTestScene();

	void Enter();
	void Exit();

	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

private:
	GameStageObject mStage;
	GDIRect mRect;
};

#endif