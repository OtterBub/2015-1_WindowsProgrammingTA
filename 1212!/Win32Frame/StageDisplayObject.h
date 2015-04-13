#ifndef __STAGEDISPLAY_OBJECT_H__
#define __STAGEDISPLAY_OBJECT_H__

#include <vector>
#include "GDIRect.h"

enum BOARD_TYPE
{
	CORNER,
	BLANK,
	DEFAULT
};

class StageDisplayObject : public Object
{
public:
	StageDisplayObject( int width, int height );
	StageDisplayObject( int width, int height, int size );
	~StageDisplayObject();

	void Update( float dt );
	void Draw( HDC hdc );

	void Translate( float x, float y );
	void Translate( OtterVector2f trans );
	void SetPosition( float x, float y );
	void SetPosition( OtterVector2f pos );

	void SetSize( int size );
	void SetIndexColor( int index, COLORREF color );
	void SetPositionColor( OtterVector2f pos, COLORREF color );
	void SetBoardType( int type );
	void SetAddBody( Vec2 addForce = Vec2( 0, 0 ) );

	int GetCollisionIndex( OtterVector2f point );
	int GetCollisionIndex( OtterRect2f rect );
	int GetTotal();
	bool* GetIgnoreList();
	GDIRect* GetRectList();
	std::vector<int> GetCollisionIndexes( OtterRect2f rect );
	COLORREF GetColorRef( int index );
	COLORREF GetColorRef( int x, int y );
	COLORREF GetColorRef( OtterVector2f index );

private:
	int mWidth, mHeight, mSize, mTotal, mBoardType;
	bool* mIgnoreIndex;
	COLORREF mDefaultColor;
	GDIRect* mRectList;
};

#endif __STAGEDISPLAY_OBJECT_H__