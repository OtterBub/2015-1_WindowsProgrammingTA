#include "GDIObject.h"

GDIObject::GDIObject()
{
	mLinePen = NULL;
	mBrush = NULL;
	mLineColor = RGB( 0, 0, 0 );
	mBrushColor = RGB( 255, 255, 255 );
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
	mLineColor = color;
	mLinePen = CreatePen( penStyle, width, mLineColor );
}

void GDIObject::SetBrush( COLORREF color )
{
	if( mBrush != NULL )
		DeleteObject( mLinePen );
	mBrushColor = color;
	mBrush = CreateSolidBrush( mBrushColor );
}

COLORREF GDIObject::GetLineColor()
{
	return mLineColor;
}

COLORREF GDIObject::GetBrushColor()
{
	return mBrushColor;
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