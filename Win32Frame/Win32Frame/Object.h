#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "OtterVector.cpp"
#include <Windows.h>

class Object
{
public:
	Object();
	virtual ~Object();

	virtual void Draw( HDC hdc ) = 0;

	virtual void Translate( int x, int y );
	virtual void Translate( OtterVector2i trans );

protected:
	
	
protected:
	OtterVector2i mPosition;
};

#endif __OBJECT_H__