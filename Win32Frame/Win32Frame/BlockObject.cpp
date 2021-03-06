#include "BlockObject.h"
#include "MathUtill.cpp"
#include <algorithm>

BlockObject::BlockObject()
{
	mDirList = nullptr;
	mIsUsed = false;
	mBlockCount = 0;
	mSize = 50;
}
BlockObject::BlockObject( const BlockObject& other )
{
	/*std::copy( other.mDirList, other.mDirList + other.mBlockCount, this->mDirList );
	this->mBlockCount = other.mBlockCount;
	this->mSize = other.mSize;
	this->mIsUsed = other.mIsUsed;
	this->mRectListvec = other.mRectListvec;
	this->mPosition = other.mPosition;*/
	//*this = other;
}


BlockObject::BlockObject( int blockCount, int size )
{
	if( blockCount <= 0 )
	{
		blockCount = 1;
	}
	mIsUsed = false;
	mRectListvec.resize( blockCount );
	mDirList = new int[blockCount];
	mBlockCount = blockCount;
	mSize = size;
	CreateBlock();
}

BlockObject::~BlockObject()
{
	if( mDirList != nullptr )
		delete[] mDirList;
}

void BlockObject::Update( float dt )
{
}
void BlockObject::Draw( HDC hdc )
{
	for( int i = 0; i < mBlockCount; ++i )
		mRectListvec[i].Draw( hdc );

	/*int size = 5;
	SelectObject( hdc, (HBRUSH)GetStockObject( BLACK_BRUSH ) );
	Rectangle( hdc, mPosition.x - size, mPosition.y - size, mPosition.x + size, mPosition.y + size );*/
}

void BlockObject::Translate( float x, float y )
{
	Object::Translate( x, y );
	
	for( int i = 0; i < mBlockCount; ++i )
		mRectListvec[i].Translate( x, y );
}
void BlockObject::Translate( OtterVector2f trans )
{
	Object::Translate( trans );

	for( int i = 0; i < mBlockCount; ++i )
		mRectListvec[i].Translate( trans );
}
void BlockObject::SetPosition( float x, float y )
{
	Object::SetPosition( x, y );
	mRectListvec[0].SetPosition( x, y );
	OtterVector2f prevPos = mRectListvec[0].GetPosition();
	OtterVector2f MaxPos = prevPos;
	OtterVector2f trans = OtterVector2f();
	for( int i = 1; i < mBlockCount; ++i )
	{
		mRectListvec[i].SetPosition( prevPos + GetRandPosition( mDirList[i] ) );
		prevPos = mRectListvec[i].GetPosition();

		if( ( MaxPos.x < prevPos.x ) || ( MaxPos.y < prevPos.y ) )
			MaxPos = prevPos;
	}
	
	trans = mPosition - MaxPos;
	for( int i = 0; i < mBlockCount; ++i )
		mRectListvec[i].Translate( trans );

}
void BlockObject::SetPosition( OtterVector2f pos )
{
	Object::SetPosition( pos );
	mRectListvec[0].SetPosition( pos );
	OtterVector2f prevPos = mRectListvec[0].GetPosition();
	OtterVector2f MaxPos = prevPos;
	OtterVector2f trans = OtterVector2f();

	for( int i = 1; i < mBlockCount; ++i )
	{
		mRectListvec[i].SetPosition( prevPos + GetRandPosition( mDirList[i] ) );
		prevPos = mRectListvec[i].GetPosition();

		if( ( MaxPos.x < prevPos.x ) || ( MaxPos.y < prevPos.y ) )
			MaxPos = prevPos;
	}
	
	trans = mPosition - MaxPos;
	for( int i = 0; i < mBlockCount; ++i )
		mRectListvec[i].Translate( trans );
}

void BlockObject::SetBlock( int blockCount, int size )
{
	if( blockCount <= 0 )
	{
		blockCount = 1;
	}
	mRectListvec.resize( blockCount );
	if( mDirList != nullptr )
		delete[] mDirList;
	mDirList = new int[blockCount];
	mBlockCount = blockCount;
	mSize = size;
	CreateBlock();
}

void BlockObject::SetColor( COLORREF color )
{
	for( int i = 0; i < mBlockCount; ++i )
	{
		mRectListvec[i].SetBrush( color );
	}
}

void BlockObject::SetUsed( bool set )
{
	mIsUsed = set;
}

void BlockObject::SetAddBody( Vec2 addForce )
{
	for( int i = 0; i < mBlockCount; ++i )
	{
		mRectListvec[i].SetAddBody( addForce );
	}
}

bool BlockObject::CollisionCheck( OtterVector2i pos )
{


	for( int i = 0; i < mBlockCount; ++i )
		if( CollisionRectToPoint( mRectListvec[i].GetRect(), pos ) )
			return true;

	return false;
}

GDIRect* BlockObject::GetRectList()
{
	return 0;
}

std::vector<GDIRect> BlockObject::GetRectListvec()
{
	return mRectListvec;
}

int BlockObject::GetBlockCount()
{
	return mBlockCount;
}



void BlockObject::CreateBlock()
{

	static GDIRect checkRect;
	OtterVector2f prevPos = mRectListvec[0].GetPosition();
	int prevCreateDir = 0;
	int currentDir = 0;
	mDirList[0] = -1;
	mRectListvec[0].SetSize( mSize );
	checkRect.SetSize( mSize );
	for( int i = 1; i < mBlockCount; ++i )
	{
		mRectListvec[i].SetSize( mSize );
		bool CollisionCheck = true;
		int lCheckCount = 0;
		while( CollisionCheck )
		{
			CollisionCheck = false;
			currentDir = rand() % 4;

			if( prevCreateDir % 2 )
			{
				while( ( prevCreateDir - 1 ) == currentDir )
					currentDir = rand() % 4;
			}
			else
			{
				while( ( prevCreateDir + 1 ) == currentDir )
					currentDir = rand() % 4;
			}
			checkRect.SetPosition( prevPos + GetRandPosition( currentDir ) );

			for( int j = 0; j < i; ++j )
				if( CollisionRectToRectRange( checkRect.GetRect(), mRectListvec[j].GetRect(), mSize / 2.f ) )
				{
					CollisionCheck = true;
					lCheckCount++;
				}

			if( lCheckCount > 10 )
			{
				prevPos = mRectListvec[rand() % i].GetPosition();
			}
		}
		mDirList[i] = currentDir;
		prevCreateDir = currentDir;
		mRectListvec[i].SetPosition( prevPos + GetRandPosition( currentDir ) );
		prevPos = mRectListvec[i].GetPosition();
	}
}

OtterVector2f BlockObject::GetRandPosition( int dir )
{
	switch( dir )
	{
		case DIR::RIGHT:
			return OtterVector2f( mSize, 0 );
		case DIR::LEFT:
			return OtterVector2f( -mSize, 0 );
		case DIR::UP:
			return OtterVector2f( 0, -mSize );
		case DIR::DOWN:
			return OtterVector2f( 0, mSize );
		default:
			return OtterVector2f();
	}
}

bool BlockObject::GetUsed()
{
	return mIsUsed;
}

OtterVector2f BlockObject::GetMaxPosition()
{
	return OtterVector2f();
}