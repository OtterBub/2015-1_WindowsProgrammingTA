#include "Object.h"

Object::Object(){}
Object::~Object(){}

void Object::Update( float dt )
{}

void Object::Translate( float x, float y )
{
	mPosition.x += x;
	mPosition.y += y;
}

void Object::Translate( OtterVector2f trans )
{
	mPosition += trans;
}

OtterVector2f Object::GetPosition()
{
	return mPosition;
}

void Object::SetPosition( float x, float y )
{
	mPosition.x = x;
	mPosition.y = y;
}

void Object::SetPosition( OtterVector2f pos )
{
	mPosition = pos;
}