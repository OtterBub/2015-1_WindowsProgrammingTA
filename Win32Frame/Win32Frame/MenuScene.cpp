#include "MenuScene.h"

MenuScene::MenuScene()
{
}
MenuScene::~MenuScene()
{
}

void MenuScene::Enter()
{
	mButton.SetRect( 100, 100, 500, 200 );
	mButton.SetText( L"HelloWorld" );

}
void MenuScene::Exit()
{
}

void MenuScene::Update( double dt )
{
}
void MenuScene::Draw( HWND hwnd, HDC hdc )
{
	mButton.Draw( hdc );

}