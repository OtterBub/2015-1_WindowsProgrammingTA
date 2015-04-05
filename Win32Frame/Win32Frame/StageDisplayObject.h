#ifndef __STAGEDISPLAY_OBJECT_H__
#define __STAGEDISPLAY_OBJECT_H__

#include <vector>
#include "GDIRect.h"

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
	void SetPostionColor( OtterVector2f pos, COLORREF color );

	int GetCollisionIndex( OtterVector2f point );
	int GetCollisionIndex( OtterRect2f rect );
	std::vector<int> GetCollisionIndexes( OtterRect2f rect );
	COLORREF GetColorRef( int index );
	COLORREF GetColorRef( OtterVector2f index );

private:
	int mWidth, mHeight, mSize;
	bool mCheckBlock;
	COLORREF mDefaultColor;
	GDIRect* mRectList;
};

#endif __STAGEDISPLAY_OBJECT_H__