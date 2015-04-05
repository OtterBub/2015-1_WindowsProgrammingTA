#include "PlayScene.h"
#include "InputSystem.h"

PlayScene::PlayScene() :
mStage( 12, 12, 50 )
{
}
PlayScene::~PlayScene()
{
}

void PlayScene::Enter()
{
	mRect.SetPosition( 300, 300 );
	mRect.SetSize( 50 );

}
void PlayScene::Exit()
{

}

void PlayScene::Update( double dt )
{
	static bool lDrag = false;
	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) )
	{
		
		/*if( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ) )
		{

		}*/
	}


	mStage.Update( dt );
}
void PlayScene::Draw( HWND hwnd, HDC hdc )
{
	mStage.Draw( hdc );
}