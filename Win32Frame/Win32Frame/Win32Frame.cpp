#include "Win32Frame.h"
#include "AnimationTestScene.h"
#include "TestScene.h"
#include <ctime>

Win32Frame::Win32Frame()
{
	mCurrentScene = nullptr;
	mChangeScene = nullptr;
}
Win32Frame::~Win32Frame()
{
}

Win32Frame& Win32Frame::GetInstance()
{
	static Win32Frame instance;
	return instance;
}

void Win32Frame::Initialize( HINSTANCE hInst )
{
	mhInstance = hInst;
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
	static bool lbKeyDown = false;	
	
	if( mCurrentScene != nullptr )
		mCurrentScene->Update( (double)( std::clock() - prevTime ) / CLOCKS_PER_SEC );

	ChangeScene();
	prevTime = std::clock();


	// Change Scene for debug	
	if( lbKeyDown == false )
	{
		if( OTTER_INPUT.GetKeyDown( '1' ) )
			WIN32FRAME.ChangeScene( new AnimationTestScene() );
		else if( OTTER_INPUT.GetKeyDown( '2' ) )
			WIN32FRAME.ChangeScene( new TestScene() );
	}

	lbKeyDown = OTTER_INPUT.GetAnyKeyDown();
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
	mChangeScene = scene;
}

void Win32Frame::SethWnd( HWND hwnd )
{
	mhwnd = hwnd;
	GetClientRect( hwnd, &mClientRect );
}

RECT Win32Frame::GetClientRectbyFrame()
{
	return mClientRect;
}

HINSTANCE Win32Frame::GetHInstance()
{
	return mhInstance;
}

void Win32Frame::ChangeScene()
{
	if( mChangeScene != nullptr )
	{
		if( mCurrentScene != nullptr )
		{
			mCurrentScene->Exit();
			delete mCurrentScene;
			mCurrentScene = nullptr;
		}
		mCurrentScene = mChangeScene;
		mChangeScene = nullptr;
		mCurrentScene->Enter();
	}
}