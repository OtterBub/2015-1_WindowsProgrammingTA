#include "CreateBlockTestScene.h"
#include "InputSystem.h"

CreateBlockScene::CreateBlockScene()
{

}
CreateBlockScene::~CreateBlockScene()
{
}

void CreateBlockScene::Enter()
{
	mBlock.SetBlock( 1000, 50 );
	mBlock.SetPosition( 200, 200 );
}
void CreateBlockScene::Exit()
{
}

void CreateBlockScene::Update( double dt )
{
	static bool lDrag = false;
	static OtterVector2i prevPos = OTTER_INPUT.GetMousePosition();
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
}