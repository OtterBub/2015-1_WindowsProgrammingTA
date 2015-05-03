#include "InputSystem.h"

Input::Input()
{
	for( int i = 0; i < 0xFF; ++i )
	{
		mKeyDown[i] = false;
		mKeyUp[i] = true;
	}

	for( int i = 0; i < MOUSE_MESSAGE::MOUSE_END; ++i )
	{
		mMouseDown[i] = false;
		mMouseUp[i] = true;
	}

	mAnyKeyUp = true;
	mAnyKeyDown = false;
}
Input::~Input()
{

}

Input& Input::GetInstance()
{
	static Input instance;
	return instance;
}

bool Input::GetAnyKeyDown()
{
	return mAnyKeyDown;
}
bool Input::GetAnyKeyUp()
{
	return mAnyKeyUp;
}
bool Input::GetKeyDown( unsigned int keycode )
{
	return mKeyDown[keycode];
}
bool Input::GetKeyUp( unsigned int keycode )
{
	return mKeyUp[keycode];
}

bool Input::GetMouseDown( MOUSE_MESSAGE message )
{
	return mMouseDown[message];
}

bool Input::GetMouseUp( MOUSE_MESSAGE message )
{
	return mMouseUp[message];
}

const OtterVector2i& Input::GetMouseDownPosition( MOUSE_MESSAGE message )
{
	return mDownMousePosition[message];
}

const OtterVector2i& Input::GetMouseUpPosition( MOUSE_MESSAGE message )
{
	return mUpMousePosition[message];
}

const OtterVector2i& Input::GetMousePosition()
{
	return mCurrentMousePosition;
}

void Input::SetMouseButton( MOUSE_MESSAGE message, const OtterVector2i& mousePos, bool down )
{
	mMouseDown[message] = down;
	mMouseUp[message] = !down;

	if( down )
		mDownMousePosition[message] = mousePos;
	else
		mUpMousePosition[message] = mousePos;
}

void Input::SetCurrentMousePosition( const OtterVector2i& mousePos )
{
	mCurrentMousePosition = mousePos;
}

void Input::SetKey( int keycode, bool down )
{
	mKeyDown[keycode] = down;
	mKeyUp[keycode] = !down;

	if( down )
	{
		mAnyKeyDown = true;
		mAnyKeyUp = false;
	}
	else
	{
		mAnyKeyUp = true;
		mAnyKeyDown = false;
	}
}