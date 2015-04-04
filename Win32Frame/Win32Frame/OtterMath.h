#ifndef __OTTERVECTOR_H__
#define __OTTERVECTOR_H__

template<typename T>
class OtterVector2
{
public:
	template<typename U>
	OtterVector2( const OtterVector2<U> other );
	OtterVector2();
	OtterVector2( T x, T y );
	~OtterVector2();

	bool Set( T x , T y );

	void operator +=( const OtterVector2<T> a );
	void operator -=( const OtterVector2<T> a );

public:
	T x, y;
};

template<typename T>
class OtterRect2
{
public:
	OtterRect2( OtterVector2<T> point1, OtterVector2<T> point2 );
	OtterRect2();
	~OtterRect2();

	void operator +=( const OtterVector2<T> trans );
	void operator -=( const OtterVector2<T> trans );

public:
	OtterVector2<T> point[2];
};

typedef OtterVector2<double> OtterVector2d;
typedef OtterVector2<float> OtterVector2f;
typedef OtterVector2<int> OtterVector2i;
typedef OtterVector2<unsigned int> OtterVector2ui;

typedef OtterRect2<double> OtterRect2d;
typedef OtterRect2<float> OtterRect2f;
typedef OtterRect2<int> OtterRect2i;
typedef OtterRect2<unsigned int> OtterRect2ui;

template<typename T>
OtterVector2<T> operator+( const OtterVector2<T> a, const OtterVector2<T> b );

template<typename T>
OtterVector2<T> operator-( const OtterVector2<T> a, const OtterVector2<T> b );

template<typename T>
OtterVector2<T> operator*( const OtterVector2<T> a, const float b );

#endif