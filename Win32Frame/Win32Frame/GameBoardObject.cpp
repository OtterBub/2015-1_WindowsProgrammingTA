#include "GameBoardObject.h"

GameBoardObject::GameBoardObject()
{
}
GameBoardObject::~GameBoardObject()
{
}

void GameBoardObject::Update( double dt )
{
}
void GameBoardObject::Draw( HDC hdc )
{
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