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
	mBitmap.FileLoad( L"chara07_2.bmp" );
	mBitmap.SetPosition( 300, 300 );
	mBitmap.SetScale( 3, 3 );
	mBitmap.SetSrcSize( 32, 48 );
	mBitmap.SetDestSize( 32, 48 );
	mBitmap.SetTransparent( true, RGB( 120, 195, 128 ) );
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

	/*switch( rand() % 1 )
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
	}	*/
	
	static int count = 0;
	static int countY = 0;
	static int spriteWidth = 32, spriteHeight = 48;
	static double animTime = 0;
	//mBitmap.SetSrcRect( spriteWidth * ( count ), 0, spriteWidth * (count + 1), 53 );
	
	mBitmap.SetSrcPosition( spriteWidth * count, spriteHeight * countY );
	animTime += dt;
	if( animTime > 0.5 ) {
		animTime = 0;
		count = (count + 1) % 3;
		if( count == 0 )
			countY ++;
	}
}

void MenuScene::Draw( HWND hwnd, HDC hdc )
{
	std::wstring debug;
	
	//TextOut( hdc, WIN32FRAME.GetClientRectbyFrame().right / 2.f - 30, 30, L"2048", wcslen( L"2048" ) );

	debug = std::to_wstring( (int)mBitmap.GetPosition().x );
	debug += L", ";
	debug += std::to_wstring( (int)mBitmap.GetPosition().y );
	TextOut( hdc, 0, 0, debug.c_str(), debug.length() );

	for( int i = 0; i < 5; ++i )
		mButton[i].Draw( hdc );

	mBitmap.Draw( hdc );
}