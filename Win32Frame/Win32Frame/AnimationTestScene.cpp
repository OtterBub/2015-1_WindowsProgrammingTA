#include "AnimationTestScene.h"
#include "Win32Frame.h"

AnimationTestScene::AnimationTestScene()
{
}
AnimationTestScene::~AnimationTestScene()
{
}

void AnimationTestScene::Enter()
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
	//mButton[5].SetText( L"AnimationTestScene" );

	//bmpExercising = LoadBitmap( WIN32FRAME.GetHInstance(), MAKEINTRESOURCE( IDB_MYCAHR ) );
	mBitmap.FileLoad( L"chara07_2.bmp" );
	mBitmap.SetPosition( 300, 300 );
	mBitmap.SetScale( 3, 3 );
	mBitmap.SetSrcSize( 32, 48 );
	mBitmap.SetDestSize( 32, 48 );
	mBitmap.SetTransparent( true, RGB( 120, 195, 128 ) );

	mAnimObj.LoadSpriteImage( L"chara07_2.bmp" );
	mAnimObj.AutoCreateAnimation( L"DOWN", 0.25, OtterVector2f( 32, 48 ), OtterVector2i(3, 0), OtterVector2i( 3, 1 ) );
	mAnimObj.AutoCreateAnimation( L"LEFT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i(3, 1), OtterVector2i( 3, 1 ) );
	mAnimObj.AutoCreateAnimation( L"RIGHT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i(3, 2), OtterVector2i( 3, 1 ) );
	mAnimObj.AutoCreateAnimation( L"UP", 0.25, OtterVector2f( 32, 48 ), OtterVector2i(3, 3), OtterVector2i( 3, 1 ) );
	mAnimObj.SetAnimClip( L"DOWN" );
	mAnimObj.SetPosition( 300, 300 );
	mAnimObj.SetImageSize( 32, 48 );
	mAnimObj.SetScale( 4, 4 );
	mAnimObj.SetTransparent( true, RGB( 120, 195, 128 ) );
}

void AnimationTestScene::Exit()
{
}

void AnimationTestScene::Update( double dt )
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

	if( OTTER_INPUT.GetKeyDown( 'A' ) ){
		mAnimObj.Translate( -1, 0  );
		mAnimObj.SetAnimClip( L"LEFT" );
	}
	if( OTTER_INPUT.GetKeyDown( 'D' ) ){
		mAnimObj.Translate( 1, 0  );
		mAnimObj.SetAnimClip( L"RIGHT" );
	}
	if( OTTER_INPUT.GetKeyDown( 'W' ) ){
		mAnimObj.Translate( 0, -1  );
		mAnimObj.SetAnimClip( L"UP" );
	}
	if( OTTER_INPUT.GetKeyDown( 'S' ) ){
		mAnimObj.Translate( 0, 1  );
		mAnimObj.SetAnimClip( L"DOWN" );
	}

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
		if( countY >=8 )
			countY = 0;
	}

	mAnimObj.Update( dt );
}

void AnimationTestScene::Draw( HWND hwnd, HDC hdc )
{
	std::wstring debug;
	
	//TextOut( hdc, WIN32FRAME.GetClientRectbyFrame().right / 2.f - 30, 30, L"2048", wcslen( L"2048" ) );

	debug = std::to_wstring( (int)mBitmap.GetPosition().x );
	debug += L", ";
	debug += std::to_wstring( (int)mBitmap.GetPosition().y );
	TextOut( hdc, 0, 0, debug.c_str(), debug.length() );

	mBitmap.Draw( hdc );
	mAnimObj.Draw( hdc );
}