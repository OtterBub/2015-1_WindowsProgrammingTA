#include "MenuScene.h"
#include "PlayScene.h"
#include "Win32Frame.h"

MenuScene::MenuScene( Win32Frame* frame ) :
Scene( frame )
{
}

MenuScene::~MenuScene()
{
}


void MenuScene::Enter()
{
	mRect.SetRect( 300, 300, 100 );
	
	mRect.SetBrush( RGB( 100, 0, 100 ) );
	mRect.SetPen( PS_SOLID, 1, RGB( 255, 0, 155 ) );
}

void MenuScene::Exit()
{
}


void MenuScene::Update( double dt )
{
}

void MenuScene::Draw( HWND hwnd, HDC hdc )
{
	TextOut( hdc, 100, 100, L"MainScene", wcslen(L"MainScene") );
	mRect.Draw( hdc );
}


void MenuScene::KeyDown( WPARAM wParam, LPARAM lParam )
{
	mFrame->ChangeScene( new PlayScene( mFrame ) );
}