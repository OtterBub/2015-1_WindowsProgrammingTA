#include "GDIRect.h"
#include <math.h>
#include "Win32Frame.h"

GDIRect::GDIRect()
{
	mSize = 50;	
}

GDIRect::~GDIRect()
{
}

void GDIRect::Draw( HDC hdc )
{
	GDIObject::CreateMyObject();
	GDIObject::Draw( hdc );
	POINT point[4];
	point[0].x = mRectf.point[0].x;
	point[0].y = mRectf.point[0].y;
	point[1].x = mRectf.point[0].x;
	point[1].y = mRectf.point[1].y;
	point[2].x = mRectf.point[1].x;
	point[2].y = mRectf.point[1].y;
	point[3].x = mRectf.point[1].x;
	point[3].y = mRectf.point[0].y;

	//Rectangle( hdc, mRectf.point[0].x, mRectf.point[0].y, mRectf.point[1].x, mRectf.point[1].y );
	
	Polygon( hdc, point, 4);
	GDIObject::DeleteMyObject();
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

void GDIRect::Translate( const OtterVector2f& trans )
{
	Object::Translate( trans );
	float halfWidth = abs( mRectf.point[1].x - mRectf.point[0].x ) / 2;
	float halfHeight = abs( mRectf.point[1].y - mRectf.point[0].y ) / 2;
	mRectf.point[0].x = mPosition.x - halfWidth;
	mRectf.point[1].x = mPosition.x + halfWidth;

	mRectf.point[0].y = mPosition.y - halfHeight;
	mRectf.point[1].y = mPosition.y + halfHeight;

}

void GDIRect::SetPosition( float x, float y )
{
	Object::SetPosition( x, y );
	float halfWidth = abs( mRectf.point[1].x - mRectf.point[0].x ) / 2;
	float halfHeight = abs( mRectf.point[1].y - mRectf.point[0].y ) / 2;
	mRectf.point[0].x = mPosition.x - halfWidth;
	mRectf.point[1].x = mPosition.x + halfWidth;

	mRectf.point[0].y = mPosition.y - halfHeight;
	mRectf.point[1].y = mPosition.y + halfHeight;

}

void GDIRect::SetPosition( const OtterVector2f& pos )
{
	Object::SetPosition( pos );
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

void GDIRect::SetRect( const OtterVector2f& pos, int size )
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

	mSize = abs( right - left );

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