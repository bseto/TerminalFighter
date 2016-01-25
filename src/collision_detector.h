#pragma once

#include "I_collision_detector.h"

class CollisionDetector : public I_CollisionDetector {
public:
   
  bool is_overlapping(Hitbox hitbox1, Hitbox hitbox2);

private:
 
};