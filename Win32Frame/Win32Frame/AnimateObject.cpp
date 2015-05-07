#include "AnimateObject.h"

AnimateObject::AnimateObject()
{
	mAnimTime = 0;
	mAnimIndex = 0;
}
AnimateObject::~AnimateObject()
{
}

void AnimateObject::Update( double dt )
{
	if( mCurrentAnimClipName.size() > 0 ) {
		std::wstring lAnimName = mCurrentAnimClipName;
		

		mAnimTime += dt;
		if( mAnimationClip[lAnimName].mAnimationDlay < mAnimTime ) {
			AnimationClip animClip = mAnimationClip[lAnimName].clipVec[mAnimIndex];

			mAnimTime = 0;

			mBitmap.SetSrcSize( animClip.size.x, animClip.size.y );
			mBitmap.SetSrcPosition( animClip.pos.x, animClip.pos.y );
			mAnimIndex++;

			if( mAnimIndex >= mAnimationClip[lAnimName].clipVec.size() )
				mAnimIndex = 0;
		}
	}
}
void AnimateObject::Draw( HDC hdc )
{
	mBitmap.Draw( hdc );
}

void AnimateObject::Translate( float x, float y )
{
	Object::Translate( x, y );
	mBitmap.Translate( x, y );
}
void AnimateObject::Translate( const OtterVector2f& trans )
{
	Object::Translate( trans );
	mBitmap.Translate( trans );
}
void AnimateObject::SetPosition( float x, float y )
{
	Object::SetPosition( x, y );
	mBitmap.SetPosition( x, y );
}
void AnimateObject::SetPosition( const OtterVector2f& pos )
{
	Object::SetPosition( pos );
	mBitmap.SetPosition( pos );
}
void AnimateObject::SetScale( const OtterVector2f& scale )
{
	mBitmap.SetScale( scale );
}
void AnimateObject::SetScale( float scaleX, float scaleY )
{
	mBitmap.SetScale( scaleX, scaleY );
}
void AnimateObject::SetImageSize( const OtterVector2f& imgSize )
{
	mBitmap.SetDestSize( imgSize );
}
void AnimateObject::SetImageSize( float width, float height )
{
	mBitmap.SetDestSize( width, height );
}
void AnimateObject::SetDrawMode( DWORD drawMode )
{
	mBitmap.SetDrawMode( drawMode );
}
void AnimateObject::SetTransparent( bool isTransparent, UINT rgb )
{
	mBitmap.SetTransparent( isTransparent, rgb );
}

void AnimateObject::SetAnimClip( std::wstring animName )
{
	if( mCurrentAnimClipName == animName )
		return;
	std::wstring prevClipName = mCurrentAnimClipName;
	mCurrentAnimClipName = animName;
	std::unordered_map<std::wstring, AnimationClipInfo>::iterator it = mAnimationClip.find( animName );
	if( it == mAnimationClip.end() ) {
		mCurrentAnimClipName = prevClipName;
	} else {
		if( mAnimIndex >= mAnimationClip[animName].clipVec.size() )
			mAnimIndex = 0;
		AnimationClip animClip = mAnimationClip[animName].clipVec[mAnimIndex];

		mBitmap.SetSrcSize( animClip.size.x, animClip.size.y );
		mBitmap.SetSrcPosition( animClip.pos.x, animClip.pos.y );
	}
}
bool AnimateObject::LoadSpriteImage( std::wstring fileName )
{
	return mBitmap.FileLoad( fileName );
}
void AnimateObject::AutoCreateAnimation( std::wstring animName, float animDlay, const OtterVector2f& clipSize, 
										 const OtterVector2i& clipStartNumber, const OtterVector2i& clipEndNumber )
{
	std::unordered_map<std::wstring, AnimationClipInfo>::iterator it = mAnimationClip.find( animName );

	if( it != mAnimationClip.end() ) {
		mAnimationClip[animName].clipVec.clear();
	}

	for( int i = 0; clipEndNumber.y > i; ++i ) {
		for( int j = 0; clipEndNumber.x > j; ++j ) {
			AnimationClip animClip;
			animClip.size = clipSize;
			animClip.pos.x =clipSize.x * (j + clipStartNumber.x) ;
			animClip.pos.y =clipSize.y * (i + clipStartNumber.y);

			mAnimationClip[animName].clipVec.push_back( animClip );
		}
	}
	mAnimationClip[animName].mAnimationDlay = animDlay;
}