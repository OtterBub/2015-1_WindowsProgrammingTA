#include "InputSystem.h"

Input::Input()
{
	for( int i = 0; i < 0xFF; ++i )
	{
		mKeyDown[i] = false;
		mKeyUp[i] = true;
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
	if( !mAnyKeyDown )
		return false;
	else
	{
		mAnyKeyDown = false;
		return true;
	}
}
bool Input::GetAnyKeyUp()
{
	if( !mAnyKeyUp )
		return false;
	else
	{
		mAnyKeyUp = false;
		return true;
	}
}
bool Input::GetKeyDown( int keycode )
{
	return mKeyDown[ keycode ];
}
bool Input::GetKeyUp( int keycode )
{
	return mKeyUp[keycode];
}

OtterVector2i Input::GetMousePosition()
{
	return OtterVector2i( 0, 0 );
}

void Input::SetMouseButton( int mouseEvent, bool down )
{
	
}
void Input::SetMousePosition( int x, int y )
{
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