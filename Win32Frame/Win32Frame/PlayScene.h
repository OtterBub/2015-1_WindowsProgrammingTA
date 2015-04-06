#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "Scene.h"
#include "GameStageObject.h"

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
};

#endif __PLAY_SCENE_H__