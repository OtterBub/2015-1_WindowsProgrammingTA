#ifndef __ANIMATE_CREATOR_H__
#define __ANIMATE_CREATOR_H__

#include "AnimateObject.h"
#include <memory>
#include <string>

class AnimateCreator
{
public:
	AnimateObject GetAnimObj( std::wstring objname );
	static AnimateCreator& GetInstance();
private:
	AnimateCreator();
};

#define ANIM_CREATOR AnimateCreator::GetInstance()

#endif __ANIMATE_CREATOR_H__