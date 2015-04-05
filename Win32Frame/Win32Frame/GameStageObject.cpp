#include "GameStageObject.h"

GameStageObject::GameStageObject( int width, int height ) :
mDisplayObject( width, height )
{
	mWidth = width, mHeight = height;

	mBlockCheck = false;
	mDefaultColor = RGB( 255, 255, 255 );
}
GameStageObject::GameStageObject( int width, int height, int size ) :
mDisplayObject( width, height, size )
{
	mWidth = width, mHeight = height;
	mBlockCheck = false;
	mDefaultColor = RGB( 255, 255, 255 );
}
GameStageObject::~GameStageObject()
{
}

void GameStageObject::Update( float dt )
{
	if( mBlockCheck )
	{
		mBlockCheck = false;
		DeleteBlockCheck();
	}
}
void GameStageObject::Draw( HDC hdc )
{
	mDisplayObject.Draw( hdc );
}

void GameStageObject::Translate( float x, float y )
{
	Object::Translate( x, y );
}
void GameStageObject::Translate( OtterVector2f trans )
{
	Object::Translate( trans );
}
void GameStageObject::SetPosition( float x, float y )
{
	Object::SetPosition( x, y );
}
void GameStageObject::SetPosition( OtterVector2f pos )
{
	Object::SetPosition( pos );
}

void GameStageObject::SetDefaultColor( COLORREF color )
{
	mDefaultColor = color;
}

void GameStageObject::BlockCheck( OtterRect2f rect, COLORREF color )
{
	int lIndex = mDisplayObject.GetCollisionIndex( rect );
	if( lIndex != -1 )
	{
		mDisplayObject.SetIndexColor( lIndex, color );
		mBlockCheck = true;
	}
}

void GameStageObject::DeleteBlockCheck()
{
	int widthCount = 0;
	int *heightCount = new int[mHeight];
	memset( heightCount, 0, sizeof( int )* mHeight );

	for( int i = 0; i < mHeight; ++i )
	{
		for( int j = 0; j < mWidth; ++j ) 
		{
			if( mDisplayObject.GetColorRef( j, i ) != mDefaultColor )
			{
				widthCount++;
				heightCount[j]++;
			}
			if( widthCount == mWidth )
			{
				DeleteBlockLine( i, LINE::HORIZONTAL );
				widthCount = 0;
			}
		}
		widthCount = 0;
	}

	for( int i = 0; i < mHeight; ++i )
	{
		if( heightCount[i] == mHeight )
		{
			DeleteBlockLine( i, LINE::VERTICAL );
		}
	}

	delete[] heightCount;
}

void GameStageObject::DeleteBlockLine( int line, LINE vh )
{
	if( vh == LINE::VERTICAL )
	{
		for( int i = 0; i < mHeight; ++i )
		{
			mDisplayObject.SetPositionColor( OtterVector2i( line, i ), mDefaultColor );
		}
	}
	else if( vh == LINE::HORIZONTAL )
	{
		for( int i = 0; i < mWidth; ++i )
		{
			mDisplayObject.SetPositionColor( OtterVector2i( i, line ), mDefaultColor );
		}
	}
}