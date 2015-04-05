#ifndef __BLOCK_OBJECT_H__
#define __BLOCK_OBJECT_H__

#include "Object.h"
#include "GDIRect.h"

class BlockObject : public Object
{
private:
	enum CREATE_DIR
	{
		RIGHT,
		LEFT,
		UP,
		DOWN
	};

public:
	BlockObject( int blockCount, int size );
	~BlockObject();

	void Update( float dt );
	void Draw( HDC hdc );

	void Translate( float x, float y );
	void Translate( OtterVector2f trans );
	void SetPosition( float x, float y );
	void SetPosition( OtterVector2f pos );

	bool CollisionCheck( OtterVector2i pos );

private:
	OtterVector2f GetRandPosition( int dir );
	void CreateBlock();

private:
	int mBlockCount, mSize;
	int* mDirList;
	GDIRect* mRectList;
};

#endif 