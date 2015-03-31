#include "MenuScene.h"
#include "PlayScene.h"
#include "Win32Frame.h"
#include "InputSystem.h"

MenuScene::MenuScene( )
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
	static float speed = 100;
	if( OTTER_INPUT.GetKeyDown( 'S' ) )	
		mRect.Translate( 0, speed * dt );

	if( OTTER_INPUT.GetKeyDown( 'A' ) )	
		mRect.Translate( speed * dt, 0 );

	if( OTTER_INPUT.GetAnyKeyDown() )
	{
		WIN32FRAME.ChangeScene( new PlayScene() );
	}

	/*if( OTTER_INPUT.GetAnyKeyDown() )
		mRect.SetRect( 300, 300, 100 );
	if( OTTER_INPUT.GetAnyKeyUp() )
		mRect.SetRect( 400, 400, 100 );*/

	mStr = L"FPS::";
	mStr += std::to_wstring( dt );
	mStr += L" / ";
	mStr += std::to_wstring( mRect.GetPosition().x );
	mStr += L", ";
	mStr += std::to_wstring( mRect.GetPosition().y );
}

void MenuScene::Draw( HWND hwnd, HDC hdc )
{
	TextOut( hdc, 100, 100, mStr.c_str(), mStr.length() );
	mRect.Draw( hdc );
}


void MenuScene::KeyDown( WPARAM wParam, LPARAM lParam )
{
	
}