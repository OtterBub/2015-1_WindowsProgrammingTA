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

void GDIRect::Translate( int x, int y )
{
	mRect.left += x;
	mRect.right += x;

	mRect.top += y;
	mRect.bottom += y;
}

void GDIRect::Translate( OtterVector2i trans )
{
	mRect.left += trans.x;
	mRect.right += trans.x;

	mRect.top += trans.y;
	mRect.bottom += trans.y;
}


void GDIRect::SetRect( int x, int y, int size )
{
	mRect.left = x - ( size / 2 );
	mRect.right = x + ( size / 2 );
	
	mRect.top = y - ( size / 2 );
	mRect.bottom = y + ( size / 2 );
}

void GDIRect::SetRect( OtterVector2i pos, int size )
{
	mRect.left = pos.x - ( size / 2 );
	mRect.right = pos.x + ( size / 2 );
	
	mRect.top = pos.y - ( size / 2 );
	mRect.bottom = pos.y + ( size / 2 );
}

void GDIRect::SetRect( int left, int top, int right, int bottom )
{
	mRect.left = left;
	mRect.right = right;
	
	mRect.top = top;
	mRect.bottom = bottom;
}