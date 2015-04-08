#include "StageDisplayObject.h"
#include "MathUtill.cpp"

StageDisplayObject::StageDisplayObject( int width, int height )
{
	mWidth = width;
	mHeight = height;
	mSize = 10;
	mTotal = mWidth * mHeight;
	mBoardType = BOARD_TYPE::DEFAULT;
	mRectList = new GDIRect[mWidth * mHeight];
	mIgnoreIndex = new bool[mTotal];
	memset( mIgnoreIndex, 0, sizeof( bool ) * mTotal );
	mDefaultColor = RGB( 255, 255, 255 );
	SetPosition( 0, 0 );
}

StageDisplayObject::StageDisplayObject( int width, int height, int size )
{
	mWidth = width;
	mHeight = height;
	mSize = size;
	mTotal = mWidth * mHeight;
	mBoardType = BOARD_TYPE::DEFAULT;
	mRectList = new GDIRect[mWidth * mHeight];
	mIgnoreIndex = new bool[mTotal];
	memset( mIgnoreIndex, 0, sizeof( bool ) * mTotal );
	mDefaultColor = RGB( 255, 255, 255 );
	SetPosition( 0, 0 );
}

StageDisplayObject::~StageDisplayObject()
{
	delete[] mRectList;
	delete[] mIgnoreIndex;
}

void StageDisplayObject::Update( float dt )
{

}

void StageDisplayObject::Draw( HDC hdc )
{
	for( int i = 0; i < mTotal; ++i )
	{
		if( mIgnoreIndex[i] )
			continue;

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
			mRectList[( i * mWidth ) + j].SetRect( pos.x, pos.y, mSize );
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
	mSize = size;

	for( int i = 0; i < mTotal; ++i )
	{
		mRectList[i].SetSize( mSize );
	}
}

void StageDisplayObject::SetIndexColor( int index, COLORREF color )
{
	if( index < mWidth * mHeight )
	{
		mRectList[index].SetBrush( color );
	}
}

void StageDisplayObject::SetPositionColor( OtterVector2f pos, COLORREF color )
{
	if( ( ( pos.x * mWidth ) + pos.y ) < ( mWidth * mHeight ) ){
		int x = pos.x;
		int y = pos.y;
		mRectList[x + ( y * mWidth )].SetBrush( color );
	}
}

void StageDisplayObject::SetBoardType( int type )
{
	switch( type )
	{
		case BOARD_TYPE::CORNER:
		{
			for( int y = 0; y < mHeight; ++y )
			{
				for( int x = 0; x < mWidth; ++x )
				{
					if( ( mWidth / 2.f >= x ) && ( mHeight / 2.f <= y ) )
					{
						mIgnoreIndex[x + ( y * mWidth )] = true;
					}
				}
			}
		}
		break;

		case BOARD_TYPE::BLANK:
		{
			for( int y = 0; y < mHeight; ++y )
			{
				for( int x = 0; x < mWidth; ++x )
				{
					if( ( mWidth / 4.f <= x ) && ( mHeight / 4.f <= y ) &&
						( mWidth * ( 3 / 4.f ) > x ) && ( mHeight * ( 3 / 4.f ) > y ) )
					{
						mIgnoreIndex[x + ( y * mWidth )] = true;
					}
				}
			}
		}
		break;

		default:
			for( int i = 0; i < mTotal; ++i )
				mIgnoreIndex[i] = false;
			break;
	}

}

void StageDisplayObject::SetAddBody( Vec2 addForce )
{
	for( int i = 0; i < mTotal; ++i )
	{
		if( mIgnoreIndex[i] )
			continue;

		mRectList[i].SetAddBody( addForce );
	}
}

int StageDisplayObject::GetCollisionIndex( OtterVector2f point )
{
	for( int i = 0; i < mTotal; ++i )
	{
		if( CollisionRectToPoint( mRectList[i].GetRect(), point ) )
			return i;
	}
	return -1;
}

int StageDisplayObject::GetCollisionIndex( OtterRect2f rect )
{
	int result = -1;
	std::vector< int > Indexes = GetCollisionIndexes( rect );
	OtterVector2f pos;
	float dist = FLT_MAX;
	pos.x = ( rect.point[0].x + rect.point[1].x ) / 2.f;
	pos.y = ( rect.point[0].y + rect.point[1].y ) / 2.f;

	for( int i : Indexes )
	{
		float vectorLength = ( pos - mRectList[i].GetPosition() ).GetLength();
		if( dist > vectorLength )
		{
			dist = vectorLength;
			result = i;
		}
	}

	return result;
}

int StageDisplayObject::GetTotal()
{
	return mTotal;
}

bool* StageDisplayObject::GetIgnoreList()
{
	bool* result = new bool[mTotal];
	memcpy( result, mIgnoreIndex, sizeof( bool ) * mTotal );


	return result;
}

GDIRect* StageDisplayObject::GetRectList()
{
	if( mTotal == 0 )
		return 0;

	GDIRect* result = new GDIRect[mTotal];

	for( int i = 0; i < mTotal; ++i )
	{
		result[i] = mRectList[i];
	}

	return result;
}

std::vector< int > StageDisplayObject::GetCollisionIndexes( OtterRect2f rect )
{
	std::vector< int > result;
	for( int i = 0; i < mTotal; ++i )
	{
		if( CollisionRectToRect( mRectList[i].GetRect(), rect ) )
			result.push_back( i );
	}
	return result;
}

COLORREF StageDisplayObject::GetColorRef( int index )
{
	return mRectList[index].GetBrushColor();
}

COLORREF StageDisplayObject::GetColorRef( int x, int y )
{
	return mRectList[x + ( y * mWidth )].GetBrushColor();
}

COLORREF StageDisplayObject::GetColorRef( OtterVector2f index )
{
	return GetColorRef( index.x + ( index.y * mWidth ) );
}