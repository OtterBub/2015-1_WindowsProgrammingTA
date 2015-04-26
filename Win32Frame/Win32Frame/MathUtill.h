#ifndef __UTILL_H__
#define __UTILL_H__

#include "OtterMath.h"

template<typename T1, typename T2>
bool CollisionRectToPoint( OtterRect2<T1> rect, OtterVector2<T2> point );

template<typename T1, typename T2>
bool CollisionRectToRect( OtterRect2<T1> rect1, OtterRect2<T2> rect2 );

template<typename T1, typename T2, typename T3>
bool CollisionRectToRectRange( OtterRect2<T1> rect1, OtterRect2<T2> rect2, T3 range );

#endif //__UTILL_H__