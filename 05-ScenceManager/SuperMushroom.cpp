#include "SuperMushroom.h"

void CSuperMushroom::Render()
{
	animation_set->at(0)->Render(x, y);
}

void CSuperMushroom::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = x;
	t = y;
	r = x + SUPER_MUSHROOM_BBOX_WIDTH;
	b = y + SUPER_MUSHROOM_BBOX_HEIGHT;
}
