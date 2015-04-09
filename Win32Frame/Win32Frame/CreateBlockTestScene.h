#ifndef __CREATE_BLOCK_TEST_SCENE_H__
#define __CREATE_BLOCK_TEST_SCENE_H__

#include "Scene.h"
#include "BlockObject.h"
#include "GDIButton.h"

class CreateBlockScene : public Scene
{
public:
	CreateBlockScene();
	~CreateBlockScene();

	void Enter();
	void Exit();

	void Update( double dt );
	void Draw( HWND hwnd, HDC hdc );


private:
	BlockObject mBlock;
	GDIButton mButton;
};

#endif __CREATE_BLOCK_TEST_SCENE_H__