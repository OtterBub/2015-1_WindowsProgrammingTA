#include "PlayScene.h"
#include "InputSystem.h"

PlayScene::PlayScene() :
mStage( 12, 12, 50 )
{

}
PlayScene::~PlayScene()
{
}

void PlayScene::Enter()
{
	mStage.SetBlock( 3, 4, 50 );
	
}
void PlayScene::Exit()
{

}

void PlayScene::Update( double dt )
{
	mStage.Update( dt );
}
void PlayScene::Draw( HWND hwnd, HDC hdc )
{
	mStage.Draw( hdc );
}