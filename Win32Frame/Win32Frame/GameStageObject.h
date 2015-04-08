#ifndef __GAMESTAGE_OBJECT_H__
#define __GAMESTAGE_OBJECT_H__

#include "StageDisplayObject.h"
#include "BlockObject.h"
#include <string>

class GameStageObject : public Object
{
private:
	enum LINE
	{
		VERTICAL,
		HORIZONTAL
	};

public:
	GameStageObject( int width, int height );
	GameStageObject( int width, int height, int size );
	~GameStageObject();	

	void Update( float dt );
	void Draw( HDC hdc );

	void Translate( float x, float y );
	void Translate( OtterVector2f trans );
	void SetPosition( float x, float y );
	void SetPosition( OtterVector2f pos );

	void SetDefaultColor( COLORREF color );
	void SetBlock( int blockamount, int maxBlockCount, int BlockSize );

	// for TestFunction
	void BlockCheck( OtterRect2f rect, COLORREF color );

	int RectCheck( OtterRect2f rect );
	bool BlockObjectCheck( BlockObject& block, bool changeColor = true );
	int BlockObjectClickCheck( OtterVector2i mousepos );

private:
	void DeleteBlockCheck();
	void DeleteBlockLine( int line, LINE vh );
	bool CheckCanPlaceBlock( BlockObject& block );

private:
	BlockObject* mBlockList;
	StageDisplayObject mDisplayObject;
	COLORREF mDefaultColor;
	COLORREF* mColorList;
	bool mBlockCheck, mCreateNewBlock, mGameOver;
	int mWidth, mHeight, mBlockCount;
	int mMaxBlockCount, mBlockSize;

	std::wstring mDebugStr;
};

#endif