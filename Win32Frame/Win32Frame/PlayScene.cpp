#include "PlayScene.h"
#include "MenuScene.h"
#include "Win32Frame.h"
#include "MathUtill.cpp"

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
	mRect.SetPosition( 300, 300 );
	mRect.SetSize( 50 );
	mRect.SetBrush( RGB( 155, 155, 0 ) );
}

void PlayScene::Exit()
{
}


void PlayScene::Update( double dt )
{
	static bool lDrag = false;
	static OtterVector2i prevMousePos = OTTER_INPUT.GetMousePosition();
	int lIndex;

	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) )
	{
		if( CollisionRectToPoint( mRect.GetRect(), OTTER_INPUT.GetMousePosition( ) ) )
		{
			lDrag = true;
		}
	}
	else
		lDrag = false;

	if( lDrag )
	{
		mRect.Translate( OTTER_INPUT.GetMousePosition( ) - prevMousePos );
	}
	
	mLineCount = 0;
	lIndex = mBoard.GetCollisionIndex( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ) );

	prevMousePos = OTTER_INPUT.GetMousePosition();

	OtterVector2f pos = mBoard.GetPosition(  );
	mStr[0] = L"Index: " + std::to_wstring( lIndex ) + L" ";
	mStr[0] += std::to_wstring( pos.x ) + L", " + std::to_wstring( pos.y );
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
	mRect.Draw( hdc );
}

void PlayScene::KeyDown( WPARAM wParam, LPARAM lParam )
{
	
}