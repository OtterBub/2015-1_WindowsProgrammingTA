#ifndef __GAME_BOARD_OBJECT_H__
#define __GAME_BOARD_OBJECT_H__
#include "Object.h"
#include "GDIRect.h"
#include "AnimateObject.h"
#include <vector>

enum GameSlideDir
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

struct BoardInfo
{
	BoardInfo(){ moveState = false, number = 0, changeNum = false; }
	OtterVector2i pos;
	OtterVector2i destPos;
	bool moveState;
	bool changeNum;
	int number;
};

struct BoardAnim
{
	BoardAnim() { 
		static int count = 0;
		destPos = OtterVector2i( -1, -1 ); 
		moveState = false;
		id = count++;
	}
	AnimateObject animObj;
	OtterVector2i currentPos;	
	OtterVector2i destPos;
	OtterVector2f dir;
	bool moveState;
	float dist;
	int id;
};

struct EffectInfo 
{
	EffectInfo() { 
		static int count = 0;
		id = count++;
	}
	OtterVector2f pos;
	int id;
};

class GameBoardObject : public Object 
{
public:
	GameBoardObject();
	~GameBoardObject();

	void Update( double dt );
	void Draw( HDC hdc );

	void Translate( float x, float y );
	void Translate( const OtterVector2f& trans );
	void SetPosition( float x, float y );
	void SetPosition( const OtterVector2f& pos );

	void CommandSlide( int slideDir );

	void SetBoardSize( const OtterVector2i& size );
	void SetBoardSize( int width, int height );
	void SetRectSize( const OtterVector2i& size );
	void SetRectSize( int width, int height );

	const BoardInfo& GetBoardInfo( int x, int y );
	const BoardInfo& GetBoardInfo( const OtterVector2i& pos );
	void SetDebugMode( bool debug );
	void RandGeneratorBlock();

private:
	void SetPosBoardInfo();
	bool CheckPositionRange( const OtterVector2i& pos );
	bool CheckPositionRange( int x, int y );
	int GetBoardIndex( const OtterVector2i& pos );
	int GetBoardIndex( int x, int y );
	OtterVector2f GetBoardPosition( int x, int y );
	OtterVector2f GetBoardPosition( const OtterVector2i& pos );
	OtterVector2i GetCheckPosition( BoardInfo& currentInfo, const OtterVector2i& cal );
	bool SetBoardAnimDestPos( const OtterVector2i& currentPos, const OtterVector2i& destPos );
	bool SetBoardAnimDestPos( int curX, int curY, int destX, int destY );
	bool MoveAnimateObject( double dt );
	void DeleteBitmap( const OtterVector2i& cur );
	void DeleteProcess();
	bool GetMoveState();
	void ChangeAnimate( AnimateObject& obj, int number );

private:
	bool mCommand;
	bool mBlockMove;
	float mBoardSpeed;
	OtterVector2i mBoardSize;
	OtterVector2f mRectSize;
	std::vector<BoardInfo> mBoard;
	std::vector<BoardInfo> mBoardResult;
	std::vector<BoardAnim> mBoardAnim;
	std::vector<BoardAnim> mDeleteAnim;
	bool mdebug;
};

#endif 