#include "GDIObject.h"

GDIObject::GDIObject()
{
	mLinePen = NULL;
	mBrush = NULL;
}
GDIObject::~GDIObject()
{
	if( mLinePen != NULL )
		DeleteObject( mLinePen );
	if( mBrush != NULL )
		DeleteObject( mBrush );
}

void GDIObject::Draw( HDC hdc )
{
	SelectMyObject( hdc );
}

void GDIObject::SetPen( int penStyle, int width, COLORREF color )
{
	if( mLinePen != NULL )
		DeleteObject( mLinePen );
	mLinePen = CreatePen( penStyle, width, color );
}

void GDIObject::SetBrush( COLORREF color )
{
	if( mBrush != NULL )
		DeleteObject( mLinePen );
	mBrush = CreateSolidBrush( color );
}

void GDIObject::SelectMyObject( HDC hdc )
{
	if( mLinePen != NULL )
		SelectObject( hdc, mLinePen );
	else
		SelectObject( hdc, GetStockObject( BLACK_PEN ) );
	if( mBrush != NULL )
		SelectObject( hdc, mBrush );
	else
		SelectObject( hdc, GetStockObject( WHITE_BRUSH ) );
}