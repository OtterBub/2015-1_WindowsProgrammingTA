#ifndef __OTTERVECTOR_H__
#define __OTTERVECTOR_H__

template<typename T>
class OtterVector2
{
public:
	OtterVector2( T x, T y );
	OtterVector2();
	~OtterVector2();

	bool Set( T x , T y );

	void operator +=( const OtterVector2<T> a );

public:
	T x, y;
};

typedef OtterVector2<double> OtterVector2d;
typedef OtterVector2<float> OtterVector2f;
typedef OtterVector2<int> OtterVector2i;
typedef OtterVector2<unsigned int> OtterVector2ui;

template<typename T>
OtterVector2<T> operator+( const OtterVector2<T> a, const OtterVector2<T> b );

template<typename T>
OtterVector2<T> operator-( const OtterVector2<T> a, const OtterVector2<T> b );

template<typename T>
OtterVector2<T> operator*( const OtterVector2<T> a, const float b );

#endif