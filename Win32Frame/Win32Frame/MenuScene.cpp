#include "MenuScene.h"
#include "Win32Frame.h"

MenuScene::MenuScene()
{
}
MenuScene::~MenuScene()
{
}

void MenuScene::Enter()
{
	RECT rect = WIN32FRAME.GetClientRectbyFrame();
	float width = 150 * 0.5;
	float height = 50 * 0.5;
	for( int i = 0; i < 5; ++i )
	{
		mButton[i].SetRect( ( rect.right * 0.5 ) - width, ( 150 + ( i * height * 2 ) ) - height,
							( rect.right * 0.5 ) + width, ( 150 + ( i * height * 2 ) ) + height);
	}

	mButton[0].SetText( L"CollisiontTest" );
	mButton[1].SetText( L"PlaceRectTest" );
	mButton[2].SetText( L"DeleteBlockTest" );
	mButton[3].SetText( L"CreateBlockTest" );
	mButton[4].SetText( L"Play" );
	//mButton[5].SetText( L"MenuScene" );

	//bmpExercising = LoadBitmap( WIN32FRAME.GetHInstance(), MAKEINTRESOURCE( IDB_MYCAHR ) );
	mBitmap.FileLoad( L"snapshot.bmp" );
	mBitmap.SetPosition( 300, 300 );
}

void MenuScene::Exit()
{
}

void MenuScene::Update( double dt )
{
	int clickIndex = -1;
	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) )
	{
		for( int i = 0; i < 5; ++i )
		{
			if( mButton[i].CheckClick( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ) ) )
				clickIndex = i;
		}
	}

	switch( clickIndex )
	{
		case 0:
			break;
		default:
			break;
	}

	if( OTTER_INPUT.GetKeyDown( 'A' ) )
		mBitmap.Translate( -1, 0  );
	if( OTTER_INPUT.GetKeyDown( 'D' ) )
		mBitmap.Translate( 1, 0  );
	if( OTTER_INPUT.GetKeyDown( 'W' ) )
		mBitmap.Translate( 0, -1  );
	if( OTTER_INPUT.GetKeyDown( 'S' ) )
		mBitmap.Translate( 0, 1  );

	switch( rand() % 1 )
	{
		case 0:
			mBitmap.FileLoad(L"snapshot.bmp");
			break;
		case 1:
			mBitmap.FileLoad(L"snapshot2.bmp");
			break;
		case 2:
			mBitmap.FileLoad(L"snapshot3.bmp");
			break;
		default:
			break;
	}	
}

void MenuScene::Draw( HWND hwnd, HDC hdc )
{
	std::wstring debug;
	mBitmap.Draw( hdc );
	//TextOut( hdc, WIN32FRAME.GetClientRectbyFrame().right / 2.f - 30, 30, L"2048", wcslen( L"2048" ) );

	debug = std::to_wstring( (int)mBitmap.GetPosition().x );
	debug += L", ";
	debug += std::to_wstring( (int)mBitmap.GetPosition().y );
	TextOut( hdc, 0, 0, debug.c_str(), debug.length() );

	for( int i = 0; i < 5; ++i )
		mButton[i].Draw( hdc );
}