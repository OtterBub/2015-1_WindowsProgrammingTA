#include "Win32Frame.h"
#include <ctime>

Win32Frame::Win32Frame()
{
	mCurrentScene = nullptr;
}
Win32Frame::~Win32Frame()
{
}


void Win32Frame::Initialize()
{
}

void Win32Frame::Exit()
{
}


void Win32Frame::Update( double dt )
{
	static clock_t prevTime = std::clock();
	
	if( mCurrentScene != nullptr )
		mCurrentScene->Update( (double)( std::clock() - prevTime ) / CLOCKS_PER_SEC );

	prevTime = std::clock();
}

void Win32Frame::Draw( HWND hwnd, HDC hdc )
{
	if( mCurrentScene != nullptr )
		mCurrentScene->Draw( hwnd, hdc );
}


void Win32Frame::KeyDown( WPARAM wParam, LPARAM lParam )
{
	 if( mCurrentScene != nullptr )
		mCurrentScene->KeyDown( wParam, lParam );
}

void Win32Frame::KeyUp( WPARAM wParam, LPARAM lParam )
{
	if( mCurrentScene != nullptr )
		mCurrentScene->KeyUp( wParam, lParam );
}

void Win32Frame::KeyChar( WPARAM wParam, LPARAM lParam )
{
	if( mCurrentScene != nullptr )
		mCurrentScene->KeyChar( wParam, lParam );
}

void Win32Frame::ChangeScene( Scene* scene )
{
	if( mCurrentScene != nullptr )
	{
		mCurrentScene->Exit();
		delete mCurrentScene;
		mCurrentScene = nullptr;
	}
	
	mCurrentScene = scene;
	mCurrentScene->Enter();
}