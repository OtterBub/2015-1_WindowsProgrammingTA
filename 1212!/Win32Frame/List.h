#ifndef __LIST_H__
#define __LIST_H__

template< typename T >
class Value
{
public:
	T value;
	Value<T>* mNext;
};

template< typename T >
class ValueHeader
{
public:
	Value<T>* mNext;
};

template< typename T >
class OtterList
{
public:
	OtterList();
	~OtterList();

	bool Add( T val );
	int GetCount();

	T operator []( int index );

private:
	ValueHeader<T> mHeader;
	int count;
};

#endif