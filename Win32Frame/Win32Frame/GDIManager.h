#ifndef __GDIMANAGER_H__
#define __GDIMANAGER_H__
#include <Windows.h>
#include <unordered_map>

class GDIManager
{
private:
public:
	std::unordered_map< COLORREF, HBRUSH > brush;
	std::unordered_map< COLORREF, HPEN > pen;
};

#endif 