#include "PlayScene.h"
#include "MenuScene.h"
#include "Win32Frame.h"

PlayScene::PlayScene(  ) :
mBoard( 12, 12, 50 )
{
	
}

PlayScene::~PlayScene()
{
}


void PlayScene::Enter()
{
	mBoard.SetPosition( 100, 100 );
	
}

void PlayScene::Exit()
{
}


void PlayScene::Update( double dt )
{
	
}

void PlayScene::Draw( HWND hwnd, HDC hdc )
{
	TextOut( hdc, 0, 0, L"PlayScene", wcslen(L"PlayScene") );
	mBoard.Draw( hdc );
}

void PlayScene::KeyDown( WPARAM wParam, LPARAM lParam )
{
	
}