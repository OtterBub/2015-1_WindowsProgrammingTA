#include "GDIRect.h"

GDIRect::GDIRect()
{
}

GDIRect::~GDIRect()
{
}

void GDIRect::Draw( HDC hdc )
{
	GDIObject::Draw( hdc );
	Rectangle( hdc, mRect.left, mRect.top, mRect.right, mRect.bottom  );
}

void GDIRect::Translate( float x, float y )
{
	Object::Translate( x, y );
	int halfWidth = abs( mRect.right - mRect.left ) / 2;
	int halfHeight = abs( mRect.bottom - mRect.top ) / 2;
	mRect.left = mPosition.x - halfWidth;
	mRect.right = mPosition.x + halfWidth;

	mRect.top = mPosition.y - halfHeight;
	mRect.bottom = mPosition.y + halfHeight;
}

void GDIRect::Translate( OtterVector2f trans )
{
	Object::Translate( trans );
	int halfWidth = abs( mRect.right - mRect.left ) / 2;
	int halfHeight = abs( mRect.bottom - mRect.top ) / 2;
	mRect.left = mPosition.x - halfWidth;
	mRect.right = mPosition.x + halfWidth;

	mRect.top = mPosition.y - halfHeight;
	mRect.bottom = mPosition.y + halfHeight;
}


void GDIRect::SetRect( int x, int y, int size )
{
	SetPosition( x, y );

	mRect.left = x - ( size / 2 );
	mRect.right = x + ( size / 2 );
	
	mRect.top = y - ( size / 2 );
	mRect.bottom = y + ( size / 2 );
}

void GDIRect::SetRect( OtterVector2f pos, int size )
{
	SetPosition( pos );

	mRect.left = pos.x - ( size / 2 );
	mRect.right = pos.x + ( size / 2 );
	
	mRect.top = pos.y - ( size / 2 );
	mRect.bottom = pos.y + ( size / 2 );
}

void GDIRect::SetRect( int left, int top, int right, int bottom )
{
	SetPosition( abs( left - right ) / 2, abs( top - bottom ) / 2 );

	mRect.left = left;
	mRect.right = right;
	
	mRect.top = top;
	mRect.bottom = bottom;
}