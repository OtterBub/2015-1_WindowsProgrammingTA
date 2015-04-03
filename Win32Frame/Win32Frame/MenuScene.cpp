#include "MenuScene.h"
#include "PlayScene.h"
#include "Win32Frame.h"
#include "InputSystem.h"
#include "StageDisplayObject.h"
#include <math.h>

MenuScene::MenuScene( )
{
}

MenuScene::~MenuScene()
{
}


void MenuScene::Enter()
{
	mRect.SetRect( 300, 300, 5 );
	
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

	if( OTTER_INPUT.GetKeyDown( 'P' ) )
		WIN32FRAME.ChangeScene( new PlayScene() );

	mStr = L"MousePos";
	mStr += std::to_wstring( OTTER_INPUT.GetMousePosition().x );
	mStr += L", ";
	mStr += std::to_wstring( OTTER_INPUT.GetMousePosition().y );

	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) )
	{
		mStr += L" / MouseLDownPos";
		mStr += std::to_wstring( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ).x );
		mStr += L", ";
		mStr += std::to_wstring( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ).y );
	}

	if( OTTER_INPUT.GetMouseUp( MOUSE_MESSAGE::MOUSE_L ) )
	{
		mStr += L" / MouseLUpPos";
		mStr += std::to_wstring( OTTER_INPUT.GetMouseUpPosition( MOUSE_MESSAGE::MOUSE_L ).x );
		mStr += L", ";
		mStr += std::to_wstring( OTTER_INPUT.GetMouseUpPosition( MOUSE_MESSAGE::MOUSE_L ).y );
	}
	
}

void MenuScene::Draw( HWND hwnd, HDC hdc )
{
	TextOut( hdc, 100, 100, mStr.c_str(), mStr.length() );
	//mRect.Draw( hdc );

	for( int i = 0; i < 360; i += ( 360 / 10.0 ) )
	{
		int x = sin( ( i ) * ( 3.14 / 180 ) ) * 50;
		int y = cos( ( i ) * ( 3.14 / 180 ) ) * 50;

		mRect.SetRect( x + 100, y + 100, 10 );
		mRect.Draw( hdc );
	}
}


void MenuScene::KeyDown( WPARAM wParam, LPARAM lParam )
{
	
}