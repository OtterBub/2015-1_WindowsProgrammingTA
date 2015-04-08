#ifndef __GDI_BUTTON_H__
#define __GDI_BUTTON_H__

#include "GDIRect.h"
#include <string>

class GDIButton : public GDIRect
{
public:
	GDIButton();
	~GDIButton();

	void Draw( HDC hdc );

	void SetText( std::wstring str );

	bool CheckClick( OtterVector2i mousePos );

private:
	std::wstring mButtonText;
};

#endif