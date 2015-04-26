#ifndef __BITMAP_OBJECT_H__
#define __BITMAP_OBJECT_H__

#include "Object.h"
#include <string>

class BitmapObject : public Object
{
public:
	BitmapObject();
#ifdef UNICODE
	BitmapObject( std::wstring filename );
	bool FileLoad( std::wstring filename );
#else
	BitmapObject( std::string filename );
	bool FileLoad( std::string filename );
#endif
	~BitmapObject();

	void Update( float dt );
	void Draw( HDC hdc );

	void Translate( float x, float y );
	void Translate( OtterVector2f trans );
	void SetPosition( float x, float y );
	void SetPosition( OtterVector2f pos );

private:
	bool GetBitmapInfo();

private:
	HBITMAP mBitmap;
	BITMAP mBitmapInfo;
};


#endif 