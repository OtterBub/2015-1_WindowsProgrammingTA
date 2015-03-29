#include "Object.h"

Object::Object(){}
Object::~Object(){}

void Object::Translate( int x, int y )
{
	mPosition.x += x;
	mPosition.y += y;
}

void Object::Translate( OtterVector2i trans )
{
	mPosition += trans;
}