#include "PlayScene.h"

PlayScene::PlayScene() :
mStage( 12, 12, 50 )
{
}
PlayScene::~PlayScene()
{
}

void PlayScene::Enter()
{
}
void PlayScene::Exit()
{
}

void PlayScene::Update( double dt )
{
}
void PlayScene::Draw( HWND hwnd, HDC hdc )
{
	mStage.Draw( hdc );
}