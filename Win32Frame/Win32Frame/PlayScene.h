#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include "Scene.h"
#include "GameStageObject.h"
#include "GDIRect.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	void Enter();
	void Exit();

	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );

private:
	GameStageObject mStage;
	GDIRect mRect;
};

#endif