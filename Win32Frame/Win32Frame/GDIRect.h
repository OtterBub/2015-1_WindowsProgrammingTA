#ifndef __GDI_RECT_H__
#define __GDI_RECT_H__

#include "GDIObject.h"

class GDIRect : public GDIObject
{
public:
	GDIRect();
	~GDIRect();

	virtual void Draw( HDC hdc );

	void Translate( float x, float y );
	void Translate( OtterVector2f trans );
	void SetPosition( float x, float y );
	void SetPosition( OtterVector2f pos );

	void SetRect( int x, int y, int size );
	void SetRect( OtterVector2f pos, int size );
	void SetRect( int left, int top, int right, int bottom );
	void SetSize( int size );
	void SetMass( float mass );

	OtterRect2f GetRect();

protected:
	OtterRect2f mRectf;
	int mSize;
	int mBodyIndex;
};


#endif __GDI_RECT_H__