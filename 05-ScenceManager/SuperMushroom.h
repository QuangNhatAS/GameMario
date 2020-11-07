#pragma once
#include "GameObject.h"

#define SUPER_MUSHROOM_BBOX_WIDTH	16
#define SUPER_MUSHROOM_BBOX_HEIGHT	16
class CSuperMushroom : public CGameObject
{
public:
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
};

