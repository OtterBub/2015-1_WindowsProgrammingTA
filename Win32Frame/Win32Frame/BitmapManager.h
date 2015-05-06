#ifndef __BITMAP_MGR_H__
#define __BITMAP_MGR_H__
#include <Windows.h>
#include <map>
#include <string>

class BitmapMGR
{
public:
	HBITMAP LoadFile( std::wstring filename );
	static BitmapMGR& GetInstance();

private:
	BitmapMGR();
	BitmapMGR( const BitmapMGR& other );

private:
	std::map<std::wstring, HBITMAP> mBitmap;
};

#define BITMAP_MGR BitmapMGR::GetInstance()

#endif 