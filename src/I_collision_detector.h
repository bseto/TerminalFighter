#pragma once
#include "hitbox.h"

class I_CollisionDetector {
public:
	virtual bool is_overlapping(Hitbox hb1, Hitbox hb2) = 0; 

}