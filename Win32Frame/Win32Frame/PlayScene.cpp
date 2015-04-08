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
	mStage.SetBoardType( rand() % 3 );
}
void PlayScene::Exit()
{

}

void PlayScene::Update( double dt )
{
	static bool lbKeyDown = false;
	if( OTTER_INPUT.GetKeyDown( 'R' ) && ( lbKeyDown == false ) )
	{
		mStage.SetBlock( 3, 8, 50 );
	}

	mStage.Update( dt );
	lbKeyDown = OTTER_INPUT.GetAnyKeyDown();
}
void PlayScene::Draw( HWND hwnd, HDC hdc )
{
	mStage.Draw( hdc );
	TextOut( hdc, 0, 30, L"PlayScene", wcslen( L"PlayScene" ) );
}