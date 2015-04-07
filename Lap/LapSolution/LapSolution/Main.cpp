#include <Windows.h>
#include "List.cpp"

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 1280

#define WINDOW_POS_X 0
#define WINDOW_POS_Y 0

// CLASS

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

HINSTANCE g_hinst;
LPCTSTR lpszClass = L"Window Class Name"; // Window Name

LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszMcdParam, int nCmdShow )
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hinst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject( WHITE_BRUSH );
	WndClass.hCursor = LoadCursor( NULL, IDC_ARROW );
	WndClass.hIcon = LoadIcon( NULL, IDI_APPLICATION );
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass( &WndClass );

	hWnd = CreateWindow( lpszClass, lpszClass,
						 WS_OVERLAPPEDWINDOW, // Window Style
						 WINDOW_POS_X, WINDOW_POS_Y, // Window Position
						 WINDOW_WIDTH, WINDOW_HEIGHT, // Window Size
						 NULL, (HMENU)NULL, hInstance, NULL );

	ShowWindow( hWnd, nCmdShow );
	UpdateWindow( hWnd );

	while( GetMessage( &Message, 0, 0, 0 ) )
	{
		TranslateMessage( &Message );
		DispatchMessage( &Message );
	}

	return Message.wParam;
}

LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	static OtterList<int> list;
	
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	static HPEN myPen = (HPEN)CreatePen( PS_SOLID, 3, RGB( 255, 0, 0 ) );
	static bool sDrag = false;
	static POINT sStartPoint = { 0, };
	static POINT sEndPoint = { 0, };
	static POINT sOldPoint = {0, };
	HPEN OldPen;

	static wchar_t str[250] = L"101010�����ٶ�";
	static wchar_t debug[300] = L"";
	static int count = 0;
	static MyRect lRect;

	switch( uMsg )
	{
		case WM_CREATE:
			count = wcslen( str );
			lRect.SetBrush( RGB( 255, 255, 0) );
			lRect.SetRect( 50, 50, 100, 10 );
			list.Add( 10 );
			list.Add( 20 );
			list.Add( 30 );
			wsprintf( debug, L"%d", list[1] );
			break;

		case WM_PAINT:
			hdc = BeginPaint( hWnd, &ps );

			OldPen = (HPEN)SelectObject( hdc, GetStockObject(BLACK_PEN) );
			
			TextOut( hdc, 0, 0, debug, wcslen( debug ) );
			lRect.Draw( hdc );
			SelectObject( hdc, OldPen );

			EndPaint( hWnd, &ps );
			break;

		case WM_CHAR:
			if( wParam == 'a' )
				list.Add( rand() );
			{
				int r = rand() % list.GetCount();
				wsprintf( debug, L"%d count::%d, MAX::%d", list[r], r, list.GetCount() );
			}
			InvalidateRect( hWnd, NULL, true );
			break;

		case WM_KEYDOWN:
			

			if( wParam == VK_UP )
			{
				lRect.Translate( 0, -10 );
				lRect.SetBrush( RGB( 0, 125, 125 ) );
			}
			else if( wParam == VK_DOWN )
			{
				lRect.Translate( 0, 10 );
				lRect.SetBrush( RGB( 0, 255, 0 ) );
			}
			else if( wParam == VK_LEFT )
			{
				lRect.Translate( -10, 0 );
				lRect.SetBrush( RGB( 255, 0, 0 ) );
			}
			else if( wParam == VK_RIGHT )
			{
				lRect.Translate( 10, 0 );
				lRect.SetBrush( RGB( 0, 0, 255 ) );
			}
			

			InvalidateRect( hWnd, NULL, true );
			break;

		case WM_SYSKEYDOWN:
			
			wsprintf( debug, L"WM_SYSKEYDOWN", count );
			break;

		case WM_SYSCHAR:
			wsprintf( debug, L"WM_SYSCHAR", count );
			break;

		case WM_LBUTTONDOWN:
			sDrag = true;
			sStartPoint.x = LOWORD( lParam );
			sStartPoint.y = HIWORD( lParam );
			sOldPoint = sEndPoint = sStartPoint;
			break;

		case WM_MOUSEMOVE:			
			if( sDrag )
			{
				hdc = GetDC( hWnd );

				SetROP2( hdc, R2_XORPEN );
				SelectObject( hdc, (HPEN)GetStockObject( WHITE_PEN ) );
				

				sEndPoint.x = LOWORD( lParam );
				sEndPoint.y = HIWORD( lParam );

				MoveToEx( hdc, sStartPoint.x, sStartPoint.y, NULL );
				LineTo( hdc, sEndPoint.x, sEndPoint.y );

				MoveToEx( hdc, sStartPoint.x, sStartPoint.y, NULL );
				LineTo( hdc, sOldPoint.x, sOldPoint.y );

				sOldPoint = sEndPoint;
				ReleaseDC( hWnd, hdc );

				wsprintf( debug, L"WM_MOUSEMOVE", count );
			}
			InvalidateRect( hWnd, NULL, FALSE );
			break;

		case WM_LBUTTONUP:
			sDrag = false;
			InvalidateRect( hWnd, NULL, TRUE );
			break;

		case WM_DESTROY:
			PostQuitMessage( 0 );
			break;
	}
	return DefWindowProc( hWnd, uMsg, wParam, lParam );
}