#include "AnimateCreator.h"

AnimateCreator::AnimateCreator()
{
}

AnimateObject AnimateCreator::GetAnimObj( std::wstring objname )
{
	AnimateObject result;
	if( objname == L"CHICKEN" ) {
		result.LoadSpriteImage( L"chara07_2.bmp" );
		result.AutoCreateAnimation( L"DOWN", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 0, 4 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"LEFT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 0, 5 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"RIGHT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 0, 6 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"UP", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 0, 7 ), OtterVector2i( 3, 1 ) );
		result.SetAnimClip( L"DOWN" );
		result.SetImageSize( 32, 48 );
		//result.SetScale( 4, 4 );
		result.SetTransparent( true, RGB( 120, 195, 128 ) );
	} 
	else if( objname == L"DOVE_FLY" ) {
		result.LoadSpriteImage( L"chara07_2.bmp" );
		result.AutoCreateAnimation( L"DOWN", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 3, 0 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"LEFT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 3, 1 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"RIGHT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 3, 2 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"UP", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 3, 3 ), OtterVector2i( 3, 1 ) );
		result.SetAnimClip( L"DOWN" );
		result.SetImageSize( 32, 48 );
		//result.SetScale( 4, 4 );
		result.SetTransparent( true, RGB( 120, 195, 128 ) );
	} 
	else if( objname == L"DOVE" ) {
		result.LoadSpriteImage( L"chara07_2.bmp" );
		result.AutoCreateAnimation( L"DOWN", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 0, 0 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"LEFT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 0, 1 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"RIGHT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 0, 2 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"UP", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 0, 3 ), OtterVector2i( 3, 1 ) );
		result.SetAnimClip( L"DOWN" );
		result.SetImageSize( 32, 48 );
		//result.SetScale( 4, 4 );
		result.SetTransparent( true, RGB( 120, 195, 128 ) );
	}
	else if( objname == L"EAGLE" ) {
		result.LoadSpriteImage( L"chara07_2.bmp" );
		result.AutoCreateAnimation( L"DOWN", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 3, 4 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"LEFT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 3, 5 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"RIGHT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 3, 6 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"UP", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 3, 7 ), OtterVector2i( 3, 1 ) );
		result.SetAnimClip( L"DOWN" );
		result.SetImageSize( 32, 48 );
		//result.SetScale( 4, 4 );
		result.SetTransparent( true, RGB( 120, 195, 128 ) );
	}
	else if( objname == L"CHICK" ) {
		result.LoadSpriteImage( L"chara07_2.bmp" );
		result.AutoCreateAnimation( L"DOWN", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 9, 4 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"LEFT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 9, 5 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"RIGHT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 9, 6 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"UP", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 9, 7 ), OtterVector2i( 3, 1 ) );
		result.SetAnimClip( L"DOWN" );
		result.SetImageSize( 32, 48 );
		//result.SetScale( 4, 4 );
		result.SetTransparent( true, RGB( 120, 195, 128 ) );
	}
	else if( objname == L"SEAGULL" ) {
		result.LoadSpriteImage( L"chara07_2.bmp" );
		result.AutoCreateAnimation( L"DOWN", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 6, 0 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"LEFT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 6, 1 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"RIGHT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 6, 2 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"UP", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 6, 3 ), OtterVector2i( 3, 1 ) );
		result.SetAnimClip( L"DOWN" );
		result.SetImageSize( 32, 48 );
		//result.SetScale( 4, 4 );
		result.SetTransparent( true, RGB( 120, 195, 128 ) );
	}
	else if( objname == L"BAT" ) {
		result.LoadSpriteImage( L"chara07_2.bmp" );
		result.AutoCreateAnimation( L"DOWN", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 6, 4 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"LEFT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 6, 5 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"RIGHT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 6, 6 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"UP", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 6, 7 ), OtterVector2i( 3, 1 ) );
		result.SetAnimClip( L"DOWN" );
		result.SetImageSize( 32, 48 );
		//result.SetScale( 4, 4 );
		result.SetTransparent( true, RGB( 120, 195, 128 ) );
	}
	else if( objname == L"SWAN" ) {
		result.LoadSpriteImage( L"chara07_2.bmp" );
		result.AutoCreateAnimation( L"DOWN", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 9, 0 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"LEFT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 9, 1 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"RIGHT", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 9, 2 ), OtterVector2i( 3, 1 ) );
		result.AutoCreateAnimation( L"UP", 0.25, OtterVector2f( 32, 48 ), OtterVector2i( 9, 3 ), OtterVector2i( 3, 1 ) );
		result.SetAnimClip( L"DOWN" );
		result.SetImageSize( 32, 48 );
		//result.SetScale( 4, 4 );
		result.SetTransparent( true, RGB( 120, 195, 128 ) );
	}

	return result;
}
AnimateCreator& AnimateCreator::GetInstance()
{
	static AnimateCreator instance;
	return instance;
}