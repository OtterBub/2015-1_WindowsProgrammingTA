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

bool Input::GetMouseRDown()
{
	return true;
}
bool Input::GetMouseRUp()
{
	return true;
}
bool Input::GetMouseLDown()
{
	return true;
}
bool Input::GetMouseLUp()
{
	return true;
}
bool Input::GetMouseMDown()
{
	return true;
}
bool Input::GetMouseMUp()
{
	return true;
}

OtterVector2i Input::GetMousePosition()
{
	return OtterVector2i( 0, 0 );
}

void Input::SetMouseRButton( bool down )
{
}
void Input::SetMouseLButton( bool down )
{
}
void Input::SetMouseMButton( bool down )
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