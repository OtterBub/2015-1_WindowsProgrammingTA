#include "GDIRect.h"
#include <math.h>
#include "Win32Frame.h"

GDIRect::GDIRect()
{
	mSize = 50;
	mBody.Set( Vec2(mSize, mSize), 10 );
}

GDIRect::~GDIRect()
{
}

void GDIRect::Draw( HDC hdc )
{
	GDIObject::CreateMyObject();
	GDIObject::Draw( hdc );
	POINT point[4];
	/*point[0].x = mRectf.point[0].x;
	point[0].y = mRectf.point[0].y;
	point[1].x = mRectf.point[0].x;
	point[1].y = mRectf.point[1].y;
	point[2].x = mRectf.point[1].x;
	point[2].y = mRectf.point[1].y;
	point[3].x = mRectf.point[1].x;
	point[3].y = mRectf.point[0].y;*/
	/*Mat22 R(WIN32FRAME.GetBodyList()[mBodyIndex].rotation);
	Vec2 x = WIN32FRAME.GetBodyList()[mBodyIndex].position;
	Vec2 h = 0.5f * WIN32FRAME.GetBodyList()[mBodyIndex].width;*/

	Mat22 R(mBody.rotation);
	Vec2 x = mBody.position;
	Vec2 h = 0.5f * mBody.width;

	Vec2 v1 = x + R * Vec2(-h.x, -h.y);
	Vec2 v2 = x + R * Vec2( h.x, -h.y);
	Vec2 v3 = x + R * Vec2( h.x,  h.y);
	Vec2 v4 = x + R * Vec2(-h.x,  h.y);	

	point[0].x = v1.x;
	point[0].y = v1.y;
	point[1].x = v2.x;
	point[1].y = v2.y;
	point[2].x = v3.x;
	point[2].y = v3.y;
	point[3].x = v4.x;
	point[3].y = v4.y;

	//Rectangle( hdc, mRectf.point[0].x, mRectf.point[0].y, mRectf.point[1].x, mRectf.point[1].y );
	
	Polygon( hdc, point, 4);
	GDIObject::DeleteMyObject();
}

void GDIRect::Translate( float x, float y )
{
	Object::Translate( x, y );
	float halfWidth = abs( mRectf.point[1].x - mRectf.point[0].x ) / 2;
	float halfHeight = abs( mRectf.point[1].y - mRectf.point[0].y ) / 2;
	mRectf.point[0].x = mPosition.x - halfWidth;
	mRectf.point[1].x = mPosition.x + halfWidth;

	mRectf.point[0].y = mPosition.y - halfHeight;
	mRectf.point[1].y = mPosition.y + halfHeight;

	mBody.position.x = mPosition.x;
	mBody.position.y = mPosition.y;
}

void GDIRect::Translate( OtterVector2f trans )
{
	Object::Translate( trans );
	float halfWidth = abs( mRectf.point[1].x - mRectf.point[0].x ) / 2;
	float halfHeight = abs( mRectf.point[1].y - mRectf.point[0].y ) / 2;
	mRectf.point[0].x = mPosition.x - halfWidth;
	mRectf.point[1].x = mPosition.x + halfWidth;

	mRectf.point[0].y = mPosition.y - halfHeight;
	mRectf.point[1].y = mPosition.y + halfHeight;

	mBody.position.x = mPosition.x;
	mBody.position.y = mPosition.y;
}

void GDIRect::SetPosition( float x, float y )
{
	Object::SetPosition( x, y );
	float halfWidth = abs( mRectf.point[1].x - mRectf.point[0].x ) / 2;
	float halfHeight = abs( mRectf.point[1].y - mRectf.point[0].y ) / 2;
	mRectf.point[0].x = mPosition.x - halfWidth;
	mRectf.point[1].x = mPosition.x + halfWidth;

	mRectf.point[0].y = mPosition.y - halfHeight;
	mRectf.point[1].y = mPosition.y + halfHeight;

	mBody.position.x = x;
	mBody.position.y = y;
}

void GDIRect::SetPosition( OtterVector2f pos )
{
	Object::SetPosition( pos );
	float halfWidth = abs( mRectf.point[1].x - mRectf.point[0].x ) / 2;
	float halfHeight = abs( mRectf.point[1].y - mRectf.point[0].y ) / 2;
	mRectf.point[0].x = mPosition.x - halfWidth;
	mRectf.point[1].x = mPosition.x + halfWidth;

	mRectf.point[0].y = mPosition.y - halfHeight;
	mRectf.point[1].y = mPosition.y + halfHeight;

	mBody.position.x = pos.x;
	mBody.position.y = pos.y;
}


void GDIRect::SetRect( int x, int y, int size )
{
	SetPosition( x, y );
	mSize = size;

	mRectf.point[0].x = mPosition.x - ( mSize / 2 );
	mRectf.point[1].x = mPosition.x + ( mSize / 2 );
	
	mRectf.point[0].y = mPosition.y - ( mSize / 2 );
	mRectf.point[1].y = mPosition.y + ( mSize / 2 );

	mBody.position.x = x;
	mBody.position.y = y;
	mBody.width = Vec2( size, size );
	mBody.Set( mBody.width, mBody.mass );
}

void GDIRect::SetRect( OtterVector2f pos, int size )
{
	SetPosition( pos );
	mSize = size;

	mRectf.point[0].x = mPosition.x - ( mSize / 2 );
	mRectf.point[1].x = mPosition.x + ( mSize / 2 );
	
	mRectf.point[0].y = mPosition.y - ( mSize / 2 );
	mRectf.point[1].y = mPosition.y + ( mSize / 2 );

	mBody.position.x = pos.x;
	mBody.position.y = pos.y;
	mBody.width = Vec2( size, size );
	mBody.Set( mBody.width, mBody.mass );
}

void GDIRect::SetRect( int left, int top, int right, int bottom )
{
	SetPosition( left + abs( left - right ) / 2.f, top + abs( top - bottom ) / 2.f);

	mRectf.point[0].x = left;
	mRectf.point[1].x = right;
	
	mRectf.point[0].y = top;
	mRectf.point[1].y = bottom;

	mSize = abs( right - left );

	mBody.width = Vec2( abs( right - left ), abs( bottom - top ) );
	mBody.Set( mBody.width, mBody.mass );
}

void GDIRect::SetSize( int size )
{
	mSize = size;
	SetRect( mPosition, mSize );
}

void GDIRect::SetAddBody( Vec2 addForce )
{
	mBody.velocity = addForce;
	WIN32FRAME.GetWorldInstance().Add( &mBody );
}

void GDIRect::SetMass( float mass )
{
	mBody.Set( mBody.width, mass );
}

OtterRect2f GDIRect::GetRect()
{
	return mRectf;
}

Body& GDIRect::GetBody()
{
	return mBody;
}