#include "GameBoardObject.h"
#include "AnimateCreator.h"
#include <string>
#include <algorithm>
#include "Win32Frame.h"

GameBoardObject::GameBoardObject()
{
	mRectSize = OtterVector2f( 30, 30 );
	mCommand = true;
	mBlockMove = false;
	mBoardSpeed = 200;
	mdebug = false;
}
GameBoardObject::~GameBoardObject()
{
}

void GameBoardObject::Update( double dt )
{
	if( mBlockMove ) {
		mBlockMove = GetMoveState();
		mCommand = false;
	}

	if( !mBlockMove && ( mCommand == false ) )
		RandGeneratorBlock();

	for( BoardAnim& it : mBoardAnim ){
		if( it.dir.x > 0 )
			it.animObj.SetAnimClip( L"RIGHT" );
		else if( it.dir.x < 0 )
			it.animObj.SetAnimClip( L"LEFT" );
		else if( it.dir.y > 0 )
			it.animObj.SetAnimClip( L"DOWN" );
		else if( it.dir.y < 0 )
			it.animObj.SetAnimClip( L"UP" );

		it.animObj.Update( dt );
		it.animObj.SetImageSize( mRectSize.x, mRectSize.y );
		//it.animObj.SetImageSize( mRectSize.x, mRectSize.y );
	}

	MoveAnimateObject( dt );
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

			if( mdebug ) {
				if( mBoard[GetBoardIndex( j, i )].number != 0 )
					DrawText( hdc, str.c_str(), str.size(), &rect, DT_CENTER | DT_SINGLELINE );
			}
		}
	}

	for( BoardAnim& it : mBoardAnim ){
		//it.animObj.SetPosition( GetBoardPosition( it.currentPos.x, it.currentPos.y ) );
		it.animObj.Draw( hdc );
		str = std::to_wstring( it.destPos.x ) + L", " + std::to_wstring( it.destPos.y ) + L" // ";
		str += std::to_wstring( it.currentPos.x ) + L", " + std::to_wstring( it.currentPos.y );
		if( mdebug )
			TextOut( hdc, it.animObj.GetPosition().x, it.animObj.GetPosition().y, str.c_str(), str.size() );
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
	mBoardResult = mBoard;
	if( mBlockMove )
		return;

	//mCommand = true;
	mBlockMove = true;
	OtterVector2i CheckResult;
	switch( slideDir )
	{
		case GameSlideDir::UP:
			for( int indexY = 0; indexY < mBoardSize.y; ++indexY ) {
				for( int indexX = 0; indexX < mBoardSize.x; ++indexX ) {
					if( mBoard[GetBoardIndex( indexX, indexY )].number != 0 ) {
						CheckResult = GetCheckPosition( mBoard[GetBoardIndex( indexX, indexY )], OtterVector2i( 0, -1 ) );
						if( SetBoardAnimDestPos( OtterVector2i( indexX, indexY ), CheckResult ) )
							mCommand = true;					
					}
				}
			}
			break;
		case GameSlideDir::DOWN:
			for( int indexY = mBoardSize.y - 1; indexY >= 0; --indexY ) {
				for( int indexX = 0; indexX < mBoardSize.x; ++indexX ) {
					if( mBoard[GetBoardIndex( indexX, indexY )].number != 0 ) {
						CheckResult = GetCheckPosition( mBoard[GetBoardIndex( indexX, indexY )], OtterVector2i( 0, 1 ) );
						if( SetBoardAnimDestPos( OtterVector2i( indexX, indexY ), CheckResult ) )
							mCommand = true;
					}
				}
			}
			break;
		case GameSlideDir::RIGHT:
			for( int indexX = mBoardSize.x - 1; indexX >= 0; --indexX ) {
				for( int indexY = 0; indexY < mBoardSize.y; ++indexY ) {
					if( mBoard[GetBoardIndex( indexX, indexY )].number != 0 ) {
						CheckResult = GetCheckPosition( mBoard[GetBoardIndex( indexX, indexY )], OtterVector2i( 1, 0 ) );
						if( SetBoardAnimDestPos( OtterVector2i( indexX, indexY ), CheckResult ) )
							mCommand = true;
					}
				}
			}
			break;
		case GameSlideDir::LEFT:
			for( int indexX = 0; indexX < mBoardSize.x; ++indexX ) {
				for( int indexY = 0; indexY < mBoardSize.y; ++indexY ) {
					if( mBoard[GetBoardIndex( indexX, indexY )].number != 0 ) {
						CheckResult = GetCheckPosition( mBoard[GetBoardIndex( indexX, indexY )], OtterVector2i( -1, 0 ) );
						if( SetBoardAnimDestPos( OtterVector2i( indexX, indexY ), CheckResult ) )
							mCommand = true;
					}
				}
			}
			break;

		default:
			break;
	}

	for( auto it : mBoard ){
		it.changeNum = false;
	}

	//std::copy( mResultBoard.begin(), mResultBoard.end(), mBoard );
	mBoard = mBoardResult;
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

const BoardInfo& GameBoardObject::GetBoardInfo( int x, int y )
{
	return mBoard[GetBoardIndex( x, y )];
}
const BoardInfo& GameBoardObject::GetBoardInfo( const OtterVector2i& pos )
{
	return mBoard[GetBoardIndex( pos )];
}
void GameBoardObject::SetDebugMode( bool debug )
{
	mdebug = debug;
}

void GameBoardObject::RandGeneratorBlock()
{
	static int count = 0;
	bool lCreate = false;
	bool lCanPlace = false;
	int lBoardNum = mBoardSize.x * mBoardSize.y;
	mCommand = true;
	for( BoardInfo& it : mBoard ) {
		if( it.number == 0 ) {
			lCanPlace = true;
		}
	}
	while( ( lCreate == false ) && lCanPlace ) {
		int num = rand() % lBoardNum;
		BoardAnim boardAnim;
		if( mBoard[num].number == 0 ) {
			lCreate = true;
			if( rand() % 3 ) {
				mBoard[num].number = 2;
				boardAnim.currentPos = mBoard[num].pos;
				boardAnim.animObj = ANIM_CREATOR.GetAnimObj( L"CHICK" );
			} else {
				mBoard[num].number = 4;
				boardAnim.currentPos = mBoard[num].pos;
				boardAnim.animObj = ANIM_CREATOR.GetAnimObj( L"CHICKEN" );
			}
			boardAnim.animObj.SetImageSize( mRectSize.x, mRectSize.y );
			mBoardAnim.push_back( boardAnim );
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
OtterVector2f GameBoardObject::GetBoardPosition( int x, int y )
{
	RECT rect;

	rect = { mPosition.x + ( mRectSize.x * x ), mPosition.y + ( mRectSize.y * y ),
				mPosition.x + ( mRectSize.x * ( x + 1 ) ), mPosition.y + ( mRectSize.y * ( y + 1 ) ) };

	return OtterVector2f( rect.left + ( mRectSize.x * 0.5f ), rect.top + ( mRectSize.y * 0.5f ) );
}

OtterVector2f GameBoardObject::GetBoardPosition( const OtterVector2i& pos )
{
	RECT rect;

	rect = { mPosition.x + ( mRectSize.x * pos.x ), mPosition.y + ( mRectSize.y * pos.y ),
				mPosition.x + ( mRectSize.x * ( pos.x + 1 ) ), mPosition.y + ( mRectSize.y * ( pos.y + 1 ) ) };

	return OtterVector2f( rect.left + ( mRectSize.x * 0.5f ), rect.top + ( mRectSize.y * 0.5f ) );
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
			
			if( mBoardResult[GetBoardIndex( checkPos )].number == 0 ) {
				blankCount++;
			} else if( ( firstOtherNum == 0 ) ){
				firstOtherNum = mBoardResult[GetBoardIndex( checkPos )].number;
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
		if( IsEqualNum ) {
			mBoardResult[GetBoardIndex( checkPos )].number += currentInfo.number;
			mBoardResult[GetBoardIndex( checkPos )].changeNum = true;
			currentInfo.number = 0;
		}
		else
			mBoardResult[GetBoardIndex( checkPos )].number = currentInfo.number;

		mBoardResult[GetBoardIndex( currentInfo.pos )].number = 0;
		return checkPos;

	} else {
		return currentInfo.pos;
	}
}

bool GameBoardObject::SetBoardAnimDestPos( const OtterVector2i& currentPos, const OtterVector2i& destPos )
{
	for( BoardAnim& it : mBoardAnim ) {
		if( currentPos == it.currentPos ) {
			if( it.currentPos == destPos  )
				return false;
			it.destPos = destPos;
			it.dir = GetBoardPosition( it.destPos ) - it.animObj.GetPosition();
			it.dist = it.dir.GetLength();
			it.dir.Normalize();
			it.moveState = true;
			return true;
		}
	}
}
bool GameBoardObject::SetBoardAnimDestPos( int curX, int curY, int destX, int destY ) 
{
	OtterVector2i cur = OtterVector2i( curX, curY );
	OtterVector2i dest = OtterVector2i( destX, destY );
	for( BoardAnim& it : mBoardAnim ) {
		if( cur == it.currentPos ) {
			if( it.currentPos == dest  )
				return false;
			it.destPos = dest;
			it.dir = GetBoardPosition( it.destPos ) - it.animObj.GetPosition();
			it.dist = it.dir.GetLength();
			it.dir.Normalize();
			it.moveState = true;
			return true;
		}
	}
}

bool GameBoardObject::MoveAnimateObject( double dt )
{
	bool moveComplete = true;
	OtterVector2i NotDestPos( -1, -1 );
	for( BoardAnim& it : mBoardAnim ) {
		if( ( it.destPos != NotDestPos ) || it.moveState ) {
			if( it.currentPos == it.destPos ) {
				it.destPos = { -1, -1 };
				continue;
			}

			OtterVector2f moveDir = it.dir * ( mBoardSpeed * dt );
			it.animObj.Translate( moveDir );
			it.dist -= mBoardSpeed * dt;
			if( it.dist <= 0 ) {
				it.animObj.SetPosition( GetBoardPosition( it.destPos ) );
				
				DeleteBitmap( it.destPos );
				it.currentPos = it.destPos;
				it.destPos = { -1, -1 };
				it.moveState = false;
				ChangeAnimate( it.animObj, mBoard[ GetBoardIndex( it.currentPos ) ].number );
				
			}
			moveComplete = false;
			
		} else {
			it.animObj.SetPosition( GetBoardPosition( it.currentPos.x, it.currentPos.y ) );
		}
	}

	DeleteProcess();
	return moveComplete;
}

void GameBoardObject::DeleteBitmap( const OtterVector2i& cur )
{
	auto it = std::find_if( mBoardAnim.begin(), mBoardAnim.end(), [&cur]( const BoardAnim& s ) { return ( ( s.currentPos == cur ) && ( s.moveState == false ) ); } );
	if( mBoardAnim.end () != it ) {
		mDeleteAnim.push_back( *it );
	}
}

void GameBoardObject::DeleteProcess()
{
	for( auto it : mDeleteAnim ) {
		auto sit = std::find_if( mBoardAnim.begin(), mBoardAnim.end(), [it]( const BoardAnim& s ){ return ( s.id == it.id ); } );
		mBoardAnim.erase( sit );
	}
	if( mDeleteAnim.size() > 0 ) {
		mDeleteAnim.clear();
	}
}

bool GameBoardObject::GetMoveState()
{
	bool result = false;

	for( auto it : mBoardAnim ){
		if( it.moveState )
			result = true;
	}

	return result;
}

void GameBoardObject::ChangeAnimate( AnimateObject& obj, int number )
{
	switch( number ){
		case 2:
			obj = ANIM_CREATOR.GetAnimObj( L"CHICK" );
			break;
		case 4:
			obj = ANIM_CREATOR.GetAnimObj( L"CHICKEN" );
			break;
		case 8:
			obj = ANIM_CREATOR.GetAnimObj( L"DOVE" );
			break;
		case 16:
			obj = ANIM_CREATOR.GetAnimObj( L"DOVE_FLY" );
			break;
		case 32:
			obj = ANIM_CREATOR.GetAnimObj( L"SEAGULL" );
			break;
		case 64:
			obj = ANIM_CREATOR.GetAnimObj( L"BAT" );
			break;
		case 128:
			obj = ANIM_CREATOR.GetAnimObj( L"SWAN" );
			break;
		case 256:
			break;
		case 512:
			break;
		case 1024:
			break;
		case 2048:
			break;
	}
}