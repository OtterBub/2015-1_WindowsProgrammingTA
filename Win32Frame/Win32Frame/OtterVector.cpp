#ifndef __OTTERVECTOR_CPP__
#define __OTTERVECTOR_CPP__

#include "OtterVector.h"
#include <list>

template<typename T>
OtterVector2<T>::OtterVector2( T x, T y )
{
	this->x = x;
	this->y = y;
}

template<typename T>
OtterVector2<T>::OtterVector2()
{
	this->x = 0;
	this->y = 0;
}

template<typename T>
OtterVector2<T>::~OtterVector2()
{
}

template<typename T>
bool OtterVector2<T>::Set( T x, T y )
{
	this->x = x;
	this->y = y;
}

template<typename T>
void OtterVector2<T>::operator +=( const OtterVector2<T> a )
{
	this->x += a.x;
	this->y += a.y;
}

template<typename T>
OtterVector2<T> operator +( const OtterVector2<T> a, const OtterVector2<T> b )
{
	OtterVector2<T> temp;
	temp.x = a.x + b.x;
	temp.y = a.y + b.y;
	return temp;
}

template<typename T>
OtterVector2<T> operator-( const OtterVector2<T> a, const OtterVector2<T> b )
{
	OtterVector2<T> temp;
	temp.x = a.x - b.x;
	temp.y = a.y - b.y;
	return temp;
}

template<typename T>
OtterVector2<T> operator*( const OtterVector2<T> a, const float b )
{
	OtterVector2<T> temp = a;
	temp.x *= b;
	temp.y *= b;
	return temp;
}

#endif 