#include "GameStageObject.h"
#include "InputSystem.h"
#include "MathUtill.h"
#include <string>

GameStageObject::GameStageObject( int width, int height ) :
mDisplayObject( width, height )
{
	mWidth = width, mHeight = height;

	mBlockCheck = false;
	mDefaultColor = RGB( 255, 255, 255 );

	mBlockamount = 0;
	mMaxBlockCount = 0;
	mBlockSize = 0;

	mBlockList = nullptr;
	mColorList = nullptr;
	mCreateNewBlock = false;
}
GameStageObject::GameStageObject( int width, int height, int size ) :
mDisplayObject( width, height, size )
{
	mWidth = width, mHeight = height;
	mBlockCheck = false;
	mDefaultColor = RGB( 255, 255, 255 );

	mBlockamount = 0;
	mMaxBlockCount = 0;
	mBlockSize = size;

	mBlockList = nullptr;
	mColorList = nullptr;
	mCreateNewBlock = false;
}
GameStageObject::~GameStageObject()
{
	if( mBlockList != nullptr )
		delete[] mBlockList;
	if( mColorList != nullptr )
		delete[] mColorList;
}

void GameStageObject::Update( float dt )
{
	static int lDragBlockIndex = -1;
	static int lreleaseBlockIndex = -1;
	static bool lreleaseBlock = false;
	static OtterVector2i prevPos = OTTER_INPUT.GetMousePosition();

	// Object Select
	if( OTTER_INPUT.GetMouseDown( MOUSE_MESSAGE::MOUSE_L ) && ( lDragBlockIndex == -1 ) )
	{
		lDragBlockIndex = BlockObjectClickCheck( OTTER_INPUT.GetMouseDownPosition( MOUSE_MESSAGE::MOUSE_L ) );
		if( lDragBlockIndex != -1 )
			lreleaseBlock = false;
	}
	else if( OTTER_INPUT.GetMouseUp( MOUSE_MESSAGE::MOUSE_L ) ){
		lreleaseBlockIndex = lDragBlockIndex;
		lDragBlockIndex = -1;
		lreleaseBlock = true;
	}

	// Object Drag
	if( lDragBlockIndex != -1 ){
		mBlockList[lDragBlockIndex].Translate( OTTER_INPUT.GetMousePosition() - prevPos );
	}
	else if( lreleaseBlock && ( lreleaseBlockIndex != -1 ) )
	{
		mBlockCheck = BlockObjectCheck( mBlockList[lreleaseBlockIndex] );
		if( mBlockCheck )
			mBlockList[lreleaseBlockIndex].SetUsed( true );

		lreleaseBlockIndex = -1;
		lreleaseBlock = false;
	}

	// Object Delete Check
	if( mBlockCheck )
	{		
		mBlockCheck = false;
		DeleteBlockCheck();

		mCreateNewBlock = true;
		for( int i = 0; i < mBlockCount; ++i )
		{
			if( mBlockList[i].GetUsed() == false )
			{
				mCreateNewBlock = false;
			}
		}
	}

	if ( mCreateNewBlock )
	{
		mCreateNewBlock = false;
		SetBlock( mBlockamount, mBlockCount, mBlockSize );
	}

	mDebugStr = std::to_wstring( lDragBlockIndex );
	
	prevPos = OTTER_INPUT.GetMousePosition();
}
void GameStageObject::Draw( HDC hdc )
{	
	mDisplayObject.Draw( hdc );

	if( mBlockList != nullptr )
	{
		for( int i = 0; i < mBlockCount; ++i )
		{
			if( mBlockList[i].GetUsed() == false )
				mBlockList[i].Draw( hdc );
		}
	}

	TextOut( hdc, 0, 0, mDebugStr.c_str(), mDebugStr.size() );
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

void GameStageObject::SetBlock( int blockamount, int maxBlockCount, int BlockSize )
{
	bool *usedNum = new bool[maxBlockCount];
	mBlockamount = blockamount;
	mMaxBlockCount = maxBlockCount;
	mBlockSize = BlockSize;

	memset( usedNum, false, sizeof(bool) * maxBlockCount );

	if( mColorList == nullptr )
	{
		mColorList = new COLORREF[blockamount];
		for( int i = 0; i < blockamount; ++i )
		{
			mColorList[i] = RGB( rand() % 255, rand() % 255, rand() % 255 );
		}
	}

	mBlockCount = blockamount;
	if( mBlockList == nullptr )
		mBlockList = new BlockObject[blockamount];
	else
	{
		delete[] mBlockList;
		mBlockList = new BlockObject[blockamount];
	}
	
	for( int i = 0; i < mBlockCount; ++i )
	{
		int blockNum = ( rand() % maxBlockCount );
		while( usedNum[blockNum] ) blockNum = ( rand() % maxBlockCount );

		usedNum[blockNum] = true;

		mBlockList[i].SetBlock( 1 + blockNum, BlockSize );
		mBlockList[i].SetPosition( 800, 100 + ( i * 250 ) );
		mBlockList[i].SetColor( mColorList[rand() % blockamount] );
	}

	delete[] usedNum;
}

void GameStageObject::BlockCheck( OtterRect2f rect, COLORREF color )
{
	int lIndex = mDisplayObject.GetCollisionIndex( rect );
	if( lIndex != -1 )
	{
		if( mDisplayObject.GetColorRef( lIndex ) == mDefaultColor )
		{
			mDisplayObject.SetIndexColor( lIndex, color );
			mBlockCheck = true;
		}
	}
}

int GameStageObject::RectCheck( OtterRect2f rect )
{
	int lIndex = mDisplayObject.GetCollisionIndex( rect );
	if( lIndex != -1 )
	{
		if( mDisplayObject.GetColorRef( lIndex ) == mDefaultColor )
		{
			return lIndex;
		}
	}

	return -1;
}

bool GameStageObject::BlockObjectCheck( BlockObject block )
{
	std::vector<GDIRect> rect = block.GetRectListvec();
	int rectCount = block.GetBlockCount();
	int checkCount = 0;
	int prevCheck = 0;
	int* changeColorIndexList = new int[rectCount];

	for( int rectIndex = 0; rectIndex < rectCount; ++rectIndex )
	{
		int check = RectCheck( rect[rectIndex].GetRect() );
		if( check == -1 )
			return false;
		else if( check == prevCheck )
			return false;
		else
			changeColorIndexList[rectIndex] = check;

		prevCheck = check;
	}

	for( int i = 0; i < rectCount; ++i )
	{
		int displayIndex = changeColorIndexList[i];
		mDisplayObject.SetIndexColor( displayIndex, rect[i].GetBrushColor() );
	}
	delete[] changeColorIndexList;
	return true;
}

int GameStageObject::BlockObjectClickCheck( OtterVector2i mousepos )
{
	for( int blockIndex = 0; blockIndex < mBlockCount; ++blockIndex )
	{
		std::vector<GDIRect> rect = mBlockList[blockIndex].GetRectListvec();
		int rectCount = mBlockList[blockIndex].GetBlockCount();
		int collisionCount = 0;

		for( int rectIndex = 0; rectIndex < rectCount; ++rectIndex )
		{
			if( CollisionRectToPoint( rect[rectIndex].GetRect(), mousepos ) )
			{
				return blockIndex;
			}
		}
	}

	return -1;
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