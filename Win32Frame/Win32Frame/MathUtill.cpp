#include "MathUtill.h"

template<typename T1, typename T2>
bool CollisionRectToPoint( OtterRect2<T1> rect, OtterVector2<T2> point )
{
	if( ( rect.point[0].x < point.x ) && ( rect.point[0].y < point.y ) &&
		( rect.point[1].x > point.x ) && ( rect.point[1].y > point.y ))
	{
		return true;
	}
	else
		return false;
}

template<typename T1, typename T2>
bool CollisionRectToRect( OtterRect2<T1> rect1, OtterRect2<T2> rect2 )
{
	if( ( rect1.point[1].x >= rect2.point[0].x ) && ( rect1.point[0].x <= rect2.point[1].x ) &&
		( rect1.point[1].y >= rect2.point[0].y ) && ( rect1.point[0].y <= rect2.point[1].y ))
	{
		return true;
	}
	else
		return false;
}