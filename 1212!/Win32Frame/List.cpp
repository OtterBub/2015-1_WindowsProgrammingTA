#include "List.h"

template<typename T>
OtterList<T>::OtterList()
{
	mHeader.mNext = nullptr;
	count = 0;
}

template<typename T>
OtterList<T>::~OtterList()
{
	if( mHeader.mNext != nullptr )
	{
		Value<T>* temp = mHeader.mNext;
		Value<T>* curr = nullptr;
		while( temp->mNext != nullptr )
		{
			curr = temp;
			temp = temp->mNext;
			delete curr;
		}
		delete temp;
	}
}

template<typename T>
bool OtterList<T>::Add( T val )
{
	if( mHeader.mNext == nullptr )
	{
		mHeader.mNext = new Value<T>;
		mHeader.mNext->value = val;
		mHeader.mNext->mNext = nullptr;
	}
	else
	{
		Value<T>* temp = mHeader.mNext;
		Value<T>* lNew = new Value<T>;
		lNew->value = val;
		lNew->mNext = nullptr;

		while( temp->mNext != nullptr )
			temp = temp->mNext;

		temp->mNext = lNew;
	}
	count++;

	return true;
}
template<typename T>
int OtterList<T>::GetCount()
{
	return count;
}

template<typename T>
T OtterList<T>::operator []( int index )
{
	if( mHeader.mNext == nullptr )
	{		
		return 0;
	}
	else
	{
		Value<T>* temp = mHeader.mNext;
		for( int i = 0; ( i < index ) && ( temp->mNext != nullptr ); ++i )
		{
			temp = temp->mNext;
		}

		if( temp != nullptr )
			return temp->value;
		else
			return 0;
	}
}