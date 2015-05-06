#ifndef __GAME_BOARD_OBJECT_H__
#define __GAME_BOARD_OBJECT_H__
#include "Object.h"
#include "GDIRect.h"
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
	BoardInfo(){ moveState = false, number = 0; }
	OtterVector2i pos;
	bool moveState;
	int number;
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

	OtterVector2f GetBoardPosition( int x, int y );
	const BoardInfo& GetBoardInfo( int x, int y );
	const BoardInfo& GetBoardInfo( const OtterVector2i& pos );
	void RandGeneratorBlock();

private:
	void SetPosBoardInfo();
	bool CheckPositionRange( const OtterVector2i& pos );
	bool CheckPositionRange( int x, int y );
	int GetBoardIndex( const OtterVector2i& pos );
	int GetBoardIndex( int x, int y );
	OtterVector2i GetCheckPosition( BoardInfo& currentInfo, const OtterVector2i& cal );

private:
	bool mSlideComplete;
	OtterVector2i mBoardSize;
	OtterVector2f mRectSize;
	std::vector<BoardInfo> mBoard;
	std::vector<BoardInfo> mResultBoard;
};

#endif 