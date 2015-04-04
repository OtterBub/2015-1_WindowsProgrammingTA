#include "MenuScene.h"
#include "PlayScene.h"
#include "Win32Frame.h"
#include "InputSystem.h"
#include "StageDisplayObject.h"
#include "MathUtill.cpp"
#include <math.h>

MenuScene::MenuScene( )
{
}

MenuScene::~MenuScene()
{
}


void MenuScene::Enter()
{
	mRect.SetRect( 100, 100, 200, 150 );
	
	mRect.SetBrush( RGB( 100, 0, 100 ) );
	mRect.SetPen( PS_SOLID, 1, RGB( 255, 0, 155 ) );

	mRect2.SetRect( 600, 600, 100 );
}

void MenuScene::Exit()
{
}


void MenuScene::Update( double dt )
{
	static float speed = 100;
	mLineCount = 0;
	if( OTTER_INPUT.GetKeyDown( 'S' ) )	
		mRect.Translate( 0, speed * dt );
	else if( OTTER_INPUT.GetKeyDown( 'W' ) )
		mRect.Translate( 0, -speed * dt );

	if( OTTER_INPUT.GetKeyDown( 'A' ) )	
		mRect.Translate( -speed * dt, 0 );
	else if( OTTER_INPUT.GetKeyDown( 'D' ) )
		mRect.Translate( speed * dt, 0 );

	if( OTTER_INPUT.GetKeyDown( 'P' ) )
		WIN32FRAME.ChangeScene( new PlayScene() );

	mStr[mLineCount] = std::to_wstring( dt );

	mLineCount++;
	mStr[mLineCount] = L"MousePos ";
	mStr[mLineCount] += std::to_wstring( OTTER_INPUT.GetMousePosition().x );
	mStr[mLineCount] += L", ";
	mStr[mLineCount] += std::to_wstring( OTTER_INPUT.GetMousePosition().y );

	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) )
	{
		mStr[mLineCount] += L" / MouseLDownPos ";
		mStr[mLineCount] += std::to_wstring( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ).x );
		mStr[mLineCount] += L", ";
		mStr[mLineCount] += std::to_wstring( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ).y );
	}

	if( OTTER_INPUT.GetMouseUp( MOUSE_MESSAGE::MOUSE_L ) )
	{
		mStr[mLineCount] += L" / MouseLUpPos ";
		mStr[mLineCount] += std::to_wstring( OTTER_INPUT.GetMouseUpPosition( MOUSE_MESSAGE::MOUSE_L ).x );
		mStr[mLineCount] += L", ";
		mStr[mLineCount] += std::to_wstring( OTTER_INPUT.GetMouseUpPosition( MOUSE_MESSAGE::MOUSE_L ).y );
	}

	mLineCount++;
	mStr[mLineCount] = L"MOUSE: ";

	if( CollisionRectToPoint( mRect.GetRect(), OTTER_INPUT.GetMousePosition() ) )
		mStr[mLineCount] += L"TRUE";
	else
		mStr[mLineCount] += L"FALSE";

	mStr[mLineCount] += L" COLLISION: ";

	if( CollisionRectToRect( mRect.GetRect(), mRect2.GetRect() ) )
		mStr[mLineCount] += L"TRUE";
	else
		mStr[mLineCount] += L"FALSE";
}

void MenuScene::Draw( HWND hwnd, HDC hdc )
{
	for( int i = 0; i <= mLineCount; ++i )
	{
		SIZE length;
		GetTextExtentPoint( hdc, mStr[0].c_str(), mStr[0].length(), &length );
		TextOut( hdc, 0, 30 * i, mStr[i].c_str(), mStr[i].length() );
	}

	mRect.Draw( hdc );
	mRect2.Draw( hdc );
}


void MenuScene::KeyDown( WPARAM wParam, LPARAM lParam )
{
	
}

void MenuScene::KeyChar( WPARAM wParam, LPARAM lParam )
{
}