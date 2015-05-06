#include "BitmapManager.h"
#include "Win32Frame.h"
#include <string>

HBITMAP BitmapMGR::LoadFile( std::wstring filename )
{
	if( mBitmap.find( filename ) != mBitmap.end() ){
		return mBitmap[filename];
	} else {
		mBitmap[filename] = (HBITMAP)LoadImage( WIN32FRAME.GetHInstance(), filename.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
		return mBitmap[filename];
	}
}
BitmapMGR& BitmapMGR::GetInstance()
{
	static BitmapMGR instance;
	return instance;
}

BitmapMGR::BitmapMGR()
{
}
BitmapMGR::BitmapMGR( const BitmapMGR& other )
{
}