#ifndef __BLOCK_OBJECT_H__
#define __BLOCK_OBJECT_H__

#include "Object.h"
#include "GDIRect.h"
#include <vector>

enum DIR
{
	RIGHT,
	LEFT,
	UP,
	DOWN
};

class BlockObject : public Object
{
public:
	BlockObject();
	BlockObject( const BlockObject& other );
	BlockObject( int blockCount, int size );
	~BlockObject();

	void Update( float dt );
	void Draw( HDC hdc );

	void Translate( float x, float y );
	void Translate( OtterVector2f trans );
	void SetPosition( float x, float y );
	void SetPosition( OtterVector2f pos );
	void SetBlock( int blockCount, int size );
	void SetColor( COLORREF color );
	void SetUsed( bool set );
	void SetAddBody( Vec2 addForce = Vec2( 0, 0 ) );

	bool CollisionCheck( OtterVector2i pos );

	GDIRect* GetRectList();
	std::vector<GDIRect> GetRectListvec();
	int GetBlockCount();
	bool GetUsed();
	OtterVector2f GetMaxPosition();

private:
	OtterVector2f GetRandPosition( int dir );
	void CreateBlock();

private:
	int mBlockCount, mSize;
	int* mDirList;
	bool mIsUsed;
	GDIRect* mRectList;
	std::vector<GDIRect> mRectListvec;
};

#endif 