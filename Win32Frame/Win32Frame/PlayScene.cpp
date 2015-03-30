#include "PlayScene.h"
#include "TestScene.h"
#include "Win32Frame.h"

PlayScene::PlayScene(  )
{
}

PlayScene::~PlayScene()
{
}


void PlayScene::Enter()
{
}

void PlayScene::Exit()
{
}


void PlayScene::Update( double dt )
{
}

void PlayScene::Draw( HWND hwnd, HDC hdc )
{
	TextOut( hdc, 0, 0, L"PlayScene", wcslen(L"PlayScene") );
}

void PlayScene::KeyDown( WPARAM wParam, LPARAM lParam )
{
	
}