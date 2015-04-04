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
	mBoard.SetPosition( 0, 0 );
}

void PlayScene::Exit()
{
}


void PlayScene::Update( double dt )
{
	mLineCount = 0;
	int lIndex;
	lIndex = mBoard.GetCollisionIndex( OtterVector2f( OTTER_INPUT.GetMousePosition( ) ) );
	OtterVector2f pos = mBoard.GetPosition();
	mStr[0] = std::to_wstring( lIndex );
	mStr[0] = std::to_wstring( pos.x ) + L", " + std::to_wstring( pos.y );
}

void PlayScene::Draw( HWND hwnd, HDC hdc )
{
	for( int i = 0; i <= mLineCount; ++i )
	{
		SIZE length;
		GetTextExtentPoint( hdc, mStr[0].c_str(), mStr[0].length(), &length );
		TextOut( hdc, 0, 30 * i, mStr[i].c_str(), mStr[i].length() );
	}
	mBoard.Draw( hdc );
}

void PlayScene::KeyDown( WPARAM wParam, LPARAM lParam )
{
	
}