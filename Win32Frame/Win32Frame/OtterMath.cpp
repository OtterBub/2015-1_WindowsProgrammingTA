#ifndef __OTTERVECTOR_CPP__
#define __OTTERVECTOR_CPP__

#include "OtterMath.h"

// ---------------------------- OtterVector2 ----------------------------
template<typename T>
template<typename U>
OtterVector2<T>::OtterVector2( const OtterVector2<U> other )
{
	this->x = other.x;
	this->y = other.y;
}

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
void OtterVector2<T>::operator -=( const OtterVector2<T> a )
{
	this->x -= a.x;
	this->y -= a.y;
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


// ---------------------------- OtterRect2 ----------------------------
template<typename T>
OtterRect2<T>::OtterRect2( OtterVector2<T> point1, OtterVector2<T> point2 )
{
	point[0] = point1;
	point[1] = point2;
}
template<typename T>
OtterRect2<T>::OtterRect2()
{
}
template<typename T>
OtterRect2<T>::~OtterRect2()
{
}

template<typename T>
void OtterRect2<T>::operator +=( const OtterVector2<T> trans )
{
	point[0] += trans;
	point[1] += trans;
}

template<typename T>
void OtterRect2<T>::operator -=( const OtterVector2<T> trans )
{
	point[0] -= trans;
	point[1] -= trans;
}


#endif 