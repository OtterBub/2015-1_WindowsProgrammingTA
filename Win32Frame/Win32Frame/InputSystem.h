#ifndef __INPUT_SYS_H__
#define __INPUT_SYS_H__

#include "OtterVector.cpp"


class Input
{

public:
	~Input();
	static Input& GetInstance();

	bool GetAnyKeyDown();
	bool GetAnyKeyUp();
	bool GetKeyDown( int keycode );
	bool GetKeyUp( int keycode );

	bool GetMouseDown();
	bool GetMouseUp();

	OtterVector2i GetMousePosition();

	void SetMouseButton( int mouseEvent, bool down );
	void SetMousePosition( int x, int y );
	void SetKey( int keycode, bool down );

private:
	Input();

private:
	bool mKeyDown[0xFF];
	bool mKeyUp[0xFF];
	bool mAnyKeyDown;
	bool mAnyKeyUp;
	bool mMouseDown[1];
	bool mMouseUp[1];
	OtterVector2i mCurrentMousePosition;
};

#define OTTER_INPUT Input::GetInstance()

#endif __INPUT_SYS_H__