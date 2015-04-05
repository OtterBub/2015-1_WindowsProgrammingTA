#include "GameStageObject.h"

GameStageObject::GameStageObject( int width, int height ) :
mDisplayObject( width, height )
{

}
GameStageObject::GameStageObject( int width, int height, int size ) :
mDisplayObject( width, height, size )
{
}
GameStageObject::~GameStageObject()
{
}

void GameStageObject::Update( float dt )
{

}
void GameStageObject::Draw( HDC hdc )
{
	mDisplayObject.Draw( hdc );
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

void GameStageObject::BlockCheck( OtterRect2f rect, COLORREF color )
{
	int lIndex = mDisplayObject.GetCollisionIndex( rect );
	if( lIndex != -1 )
	{
		mDisplayObject.SetIndexColor( lIndex, color );
	}
}