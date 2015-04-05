#ifndef __GAMESTAGE_OBJECT_H__
#define __GAMESTAGE_OBJECT_H__

#include "StageDisplayObject.h"

class GameStageObject : public Object
{
private:
	enum LINE
	{
		VERTICAL,
		HORIZONTAL
	};

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

	void SetDefaultColor( COLORREF color );

	void BlockCheck( OtterRect2f rect, COLORREF color );

private:
	void DeleteBlockCheck();
	void DeleteBlockLine( int line, LINE vh );

private:
	StageDisplayObject mDisplayObject;
	COLORREF mDefaultColor;
	bool mBlockCheck;
	int mWidth, mHeight;
};

#endif