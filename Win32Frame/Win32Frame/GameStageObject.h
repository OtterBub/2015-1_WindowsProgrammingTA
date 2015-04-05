#ifndef __GAMESTAGE_OBJECT_H__
#define __GAMESTAGE_OBJECT_H__

#include "StageDisplayObject.h"

class GameStageObject : public Object
{
public:
	GameStageObject( int width, int height );
	GameStageObject( int width, int height, int size );
	~GameStageObject();	

	void Update( float dt );
	void Draw( HDC hdc );

	void Translate( float x, float y );
	void Translate( OtterVector2f trans );
	void SetPosition( float x, float y );
	void SetPosition( OtterVector2f pos );

	void BlockCheck( OtterRect2f rect, COLORREF color );

private:
	StageDisplayObject mDisplayObject;
};

#endif