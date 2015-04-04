#include "GDIRect.h"
#include <math.h>

GDIRect::GDIRect()
{
}

GDIRect::~GDIRect()
{
}

void GDIRect::Draw( HDC hdc )
{
	GDIObject::Draw( hdc );
	Rectangle( hdc, mRectf.point[0].x, mRectf.point[0].y, mRectf.point[1].x, mRectf.point[1].y );
}

void GDIRect::Translate( float x, float y )
{
	Object::Translate( x, y );
	float halfWidth = abs( mRectf.point[1].x - mRectf.point[0].x ) / 2;
	float halfHeight = abs( mRectf.point[1].y - mRectf.point[0].y ) / 2;
	mRectf.point[0].x = mPosition.x - halfWidth;
	mRectf.point[1].x = mPosition.x + halfWidth;

	mRectf.point[0].y = mPosition.y - halfHeight;
	mRectf.point[1].y = mPosition.y + halfHeight;
}

void GDIRect::Translate( OtterVector2f trans )
{
	Object::Translate( trans );
	float halfWidth = abs( mRectf.point[1].x - mRectf.point[0].x ) / 2;
	float halfHeight = abs( mRectf.point[1].y - mRectf.point[0].y ) / 2;
	mRectf.point[0].x = mPosition.x - halfWidth;
	mRectf.point[1].x = mPosition.x + halfWidth;

	mRectf.point[0].y = mPosition.y - halfHeight;
	mRectf.point[1].y = mPosition.y + halfHeight;
}


void GDIRect::SetRect( int x, int y, int size )
{
	SetPosition( x, y );
	mSize = size;

	mRectf.point[0].x = mPosition.x - ( mSize / 2 );
	mRectf.point[1].x = mPosition.x + ( mSize / 2 );
	
	mRectf.point[0].y = mPosition.y - ( mSize / 2 );
	mRectf.point[1].y = mPosition.y + ( mSize / 2 );
}

void GDIRect::SetRect( OtterVector2f pos, int size )
{
	SetPosition( pos );
	mSize = size;

	mRectf.point[0].x = mPosition.x - ( mSize / 2 );
	mRectf.point[1].x = mPosition.x + ( mSize / 2 );
	
	mRectf.point[0].y = mPosition.y - ( mSize / 2 );
	mRectf.point[1].y = mPosition.y + ( mSize / 2 );
}

void GDIRect::SetRect( int left, int top, int right, int bottom )
{
	SetPosition( left + abs( left - right ) / 2.f, top + abs( top - bottom ) / 2.f);

	mRectf.point[0].x = left;
	mRectf.point[1].x = right;
	
	mRectf.point[0].y = top;
	mRectf.point[1].y = bottom;
}

void GDIRect::SetSize( int size )
{
	mSize = size;
	SetRect( mPosition, mSize );
}

OtterRect2f GDIRect::GetRect()
{
	return mRectf;
}