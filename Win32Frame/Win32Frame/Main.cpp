#include <Windows.h>
#include <ctime>
#include "Win32Frame.h"
#include "MenuScene.h"

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 1280

#define WINDOW_POS_X 0
#define WINDOW_POS_Y 0

HINSTANCE g_hinst;
LPCTSTR lpszClass = L"1212!"; // Window Name

LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
VOID CALLBACK timer(HWND hwnd, UINT uMsg, UINT_PTR ptr, DWORD dword);

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszMcdParam, int nCmdShow )
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hinst = hInstance;

	srand( (unsigned int)time(NULL) );

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
	HDC hdc;
	PAINTSTRUCT ps;

	
	switch( uMsg )
	{
		case WM_CREATE:
			WIN32FRAME.Initialize();
			WIN32FRAME.SethWnd( hWnd );
			WIN32FRAME.ChangeScene( new MenuScene( ) );

			SetTimer( hWnd, 0, 10, timer );
			break;

		case WM_PAINT:
		{
			RECT clientRect;
			HDC BackBuffDC;
			HBITMAP backbuffer;
			HBITMAP oldBmp;

			hdc = BeginPaint( hWnd, &ps );
			GetClientRect( hWnd, &clientRect );
			
			BackBuffDC = CreateCompatibleDC( hdc );
			backbuffer = CreateCompatibleBitmap( hdc, clientRect.right, clientRect.bottom );
			oldBmp = (HBITMAP)SelectObject( BackBuffDC, backbuffer );
			
			// Clear
			FillRect( BackBuffDC, &clientRect, (HBRUSH)GetStockObject(WHITE_BRUSH) );

			// Draw
			WIN32FRAME.Draw( hWnd, BackBuffDC );
			
			// Draw Second Buffer to Main Buffer
			BitBlt( hdc, 0, 0, clientRect.right, clientRect.bottom, BackBuffDC, 0, 0, SRCCOPY );
			
			SelectObject( hdc, oldBmp );
			DeleteObject( backbuffer );
			DeleteDC( BackBuffDC );
			EndPaint( hWnd, &ps );
			
		}
			break;

		case WM_CHAR:
			WIN32FRAME.KeyChar( wParam, lParam );
			break;

		case WM_KEYDOWN:
			OTTER_INPUT.SetKey( wParam, true );
			//WIN32FRAME.KeyDown( wParam, lParam );
			break;

		case WM_KEYUP:
			OTTER_INPUT.SetKey( wParam, false );
			//WIN32FRAME.KeyUp( wParam, lParam );
			break;

		case WM_LBUTTONDOWN:
			OTTER_INPUT.SetMouseButton( MOUSE_MESSAGE::MOUSE_L, OtterVector2i( LOWORD(lParam), HIWORD(lParam) ), true );
			break;
			
		case WM_LBUTTONUP:
			OTTER_INPUT.SetMouseButton( MOUSE_MESSAGE::MOUSE_L, OtterVector2i( LOWORD(lParam), HIWORD(lParam) ), false );
			break;

		case WM_RBUTTONDOWN:
			OTTER_INPUT.SetMouseButton( MOUSE_MESSAGE::MOUSE_R, OtterVector2i( LOWORD(lParam), HIWORD(lParam) ), false );
			break;

		case WM_RBUTTONUP:
			OTTER_INPUT.SetMouseButton( MOUSE_MESSAGE::MOUSE_R, OtterVector2i( LOWORD(lParam), HIWORD(lParam) ), false );
			break;

		case WM_MOUSEMOVE:
			OTTER_INPUT.SetCurrentMousePosition( OtterVector2i( LOWORD(lParam), HIWORD(lParam) ) );
			break;

		case WM_TIMER:
			
			break;

		case WM_DESTROY:
			PostQuitMessage( 0 );
			break;
	}
	return DefWindowProc( hWnd, uMsg, wParam, lParam );
}

VOID CALLBACK timer(HWND hwnd, UINT uMsg, UINT_PTR ptr, DWORD dword)
{
	WIN32FRAME.Update( 0 );
	InvalidateRect( hwnd, NULL, false );
}