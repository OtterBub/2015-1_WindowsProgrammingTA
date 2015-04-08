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
	mStage.SetBlock( 3, 8, 50 );
	
}
void PlayScene::Exit()
{

}

void PlayScene::Update( double dt )
{
	if( OTTER_INPUT.GetKeyDown( 'R' ) )
	{
		mStage.SetBlock( 3, 8, 50 );
	}

	mStage.Update( dt );
}
void PlayScene::Draw( HWND hwnd, HDC hdc )
{
	mStage.Draw( hdc );
	TextOut( hdc, 0, 30, L"PlayScene", wcslen( L"PlayScene" ) );
}