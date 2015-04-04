#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "OtterMath.cpp"
#include <Windows.h>

class Object
{
public:
	Object();
	virtual ~Object();

	virtual void Draw( HDC hdc ) = 0;

	virtual void Translate( float x, float y );
	virtual void Translate( OtterVector2f trans );
	virtual void SetPosition( float x, float y );
	virtual void SetPosition( OtterVector2f pos );

	OtterVector2f GetPosition();

protected:
	
	
protected:
	OtterVector2f mPosition;
};

#endif __OBJECT_H__