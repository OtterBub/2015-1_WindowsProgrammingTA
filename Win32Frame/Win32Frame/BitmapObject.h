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
	
	void SetScale( OtterVector2f scale );
	void SetScale( float scaleX, float scaleY );
	void SetDestSize( OtterVector2f destSize );
	void SetDestSize( float width, float height );
	void SetSrcRect( OtterRect2f srcRect );
	void SetSrcRect( OtterVector2f point1, OtterVector2f point2 );
	void SetSrcRect( float x1, float y1, float x2, float y2 );

	

private:
	bool GetBitmapInfo();

private:
	HBITMAP mBitmap;
	BITMAP mBitmapInfo;
	OtterVector2f mDestScale;
	OtterVector2f mDestSize;
	OtterRect2f mSrcRect;
};


#endif 