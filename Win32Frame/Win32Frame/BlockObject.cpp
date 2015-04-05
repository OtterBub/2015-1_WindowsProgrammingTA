#include "BlockObject.h"
#include "MathUtill.cpp"

BlockObject::BlockObject( int blockCount, int size )
{
	if( blockCount <= 0 )
	{
		blockCount = 1;
	}
	mRectList = new GDIRect[blockCount]();
	mDirList = new int[blockCount];
	mBlockCount = blockCount;
	mSize = size;
	CreateBlock();
}
BlockObject::~BlockObject()
{
	delete[] mRectList;
	delete[] mDirList;
}


void BlockObject::Update( float dt )
{
}
void BlockObject::Draw( HDC hdc )
{
	for( int i = 0; i < mBlockCount; ++i )
		mRectList[i].Draw( hdc );
}

void BlockObject::Translate( float x, float y )
{
	Object::Translate( x, y );
	for( int i = 0; i < mBlockCount; ++i )
		mRectList[i].Translate( x, y );
}
void BlockObject::Translate( OtterVector2f trans )
{
	Object::Translate( trans );
	for( int i = 0; i < mBlockCount; ++i )
		mRectList[i].Translate( trans );
}
void BlockObject::SetPosition( float x, float y )
{
	Object::SetPosition( x, y );
	mRectList[0].SetPosition( x, y );
	for( int i = 1; i < mBlockCount; ++i )
	{
		OtterVector2f dirpos = GetRandPosition( mDirList[i] );
		OtterVector2f setpos = GetPosition() + dirpos;
		
		if( i != 0 )
		{
			setpos = mRectList[i - 1].GetPosition() + dirpos;
		}

		mRectList[i].SetPosition( setpos );
	}
}
void BlockObject::SetPosition( OtterVector2f pos )
{
	Object::SetPosition( pos );
	mRectList[0].SetPosition( pos );
	for( int i = 1; i < mBlockCount; ++i )
	{
		OtterVector2f dirpos = GetRandPosition( mDirList[i] );
		OtterVector2f setpos = GetPosition() + dirpos;
		
		if( i != 0 )
		{
			setpos = mRectList[i - 1].GetPosition() + dirpos;
		}

		mRectList[i].SetPosition( setpos );
	}
}

bool BlockObject::CollisionCheck( OtterVector2i pos )
{
	for( int i = 0; i < mBlockCount; ++i )
		if( CollisionRectToPoint( mRectList[i].GetRect(), pos ) )
			return true;

	return false;
}

void BlockObject::CreateBlock()
{
	static GDIRect checkRect;
	OtterVector2f prevPos = mRectList[0].GetPosition();
	int prevCreateDir = 0;
	int currentDir = 0;
	mDirList[0] = -1;
	mRectList[0].SetSize( mSize );
	checkRect.SetSize( mSize );
	for( int i = 1; i < mBlockCount; ++i )
	{
		mRectList[i].SetSize( mSize );
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
				if( CollisionRectToRectRange( checkRect.GetRect(), mRectList[j].GetRect(), mSize / 2.f ) )
				{
					CollisionCheck = true;
					lCheckCount++;
				}

			if( lCheckCount > 10 )
			{
				prevPos = mRectList[rand() % i].GetPosition();
			}
		}
		mDirList[i] = currentDir;
		prevCreateDir = currentDir;
		mRectList[i].SetPosition( mRectList[i - 1].GetPosition() + GetRandPosition( currentDir ) );
		prevPos = mRectList[i].GetPosition();
	}
}

OtterVector2f BlockObject::GetRandPosition( int dir )
{
	switch( dir )
	{
		case RIGHT:
			return OtterVector2f( mSize, 0 );
		case LEFT:
			return OtterVector2f( -mSize, 0 );
		case UP:
			return OtterVector2f( 0, -mSize );
		case DOWN:
			return OtterVector2f( 0, mSize );
		default:
			return OtterVector2f();
	}
}