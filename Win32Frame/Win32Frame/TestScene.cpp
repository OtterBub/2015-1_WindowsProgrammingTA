#include "TestScene.h"
#include "InputSystem.h"
#include "Win32Frame.h"

TestScene::TestScene()
{
}
TestScene::~TestScene()
{
}

void TestScene::Enter()
{
	mBoard.SetBoardSize( 4, 4 );
	mBoard.SetRectSize( 150, 150 );
	mBoard.SetPosition( 20, 20 );
	mBoard.RandGeneratorBlock();
}
void TestScene::Exit()
{
}

void TestScene::Update( double dt )
{
	static bool lKeyDown = false;
	static bool debug = true;
	if( OTTER_INPUT.GetKeyDown( 'S' ) && ( lKeyDown == false ) ) {
		mBoard.CommandSlide( GameSlideDir::DOWN );
		lKeyDown = true;
	} else if( OTTER_INPUT.GetKeyDown( 'W' ) && ( lKeyDown == false ) ) {
		mBoard.CommandSlide( GameSlideDir::UP );
		lKeyDown = true;
	} else if( OTTER_INPUT.GetKeyDown( 'A' ) && ( lKeyDown == false ) ) {	
		mBoard.CommandSlide( GameSlideDir::LEFT );
		lKeyDown = true;
	} else if( OTTER_INPUT.GetKeyDown( 'D' ) && ( lKeyDown == false ) ) {
		mBoard.CommandSlide( GameSlideDir::RIGHT );
		lKeyDown = true;
	} else if( OTTER_INPUT.GetKeyDown( 'B' ) && ( lKeyDown == false ) ) {
		debug = !debug;
		WIN32FRAME.SetDebugMode( debug );
		mBoard.SetDebugMode( debug );
		lKeyDown = true;
	}

	if( !OTTER_INPUT.GetAnyKeyDown() ) {
		lKeyDown = false;
	}	

	mBoard.Update( dt );
}
void TestScene::Draw( HWND hwnd, HDC hdc )
{
	mBoard.Draw( hdc );
}