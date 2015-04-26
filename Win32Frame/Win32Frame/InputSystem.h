#ifndef __INPUT_SYS_H__
#define __INPUT_SYS_H__

#include "OtterMath.h"

enum MOUSE_MESSAGE
{
	MOUSE_L,
	MOUSE_M,
	MOUSE_R,
	MOUSE_END
};

class Input
{
public:
	~Input();
	static Input& GetInstance();

	bool GetAnyKeyDown();
	bool GetAnyKeyUp();
	bool GetKeyDown( unsigned int keycode );
	bool GetKeyUp( unsigned int keycode );

	bool GetMouseDown( MOUSE_MESSAGE message );
	bool GetMouseUp( MOUSE_MESSAGE message );
	OtterVector2i GetMouseDownPosition( MOUSE_MESSAGE message );
	OtterVector2i GetMouseUpPosition( MOUSE_MESSAGE message );

	OtterVector2i GetMousePosition();

	void SetMouseButton( MOUSE_MESSAGE message, OtterVector2i mousePos, bool down );
	void SetCurrentMousePosition( OtterVector2i mousePos );
	void SetKey( int keycode, bool down );

private:
	Input();

private:

	bool mKeyDown[0xFF];
	bool mKeyUp[0xFF];
	bool mAnyKeyDown;
	bool mAnyKeyUp;
	bool mMouseDown[MOUSE_MESSAGE::MOUSE_END];
	bool mMouseUp[MOUSE_MESSAGE::MOUSE_END];
	OtterVector2i mUpMousePosition[MOUSE_MESSAGE::MOUSE_END];
	OtterVector2i mDownMousePosition[MOUSE_MESSAGE::MOUSE_END];
	OtterVector2i mCurrentMousePosition;
};

#define OTTER_INPUT Input::GetInstance()

#endif __INPUT_SYS_H__