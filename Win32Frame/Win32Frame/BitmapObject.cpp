#include "BitmapObject.h"
#include "Win32Frame.h"

#ifdef UNICODE
#define LoadImage  LoadImageW
#else
#define LoadImage  LoadImageA
#endif // !UNICODE

BitmapObject::BitmapObject()
{
	mBitmap = NULL;
}
#ifdef UNICODE
BitmapObject::BitmapObject( std::wstring filename )
{
	mBitmap = (HBITMAP)LoadImage( WIN32FRAME.GetHInstance(), filename.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	GetBitmapInfo();
}
bool BitmapObject::FileLoad( std::wstring filename )
{
	if( mBitmap != NULL )
		DeleteObject( mBitmap );
	mBitmap = (HBITMAP)LoadImage( WIN32FRAME.GetHInstance(), filename.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	GetBitmapInfo();
	return true;
}
#else
BitmapObject::BitmapObject( std::string filename )
{
	mBitmap = (HBITMAP)LoadImage( WIN32FRAME.GetHInstance(), filename.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	GetBitmapInfo();
}
bool BitmapObject::FileLoad( std::string filename )
{
	if( mBitmap != NULL )
		DeleteObject( mBitmap );
	mBitmap = (HBITMAP)LoadImage( WIN32FRAME.GetHInstance(), filename.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	GetBitmapInfo();
	return true;
}
#endif
BitmapObject::~BitmapObject()
{
	if( mBitmap != NULL )
		DeleteObject( mBitmap );
}



void BitmapObject::Update( float dt )
{
}
void BitmapObject::Draw( HDC hdc )
{
	HDC BitmapDC;
	BitmapDC = CreateCompatibleDC( hdc );
	SelectObject( BitmapDC, mBitmap );
	BitBlt( hdc, 
			mPosition.x - ( mBitmapInfo.bmWidth / 2 ), mPosition.y - ( mBitmapInfo.bmHeight / 2 ),
			mBitmapInfo.bmWidth, mBitmapInfo.bmHeight, 
			BitmapDC, 0, 0, SRCCOPY );

	DeleteDC( BitmapDC );
}

void BitmapObject::Translate( float x, float y )
{
	Object::Translate( x, y );
}
void BitmapObject::Translate( OtterVector2f trans )
{
	Object::Translate( trans );
}
void BitmapObject::SetPosition( float x, float y )
{
	Object::SetPosition( x, y );
}
void BitmapObject::SetPosition( OtterVector2f pos )
{
	Object::SetPosition( pos );
}

bool BitmapObject::GetBitmapInfo()
{
	GetObject( mBitmap, sizeof(BITMAP), &mBitmapInfo );
	return true;
}