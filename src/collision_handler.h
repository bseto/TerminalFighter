#pragma once
#include <vector>

#include "I_collision_handler.h"
#include "sensor.h"
#include "projectile.h"
#include "ship.h"

class CollisionHandler : public I_CollisionHandler {
public:
    CollisionHandler(CollisionDetector cd);

    


  

private:
    std::vector<Sensor*> friendly_sensors_;
    std::vector<Sensor*> enemy_sensors_;
    std::vector<Projectile*> friendly_projectiles_;
    std::vector<Projectile*> enemy_projectiles_;
    std::vector<Ship*> friendly_ships_;
    std::vector<Ship*> enemy_ships_;
    CollisionDetector collision_detector_; 
}; 