#include "Win32Frame.h"
#include "MenuScene.h"
#include "CollisionTestScene.h"
#include "PlaceRectTestScene.h"
#include "DeleteBlockTestScene.h"
#include "CreateBlockTestScene.h"
#include "PlayScene.h"
#include <ctime>

Win32Frame::Win32Frame() :
mWorld( Vec2( 0.0f, 1000.0f ), 10 )
{
	WIN32FRAME.GetBodyList()[GROUND_BODY].Set( Vec2( 1280, 30 ), FLT_MAX );
	WIN32FRAME.GetBodyList()[GROUND_BODY].position.Set( 1280 / 2.f, 800 );
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

World& Win32Frame::GetWorldInstance()
{
	return mWorld;
}

Body* Win32Frame::GetBodyList()
{
	return mBody;
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

	WIN32FRAME.GetWorldInstance().Step( (double)( std::clock() - prevTime ) / CLOCKS_PER_SEC );
	
	if( mCurrentScene != nullptr )
		mCurrentScene->Update( (double)( std::clock() - prevTime ) / CLOCKS_PER_SEC );

	if( mChangeScene != nullptr )
	{
		if( mCurrentScene != nullptr )
		{
			mCurrentScene->Exit();
			mWorld.Clear();
			delete mCurrentScene;
			mCurrentScene = nullptr;
		}
		mCurrentScene = mChangeScene;
		mChangeScene = nullptr;
		mCurrentScene->Enter();
	}

	prevTime = std::clock();


	//for debug	
	if( lbKeyDown == false )
	{
		if( OTTER_INPUT.GetKeyDown( '1' ) )
			WIN32FRAME.ChangeScene( new MenuScene() );
		if( OTTER_INPUT.GetKeyDown( '2' ) )
			WIN32FRAME.ChangeScene( new CollisionTestScene() );
		if( OTTER_INPUT.GetKeyDown( '3' ) )
			WIN32FRAME.ChangeScene( new PlaceRectTestScene() );
		if( OTTER_INPUT.GetKeyDown( '4' ) )
			WIN32FRAME.ChangeScene( new DeleteBlockTestScene() );
		if( OTTER_INPUT.GetKeyDown( '5' ) )
			WIN32FRAME.ChangeScene( new CreateBlockScene() );
		if( OTTER_INPUT.GetKeyDown( '6' ) )
			WIN32FRAME.ChangeScene( new PlayScene() );
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
	WIN32FRAME.GetBodyList()[GROUND_BODY].position.Set( mClientRect.right / 2.f, mClientRect.bottom + 15 );
}

RECT Win32Frame::GetClientRectbyFrame()
{
	return mClientRect;
}