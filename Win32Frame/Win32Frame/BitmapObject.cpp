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
	mDestScale = OtterVector2f( 1, 1 );
}
#ifdef UNICODE
BitmapObject::BitmapObject( std::wstring filename )
{
	mBitmap = (HBITMAP)LoadImage( WIN32FRAME.GetHInstance(), filename.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	GetBitmapInfo();
	mDestSize = OtterVector2f( mBitmapInfo.bmWidth, mBitmapInfo.bmHeight );
	mDestScale = OtterVector2f( 1, 1 );
	mSrcRect = OtterRect2f( 0, 0, mDestSize.x, mDestSize.y );
}
bool BitmapObject::FileLoad( std::wstring filename )
{
	if( mBitmap != NULL )
		DeleteObject( mBitmap );
	mBitmap = (HBITMAP)LoadImage( WIN32FRAME.GetHInstance(), filename.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	GetBitmapInfo();
	mDestSize = OtterVector2f( mBitmapInfo.bmWidth, mBitmapInfo.bmHeight );
	mDestScale = OtterVector2f( 1, 1 );
	mSrcRect = OtterRect2f( 0, 0, mDestSize.x, mDestSize.y );
	return true;
}
#else
BitmapObject::BitmapObject( std::string filename )
{
	mBitmap = (HBITMAP)LoadImage( WIN32FRAME.GetHInstance(), filename.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	GetBitmapInfo();
	mDestSize = OtterVector2f( mBitmapInfo.bmWidth, mBitmapInfo.bmHeight );
}
bool BitmapObject::FileLoad( std::string filename )
{
	if( mBitmap != NULL )
		DeleteObject( mBitmap );
	mBitmap = (HBITMAP)LoadImage( WIN32FRAME.GetHInstance(), filename.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	GetBitmapInfo();
	mDestSize = OtterVector2f( mBitmapInfo.bmWidth, mBitmapInfo.bmHeight );
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
	/*BitBlt( hdc, 
			mPosition.x - ( mBitmapInfo.bmWidth / 2 ), mPosition.y - ( mBitmapInfo.bmHeight / 2 ),
			mBitmapInfo.bmWidth, mBitmapInfo.bmHeight, 
			BitmapDC, 0, 0, SRCCOPY );*/
	StretchBlt( hdc, 
				mPosition.x - ( mBitmapInfo.bmWidth / 2 ), mPosition.y - ( mBitmapInfo.bmHeight / 2 ),
				mDestSize.x * mDestScale.x, mDestSize.y * mDestScale.y,
				BitmapDC, 
				mSrcRect.point[0].x, mSrcRect.point[0].y,
				mSrcRect.point[1].x, mSrcRect.point[1].y, SRCCOPY );
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

void BitmapObject::SetScale( OtterVector2f scale )
{
	mDestScale = scale;
}
void BitmapObject::SetScale( float scaleX, float scaleY )
{
	mDestScale.x = scaleX;
	mDestScale.y = scaleY;
}
void BitmapObject::SetDestSize( OtterVector2f destSize )
{
	mDestSize = destSize;
}
void BitmapObject::SetDestSize( float width, float height )
{
	mDestSize.x = width;
	mDestSize.y = height;
}
void BitmapObject::SetSrcRect( OtterRect2f srcRect )
{
	mSrcRect = srcRect;
}
void BitmapObject::SetSrcRect( OtterVector2f point1, OtterVector2f point2 )
{
	mSrcRect = OtterRect2f( point1, point2 );
}
void BitmapObject::SetSrcRect( float x1, float y1, float x2, float y2 )
{
	mSrcRect = OtterRect2f( x1, y1, x2, y2 );
}

bool BitmapObject::GetBitmapInfo()
{
	GetObject( mBitmap, sizeof(BITMAP), &mBitmapInfo );
	return true;
}