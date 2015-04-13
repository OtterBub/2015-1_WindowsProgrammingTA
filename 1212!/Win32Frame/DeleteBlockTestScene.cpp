#include "DeleteBlockTestScene.h"
#include "InputSystem.h"
#include "MathUtill.h"
#include "MenuScene.h"
#include "Win32Frame.h"

DeleteBlockTestScene::DeleteBlockTestScene() :
mStage( 12, 12, 50 )
{
}
DeleteBlockTestScene::~DeleteBlockTestScene()
{
}

void DeleteBlockTestScene::Enter()
{
	RECT rect = WIN32FRAME.GetClientRectbyFrame();
	float width = 150;
	float height = 50 * 0.5;
	mButton.SetRect( ( rect.right ) - width, ( 100 + ( height * 2 ) ) - height,
					 ( rect.right ), ( 100 + ( height * 2 ) ) + height );

	mButton.SetText( L"MainMenu" );

	mRect.SetPosition( 800, 300 );
	mRect.SetSize( 50 );
	mRect.SetBrush( RGB( 0, 255, 255 ) );
}
void DeleteBlockTestScene::Exit()
{

}

void DeleteBlockTestScene::Update( double dt )
{
	static bool lDrag = false;
	static OtterVector2f prevPos = OTTER_INPUT.GetMousePosition();

	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) &&
		mButton.CheckClick( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ) ))
		WIN32FRAME.ChangeScene( new MenuScene() );

	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) )
	{
		
		if( CollisionRectToPoint( mRect.GetRect(), OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ) ) )
		{
			lDrag = true;
		}
	}
	else
		lDrag = false;

	if( lDrag )
		mRect.Translate( OTTER_INPUT.GetMousePosition() - prevPos );

	mStage.BlockCheck( mRect.GetRect(), mRect.GetBrushColor() );

	mStage.Update( dt );
	prevPos = OTTER_INPUT.GetMousePosition();
}
void DeleteBlockTestScene::Draw( HWND hwnd, HDC hdc )
{
	mStage.Draw( hdc );
	mRect.Draw( hdc );
	TextOut( hdc, 0, 0, L"DeleteBlockTestScene", wcslen( L"DeleteBlockTestScene" ) );
	mButton.Draw( hdc );
}