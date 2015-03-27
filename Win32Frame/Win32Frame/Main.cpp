#include <Windows.h>
#include "Win32Frame.h"
#include "List.cpp"
#include "Object.h"

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 1280

#define WINDOW_POS_X 0
#define WINDOW_POS_Y 0

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
	static Win32Frame frame;
	HDC hdc;
	PAINTSTRUCT ps;

	
	switch( uMsg )
	{
		case WM_CREATE:
			frame.Initialize();
			SetTimer( hWnd, 0, 33, NULL );
			break;

		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			RECT clientRect;
			HDC BackBuffDC;
			HBITMAP backbuffer;
			HBITMAP oldBmp;

			hdc = BeginPaint( hWnd, &ps );
			GetClientRect( hWnd, &clientRect );
			
			BackBuffDC = CreateCompatibleDC( hdc );
			backbuffer = CreateCompatibleBitmap( hdc, clientRect.right, clientRect.bottom );
			oldBmp = (HBITMAP)SelectObject( BackBuffDC, backbuffer );
			
			frame.Draw( hWnd, BackBuffDC );

			BitBlt( hdc, 0, 0, clientRect.right, clientRect.bottom, BackBuffDC, 0, 0, SRCCOPY );
			

			EndPaint( hWnd, &ps );
			SelectObject( hdc, oldBmp );
			DeleteObject( backbuffer );
			DeleteDC( BackBuffDC );
			
		}
			
			break;

		case WM_CHAR:
			//InvalidateRect( hWnd, NULL, true );
			break;

		case WM_KEYDOWN:
			//InvalidateRect( hWnd, NULL, true );
			break;

		case WM_TIMER:
			InvalidateRect( hWnd, NULL, true );
			break;

		case WM_DESTROY:
			PostQuitMessage( 0 );
			break;
	}
	return DefWindowProc( hWnd, uMsg, wParam, lParam );
}