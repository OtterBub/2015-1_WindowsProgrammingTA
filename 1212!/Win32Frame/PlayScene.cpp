#include "PlayScene.h"
#include "InputSystem.h"
#include "Win32Frame.h"
#include "MenuScene.h"

PlayScene::PlayScene() :
mStage( 12, 12, 50 )
{

}
PlayScene::~PlayScene()
{
}

void PlayScene::Enter()
{
	RECT rect = WIN32FRAME.GetClientRectbyFrame();
	float width = 150;
	float height = 50 * 0.5;
	mButton.SetRect( ( rect.right ) - width, ( 100 + ( height * 2 ) ) - height,
					 ( rect.right ), ( 100 + ( height * 2 ) ) + height );

	mButton.SetText( L"MainMenu" );

	mStage.SetBlock( 3, 8, 50 );	
	mStage.SetBoardType( rand() % 3 );
}
void PlayScene::Exit()
{

}

void PlayScene::Update( double dt )
{
	static bool lbKeyDown = false;

	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) &&
		mButton.CheckClick( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ) ))
		WIN32FRAME.ChangeScene( new MenuScene() );

	if( OTTER_INPUT.GetKeyDown( 'R' ) && ( lbKeyDown == false ) )
	{
		mStage.SetBlock( 3, 8, 50 );
	}

	mStage.Update( dt );
	lbKeyDown = OTTER_INPUT.GetAnyKeyDown();
}
void PlayScene::Draw( HWND hwnd, HDC hdc )
{
	mStage.Draw( hdc );
	TextOut( hdc, 0, 30, L"PlayScene", wcslen( L"PlayScene" ) );
	mButton.Draw( hdc );

}