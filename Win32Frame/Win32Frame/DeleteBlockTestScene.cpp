#include "DeleteBlockTestScene.h"
#include "InputSystem.h"
#include "MathUtill.h"

DeleteBlockTestScene::DeleteBlockTestScene() :
mStage( 12, 12, 50 )
{
}
DeleteBlockTestScene::~DeleteBlockTestScene()
{
}

void DeleteBlockTestScene::Enter()
{
	mRect.SetPosition( 300, 300 );
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
}