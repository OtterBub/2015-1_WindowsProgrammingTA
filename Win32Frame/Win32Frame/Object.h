#include <Windows.h>

class MyRect
{
public:
	MyRect()
	{
		mLinePen = NULL;
		mBrush = NULL;
	}
	~MyRect()
	{
		if( mLinePen != NULL )
			DeleteObject( mLinePen );
		if( mBrush != NULL )
			DeleteObject( mBrush );
	}

	void Draw( HDC hdc )
	{
		if( mLinePen != NULL )
			SelectObject( hdc, mLinePen );
		if( mBrush != NULL )
			SelectObject( hdc, mBrush );

		Ellipse( hdc, mRect.left, mRect.top, mRect.right, mRect.bottom );
	}

	void Translate( int x, int y )
	{
		mRect.left += x;
		mRect.right += x;

		mRect.top += y;
		mRect.bottom += y;
	}

	void SetRect( int left, int top, int right, int bottom )
	{
		mRect.left = left;
		mRect.top = top;
		mRect.right = right;
		mRect.bottom = bottom;
	}

	void SetPen( int penStyle, int width, COLORREF color )
	{
		if( mLinePen != NULL )
			DeleteObject( mLinePen );
		mLinePen = CreatePen( penStyle, width, color );
	}

	void SetBrush( COLORREF color )
	{
		if( mBrush != NULL )
			DeleteObject( mLinePen );
		mBrush = CreateSolidBrush( color );
	}
	
private:
	HPEN mLinePen;
	HBRUSH mBrush;
	COLORREF mLineColor, mBrushColor;
	RECT mRect;
};