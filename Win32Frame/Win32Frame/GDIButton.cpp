#include "GDIButton.h"
#include "MathUtill.cpp"

GDIButton::GDIButton()
{
}

GDIButton::~GDIButton()
{
}

void GDIButton::Draw( HDC hdc )
{
	GDIObject::CreateMyObject();
	GDIObject::Draw( hdc );
	POINT point[4];
	RECT textRect;
	point[0].x = mRectf.point[0].x;
	point[0].y = mRectf.point[0].y;
	point[1].x = mRectf.point[0].x;
	point[1].y = mRectf.point[1].y;
	point[2].x = mRectf.point[1].x;
	point[2].y = mRectf.point[1].y;
	point[3].x = mRectf.point[1].x;
	point[3].y = mRectf.point[0].y;

	textRect.left = mRectf.point[0].x;
	textRect.top = mRectf.point[0].y;
	textRect.right = mRectf.point[1].x;
	textRect.bottom = mRectf.point[1].y;

	//Rectangle( hdc, mRectf.point[0].x, mRectf.point[0].y, mRectf.point[1].x, mRectf.point[1].y );
	Polygon( hdc, point, 4);
	DrawText( hdc, mButtonText.c_str(), mButtonText.size(), &textRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER );

	GDIObject::DeleteMyObject();
}

void GDIButton::SetText( std::wstring str )
{
	mButtonText = str;
}

bool GDIButton::CheckClick( OtterVector2i mousePos )
{
	return CollisionRectToPoint( mRectf, mousePos );
}