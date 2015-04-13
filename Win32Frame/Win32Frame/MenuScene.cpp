#include "MenuScene.h"
#include "Win32Frame.h"

MenuScene::MenuScene()
{
}
MenuScene::~MenuScene()
{
}

void MenuScene::Enter()
{
	RECT rect = WIN32FRAME.GetClientRectbyFrame();
	float width = 150 * 0.5;
	float height = 50 * 0.5;
	for( int i = 0; i < 5; ++i )
	{
		mButton[i].SetRect( ( rect.right * 0.5 ) - width, ( 150 + ( i * height * 2 ) ) - height,
							( rect.right * 0.5 ) + width, ( 150 + ( i * height * 2 ) ) + height);
	}

	mButton[0].SetText( L"CollisiontTest" );
	mButton[1].SetText( L"PlaceRectTest" );
	mButton[2].SetText( L"DeleteBlockTest" );
	mButton[3].SetText( L"CreateBlockTest" );
	mButton[4].SetText( L"Play" );
	//mButton[5].SetText( L"MenuScene" );
}
void MenuScene::Exit()
{
}

void MenuScene::Update( double dt )
{
	int clickIndex = -1;
	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) )
	{
		for( int i = 0; i < 5; ++i )
		{
			if( mButton[i].CheckClick( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ) ) )
				clickIndex = i;
		}
	}

	switch( clickIndex )
	{
		case 0:
			break;
		default:
			break;
	}

}
void MenuScene::Draw( HWND hwnd, HDC hdc )
{
	TextOut( hdc, WIN32FRAME.GetClientRectbyFrame().right / 2.f - 30, 30, L"1212!", wcslen( L"1212!" ) );

	for( int i = 0; i < 5; ++i )
		mButton[i].Draw( hdc );
}