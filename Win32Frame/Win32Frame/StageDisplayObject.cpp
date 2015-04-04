#include "StageDisplayObject.h"
#include "MathUtill.cpp"

StageDisplayObject::StageDisplayObject( int width, int height )
{
	mWidth = width;
	mHeight = height;
	mSize = 10;
	mRectList = new GDIRect[mWidth * mHeight];
	SetPosition( 0, 0 );
}

StageDisplayObject::StageDisplayObject( int width, int height, int size )
{
	mWidth = width;
	mHeight = height;
	mSize = size;
	mRectList = new GDIRect[mWidth * mHeight];
	SetPosition( 0, 0 );
}

StageDisplayObject::~StageDisplayObject()
{
	delete[] mRectList;
}


void StageDisplayObject::Draw( HDC hdc )
{
	int lTotal = mWidth * mHeight;

	for( int i = 0; i < lTotal; ++i )
	{
		mRectList[i].Draw( hdc );
	}
}

void StageDisplayObject::Translate( float x, float y )
{
	Object::Translate( x, y );
	SetPosition( mPosition.x, mPosition.y );
}

void StageDisplayObject::Translate( OtterVector2f trans )
{
	Object::Translate( trans );
	SetPosition( mPosition );
}

void StageDisplayObject::SetPosition( float x, float y )
{
	Object::SetPosition( x, y );

	for( int i = 0; i < mHeight; ++i )
	{
		for( int j = 0; j < mWidth; ++j )
		{
			OtterVector2f pos;
			pos.x = mPosition.x + ( mSize + ( mWidth - ( mWidth - j ) ) * mSize );
			pos.y = mPosition.y + ( mSize + ( mHeight - ( mHeight - i ) ) * mSize );
			mRectList[ ( i * mWidth ) + j ].SetRect( pos.x, pos.y, mSize );
		}
	}
}

void StageDisplayObject::SetPosition( OtterVector2f pos )
{
	Object::SetPosition( pos );

	SetPosition( pos.x, pos.y );
}

void StageDisplayObject::SetSize( int size )
{
	int lTotal = mWidth * mHeight;
	mSize = size;

	for( int i = 0; i < lTotal; ++i )
	{
		mRectList[i].SetSize( mSize );
	}
}

void StageDisplayObject::SetPostionColor( OtterVector2f pos, COLORREF color )
{
	if( ( ( pos.x * mWidth ) + pos.y ) < ( mWidth * mHeight ) ){
		int x = pos.x;
		int y = pos.y;
		mRectList[ ( x * mWidth ) + y ].SetBrush( color );
	}
}

int StageDisplayObject::GetCollisionIndex( OtterVector2f point )
{
	int lTotal = mWidth * mHeight;
	for( int i = 0; i < lTotal; ++i )
	{
		if( CollisionRectToPoint( mRectList[i].GetRect(), point ) )
			return i;
	}
	return -1;
}

int StageDisplayObject::GetCollisionIndex( OtterRect2f rect )
{
	int lTotal = mWidth * mHeight;
	for( int i = 0; i < lTotal; ++i )
	{
		if( CollisionRectToRect( mRectList[i].GetRect(), rect ) )
			return i;
	}
	return -1;
}