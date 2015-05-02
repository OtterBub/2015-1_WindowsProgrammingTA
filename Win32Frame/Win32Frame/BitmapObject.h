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
	void SetSrcPosition( OtterVector2f pos );
	void SetSrcPosition( float x, float y );
	void SetSrcSize( OtterVector2f size );
	void SetSrcSize( float width, float height );
	void SetDrawMode( DWORD drawMode );
	void SetTransparent( bool isTransparent, UINT rgb = RGB(0, 0, 0) );

	const BITMAP GetBitmapInfo();

private:
	bool CreateBitmapInfo();

private:
	bool mIsTransparent;
	UINT mTransparentRGB;
	HBITMAP mBitmap;
	BITMAP mBitmapInfo;
	OtterVector2f mDestScale;
	OtterVector2f mDestSize;
	OtterVector2f mSrcPosition;
	OtterVector2f mSrcSize;
	OtterRect2f mSrcRect;
	DWORD mDrawMode;
};


#endif 