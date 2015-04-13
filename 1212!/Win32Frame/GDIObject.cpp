#include "GDIObject.h"
#include <stdio.h>

GDIObject::GDIObject()
{
	mLinePen = NULL;
	mBrush = NULL;
	mLineColor = RGB( 0, 0, 0 );
	mBrushColor = RGB( 255, 255, 255 );
	mPenStyle = PS_SOLID;
	mWidth = 1;
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
	mPenStyle = penStyle;
	mLineColor = color;
}

void GDIObject::SetBrush( COLORREF color )
{
	mBrushColor = color;
}

COLORREF GDIObject::GetLineColor()
{
	return mLineColor;
}

COLORREF GDIObject::GetBrushColor()
{
	return mBrushColor;
}

void GDIObject::CreateMyObject( )
{
	mLinePen = CreatePen( mPenStyle, mWidth, mLineColor );
	mBrush = CreateSolidBrush( mBrushColor );
}
void GDIObject::DeleteMyObject( )
{
	DeleteObject( mLinePen );
	DeleteObject( mBrush );
	mLinePen = NULL;
	mBrush = NULL;
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