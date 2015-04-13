#include "PlaceRectTestScene.h"
#include "CollisionTestScene.h"
#include "Win32Frame.h"
#include "MathUtill.cpp"
#include "MenuScene.h"

PlaceRectTestScene::PlaceRectTestScene(  ) :
mBoard( 12, 12, 50 )
{
	
}

PlaceRectTestScene::~PlaceRectTestScene()
{
}


void PlaceRectTestScene::Enter()
{
	RECT rect = WIN32FRAME.GetClientRectbyFrame();
	float width = 150;
	float height = 50 * 0.5;
	mButton.SetRect( ( rect.right ) - width, ( 100 + ( height * 2 ) ) - height,
					 ( rect.right ), ( 100 + ( height * 2 ) ) + height );

	mButton.SetText( L"MainMenu" );

	mBoard.SetPosition( 0, 50 );
	mRect.SetPosition( 800, 300 );
	mRect.SetSize( 50 );
	mRect.SetBrush( RGB( 155, 155, 0 ) );
}

void PlaceRectTestScene::Exit()
{
}


void PlaceRectTestScene::Update( double dt )
{
	static bool lDrag = false;
	static OtterVector2i prevMousePos = OTTER_INPUT.GetMousePosition();
	int lIndex = 0;
	int lIndexList = 0;

	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) &&
		mButton.CheckClick( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ) ))
		WIN32FRAME.ChangeScene( new MenuScene() );


	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) )
	{
		if( CollisionRectToPoint( mRect.GetRect(), OTTER_INPUT.GetMousePosition( ) ) )
		{
			lDrag = true;
		}
		lIndex = mBoard.GetCollisionIndex( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ) );
		if( ( lIndex >= 0 ) && ( lDrag == false ) )
		{
			mBoard.SetIndexColor( lIndex, RGB( 255, 255, 255 ) );
		}
	}
	else
		lDrag = false;

	if( lDrag )
	{
		mRect.Translate( OTTER_INPUT.GetMousePosition( ) - prevMousePos );
	}
	
	mLineCount = 0;
	

	lIndexList = mBoard.GetCollisionIndex( mRect.GetRect() );
	if( lIndexList > 0 )
	{
		mBoard.SetIndexColor( lIndexList, RGB( 0, 0, 125 ) );
	}

	prevMousePos = OTTER_INPUT.GetMousePosition();

	OtterVector2f pos = mBoard.GetPosition(  );
	mStr[0] = L"Index: " + std::to_wstring( lIndex ) + L" ";
	mStr[0] += std::to_wstring( pos.x ) + L", " + std::to_wstring( pos.y ) + L" / ";
	mStr[0] += L"RectToRect Index: ";
	mStr[0] += std::to_wstring(lIndexList) + L" ";
	
}

void PlaceRectTestScene::Draw( HWND hwnd, HDC hdc )
{
	mBoard.Draw( hdc );
	mRect.Draw( hdc );
	TextOut( hdc, 0, 0, L"PlaceRectTestScene", wcslen( L"PlaceRectTestScene" ) );
	for( int i = 0; i <= mLineCount; ++i )
	{
		SIZE length;
		GetTextExtentPoint( hdc, mStr[0].c_str(), mStr[0].length(), &length );
		TextOut( hdc, 0, 30 * (i + 1), mStr[i].c_str(), mStr[i].length() );
	}
	mButton.Draw( hdc );
}

void PlaceRectTestScene::KeyDown( WPARAM wParam, LPARAM lParam )
{
	
}