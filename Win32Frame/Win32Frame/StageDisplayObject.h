#ifndef __STAGEDISPLAY_OBJECT_H__
#define __STAGEDISPLAY_OBJECT_H__

#include "GDIRect.h"

class StageDisplayObject : public Object
{
public:
	StageDisplayObject( int width, int height );
	StageDisplayObject( int width, int height, int size );
	~StageDisplayObject();

	void Draw( HDC hdc );

	void Translate( float x, float y );
	void Translate( OtterVector2f trans );
	void SetPosition( float x, float y );
	void SetPosition( OtterVector2f pos );

	void SetSize( int size );
	void SetPostionColor( OtterVector2f pos, COLORREF color );

	int GetCollisionIndex( OtterVector2f point );
	int GetCollisionIndex( OtterRect2f rect );

private:
	int mWidth, mHeight, mSize;
	GDIRect* mRectList;
};

#endif __STAGEDISPLAY_OBJECT_H__