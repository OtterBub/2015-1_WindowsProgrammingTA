#ifndef __ANIMATE_OBJECT_H__
#define __ANIMATE_OBJECT_H__
#include "BitmapObject.h"
#include <unordered_map>
#include <vector>

struct AnimationClip
{
	OtterVector2f size;
	OtterVector2f pos;
};

struct AnimationClipInfo
{
	std::vector<AnimationClip> clipVec;
	float mAnimationDlay;
};

class AnimateObject : public Object
{
public:
	AnimateObject();
	~AnimateObject();

	void Update( double dt );
	void Draw( HDC hdc );

	void Translate( float x, float y );
	void Translate( const OtterVector2f& trans );
	void SetPosition( float x, float y );
	void SetPosition( const OtterVector2f& pos );
	void SetScale( const OtterVector2f& scale );
	void SetScale( float scaleX, float scaleY );
	void SetImageSize( const OtterVector2f& destSize );
	void SetImageSize( float width, float height );
	void SetDrawMode( DWORD drawMode );
	void SetTransparent( bool isTransparent, UINT rgb = RGB(0, 0, 0) );

	void SetAnimClip( std::wstring animName );
	bool LoadSpriteImage( std::wstring fileName );
	void AutoCreateAnimation( std::wstring animName, float animDlay, const OtterVector2f& clipSize, const OtterVector2i& clipStartNumber, const OtterVector2i& clipEndNumber );

private:
	BitmapObject mBitmap;
	double mAnimTime;
	unsigned int mAnimIndex;
	std::wstring mCurrentAnimClipName;
	std::unordered_map<std::wstring, AnimationClipInfo> mAnimationClip;
	std::vector<AnimationClip>::iterator mAnimClipItor;
};


#endif __ANIMATE_OBJECT_H__