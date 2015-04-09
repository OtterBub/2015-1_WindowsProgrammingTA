#include "CreateBlockTestScene.h"
#include "InputSystem.h"
#include "Win32Frame.h"
#include "MenuScene.h"

CreateBlockScene::CreateBlockScene()
{

}
CreateBlockScene::~CreateBlockScene()
{
}

void CreateBlockScene::Enter()
{
	RECT rect = WIN32FRAME.GetClientRectbyFrame();
	float width = 150;
	float height = 50 * 0.5;
	mButton.SetRect( ( rect.right ) - width, ( 100 + ( height * 2 ) ) - height,
					 ( rect.right ), ( 100 + ( height * 2 ) ) + height );

	mButton.SetText( L"MainMenu" );

	mBlock.SetBlock( 1000, 20 );
	mBlock.SetPosition( 200, 200 );
}
void CreateBlockScene::Exit()
{
}

void CreateBlockScene::Update( double dt )
{
	static bool lDrag = false;
	static OtterVector2i prevPos = OTTER_INPUT.GetMousePosition();

	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) &&
		mButton.CheckClick( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ) ))
		WIN32FRAME.ChangeScene( new MenuScene() );

	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) )
	{
		if( mBlock.CollisionCheck( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ) ) )
		{
			lDrag = true;
		}
	}
	else
		lDrag = false;

	if( lDrag )
	{
		mBlock.Translate( OTTER_INPUT.GetMousePosition() - prevPos );
	}

	prevPos = OTTER_INPUT.GetMousePosition();
}
void CreateBlockScene::Draw( HWND hwnd, HDC hdc )
{
	mBlock.Draw( hdc );
	TextOut( hdc, 0, 0, L"CreateBlockScene", wcslen( L"CreateBlockScene" ) );
	mButton.Draw( hdc );
}