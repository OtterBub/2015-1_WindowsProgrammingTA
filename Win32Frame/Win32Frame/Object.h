#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "OtterMath.h"
#include <Windows.h>

class Object
{
public:
	Object();
	virtual ~Object();

	virtual void Update( double dt );
	virtual void Draw( HDC hdc ) = 0;

	virtual void Translate( float x, float y );
	virtual void Translate( const OtterVector2f& trans );
	virtual void SetPosition( float x, float y );
	virtual void SetPosition( const OtterVector2f& pos );

	const OtterVector2f& GetPosition();

protected:
	
	
protected:
	OtterVector2f mPosition;
};

#endif __OBJECT_H__