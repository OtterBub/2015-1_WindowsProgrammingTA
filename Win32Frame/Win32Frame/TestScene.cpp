#include "TestScene.h"
#include "PlayScene.h"
#include "Win32Frame.h"

TestScene::TestScene( Win32Frame* frame ) :
Scene( frame )
{

}

TestScene::~TestScene()
{

}


void TestScene::Enter()
{

}

void TestScene::Exit()
{

}


void TestScene::Update( double dt )
{

}

void TestScene::Draw( HWND hwnd, HDC hdc )
{
	TextOut( hdc, 0, 0, L"TestScene", wcslen(L"TestScene") );
}

void TestScene::KeyDown( WPARAM wParam, LPARAM lParam )
{
	mFrame->ChangeScene( new PlayScene( mFrame ) );
}