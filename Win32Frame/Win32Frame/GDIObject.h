#ifndef __GDI_OBJECT_H__
#define __GDI_OBJECT_H__

#include "Object.h"

class GDIObject : public Object
{
public:
	GDIObject();
	virtual ~GDIObject();

	virtual void Draw( HDC hdc ) = 0;

	void SetPen( int penStyle, int width, COLORREF color );
	void SetBrush( COLORREF color );

private:
	void SelectMyObject( HDC hdc );
	
protected:
	HPEN mLinePen;
	HBRUSH mBrush;
	COLORREF mLineColor, mBrushColor;
	RECT mRect;
};

#endif __GDI_OBJECT_H__