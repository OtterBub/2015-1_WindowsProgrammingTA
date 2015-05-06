#include "GameBoardObject.h"
#include <string>
#include <algorithm>

GameBoardObject::GameBoardObject()
{
	mRectSize = OtterVector2f( 30, 30 );
	mSlideComplete = false;
}
GameBoardObject::~GameBoardObject()
{
}

void GameBoardObject::Update( double dt )
{
	if( mSlideComplete )
		RandGeneratorBlock();

}
void GameBoardObject::Draw( HDC hdc )
{
	std::wstring str;
	RECT rect;
	for( int i = 0; i < mBoardSize.y; ++i ) {
		for( int j = 0; j < mBoardSize.x; ++j ) {
			rect = { mPosition.x + ( mRectSize.x * j ), mPosition.y + ( mRectSize.y * i ),
				mPosition.x + ( mRectSize.x * ( j + 1 ) ), mPosition.y + ( mRectSize.y * ( i + 1 ) ) };

			Rectangle( hdc, rect.left, rect.top, rect.right, rect.bottom );
			str = std::to_wstring( mBoard[GetBoardIndex( j, i )].number );

			if( mBoard[GetBoardIndex( j, i )].number != 0 )
				DrawText( hdc, str.c_str(), str.size(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE );
		}
	}
}

void GameBoardObject::Translate( float x, float y )
{
	Object::Translate( x, y );
}
void GameBoardObject::Translate( const OtterVector2f& trans )
{
	Object::Translate( trans );
}
void GameBoardObject::SetPosition( float x, float y )
{
	Object::SetPosition( x, y );
}
void GameBoardObject::SetPosition( const OtterVector2f& pos )
{
	Object::SetPosition( pos );
}

void GameBoardObject::CommandSlide( int slideDir )
{
	//std::copy( mBoard.begin(), mBoard.end(), mResultBoard );
	//mResultBoard = mBoard;
	OtterVector2i CheckResult;
	switch( slideDir )
	{
		case GameSlideDir::UP:
			for( int indexY = 0; indexY < mBoardSize.y; ++indexY ) {
				for( int indexX = 0; indexX < mBoardSize.x; ++indexX ) {
					if( mBoard[GetBoardIndex( indexX, indexY )].number != 0 ) {
						CheckResult = GetCheckPosition( mBoard[GetBoardIndex( indexX, indexY )], OtterVector2i( 0, -1 ) );
					}
				}
			}
			break;
		case GameSlideDir::DOWN:
			for( int indexY = mBoardSize.y - 1; indexY >= 0; --indexY ) {
				for( int indexX = 0; indexX < mBoardSize.x; ++indexX ) {
					if( mBoard[GetBoardIndex( indexX, indexY )].number != 0 ) {
						CheckResult = GetCheckPosition( mBoard[GetBoardIndex( indexX, indexY )], OtterVector2i( 0, 1 ) );
					}
				}
			}
			break;
		case GameSlideDir::RIGHT:
			for( int indexX = mBoardSize.x - 1; indexX >= 0; --indexX ) {
				for( int indexY = 0; indexY < mBoardSize.y; ++indexY ) {
					if( mBoard[GetBoardIndex( indexX, indexY )].number != 0 ) {
						CheckResult = GetCheckPosition( mBoard[GetBoardIndex( indexX, indexY )], OtterVector2i( 1, 0 ) );
					}
				}
			}
			break;
		case GameSlideDir::LEFT:
			for( int indexX = 0; indexX < mBoardSize.x; ++indexX ) {
				for( int indexY = 0; indexY < mBoardSize.y; ++indexY ) {
					if( mBoard[GetBoardIndex( indexX, indexY )].number != 0 ) {
						CheckResult = GetCheckPosition( mBoard[GetBoardIndex( indexX, indexY )], OtterVector2i( -1, 0 ) );
					}
				}
			}
			break;

		default:
			break;
	}

	//std::copy( mResultBoard.begin(), mResultBoard.end(), mBoard );
	//mBoard = mResultBoard;
}

void GameBoardObject::SetBoardSize( const OtterVector2i& size )
{
	mBoardSize = size;
	mBoard.resize( size.x * size.y );
	SetPosBoardInfo();
}
void GameBoardObject::SetBoardSize( int width, int height )
{
	mBoardSize.x = width;
	mBoardSize.y = height;
	mBoard.resize( width * height );
	SetPosBoardInfo();
}
void GameBoardObject::SetRectSize( const OtterVector2i& size )
{
	mRectSize = size;
}
void GameBoardObject::SetRectSize( int width, int height )
{
	mRectSize.x = width;
	mRectSize.y = height;
}

OtterVector2f GameBoardObject::GetBoardPosition( int x, int y )
{
	RECT rect;

	rect = { mPosition.x + ( mRectSize.x * x ), mPosition.y + ( mRectSize.y * y ),
		mPosition.x + ( mRectSize.x * ( x + 1 ) ), mPosition.y + ( mRectSize.y * ( y + 1 ) ) };

	return OtterVector2f( ( rect.right - rect.left ) / 2.f, ( rect.bottom - rect.top ) / 2.f );
}
const BoardInfo& GameBoardObject::GetBoardInfo( int x, int y )
{
	return mBoard[GetBoardIndex( x, y )];
}
const BoardInfo& GameBoardObject::GetBoardInfo( const OtterVector2i& pos )
{
	return mBoard[GetBoardIndex( pos )];
}

void GameBoardObject::RandGeneratorBlock()
{
	static int count = 0;
	bool lCreate = false;
	int lBoardNum = mBoardSize.x * mBoardSize.y;
	mSlideComplete = false;
	while( lCreate == false ) {
		int num = rand() % lBoardNum;
		if( mBoard[num].number == 0 ) {
			lCreate = true;
			if( rand() % 3 )
				mBoard[num].number = 2;
			else
				mBoard[num].number = 4;
		}
	}
}

void GameBoardObject::SetPosBoardInfo()
{
	for( int i = 0; i < mBoardSize.y; ++i ) {
		for( int j = 0; j < mBoardSize.x; ++j ) {
			mBoard[GetBoardIndex( j, i )].pos.x = j;
			mBoard[GetBoardIndex( j, i )].pos.y = i;
		}
	}
}
bool GameBoardObject::CheckPositionRange( const OtterVector2i& pos )
{
	return ( pos.x >= 0 ) && ( pos.x < mBoardSize.x ) &&
		( pos.y >= 0 ) && ( pos.y < mBoardSize.y );
}
bool GameBoardObject::CheckPositionRange( int x, int y )
{
	return ( x >= 0 ) && ( x < mBoardSize.x ) &&
		( y >= 0 ) && ( y < mBoardSize.y );
}
int GameBoardObject::GetBoardIndex( const OtterVector2i& pos )
{
	return pos.x + ( pos.y * mBoardSize.x );
}
int GameBoardObject::GetBoardIndex( int x, int y )
{
	return x + ( y * mBoardSize.x );
}
OtterVector2i GameBoardObject::GetCheckPosition( BoardInfo& currentInfo, const OtterVector2i& cal )
{
	OtterVector2i checkPos = currentInfo.pos;
	OtterVector2i checkPosBackUp = checkPos;
	int blankCount = 0;
	int firstOtherNum = 0;
	bool checking = true;
	bool IsEqualNum = false;
	while( checking ) {
		checkPos += cal;
		if( CheckPositionRange( checkPos ) ) {
			
			if( mBoard[GetBoardIndex( checkPos )].number == 0 ) {
				blankCount++;
			} else if( firstOtherNum == 0 ){
				firstOtherNum = mBoard[GetBoardIndex( checkPos )].number;
			}
			if( ( currentInfo.number == firstOtherNum ) ) {
				checking = false;
				IsEqualNum = true;
			}
		}
		else {
			checking = false;
			checkPos = checkPosBackUp;
		}
	}
	if( IsEqualNum == false )
		checkPos = currentInfo.pos + ( cal * blankCount );

	if( checkPos != currentInfo.pos ) {
		if( IsEqualNum )
			mBoard[GetBoardIndex( checkPos )].number += currentInfo.number;
		else
			mBoard[GetBoardIndex( checkPos )].number = currentInfo.number;

		mBoard[GetBoardIndex( currentInfo.pos )].number = 0;
		return checkPos;

	} else {
		return currentInfo.pos;
	}
}