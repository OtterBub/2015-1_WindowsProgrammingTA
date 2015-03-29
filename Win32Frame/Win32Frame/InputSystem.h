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

	bool GetMouseRDown();
	bool GetMouseRUp();
	bool GetMouseLDown();
	bool GetMouseLUp();
	bool GetMouseMDown();
	bool GetMouseMUp();

	OtterVector2i GetMousePosition();

	void SetMouseRButton( bool down );
	void SetMouseLButton( bool down );
	void SetMouseMButton( bool down );
	void SetMousePosition( int x, int y );
	void SetKey( int keycode, bool down );

private:
	Input();
	
private:
	bool mKeyDown[0xFF];
	bool mKeyUp[0xFF];
	bool mAnyKeyDown;
	bool mAnyKeyUp;
	OtterVector2i mCurrentMousePosition;
};

#define OTTER_INPUT Input::GetInstance()

#endif __INPUT_SYS_H__