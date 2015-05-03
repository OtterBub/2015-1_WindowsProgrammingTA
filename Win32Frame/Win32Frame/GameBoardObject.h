#ifndef __GAME_BOARD_OBJECT_H__
#define __GAME_BOARD_OBJECT_H__
#include "Object.h"

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

private:

};

#endif 