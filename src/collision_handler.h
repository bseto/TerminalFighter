#pragma once
#include <map>

#include "I_collision_handler.h"
#include "sensor.h"
#include "projectile.h"
#include "ship.h"
#include "collision_detector.h"

class CollisionHandler : public I_CollisionHandler {
public:
    CollisionHandler(CollisionDetector cd);

    void check_friendly_sensor_collisions();
    void check_enemy_sensor_collisions();
    void check_friendly_projectile_collisions();
    void check_enemy_projectile_collisions();
    void check_friendly_ship_collisions();
    void check_enemy_ship_collisions();

    void add_friendly_sensor(Sensor *friendly_sensor);
    void add_friendly_ship(Ship *friendly_ship); 
    void add_friendly_projectile(Projectile *friendly_projectile); 
    void add_enemy_sensor(Sensor *enemy_sensor); 
    void add_enemy_ship(Ship *enemy_ship); 
    void add_enemy_projectile(Projectile *enemy_projectile); 

    void remove_friendly_sensor(Sensor *friendly_sensor); 
    void remove_friendly_ship(Ship *friendly_ship); 
    void remove_friendly_projectile(Projectile *friendly_projectile); 
    void remove_enemy_sensor(Sensor *enemy_sensor); 
    void remove_enemy_ship(Ship *enemy_ship); 
    void remove_enemy_projectile(Projectile *enemy_projectile); 


  

private:
    std::map<int, Sensor*> friendly_sensors_;
    std::map<int, Sensor*> enemy_sensors_;
    std::map<int, Projectile*> friendly_projectiles_;
    std::map<int, Projectile*> enemy_projectiles_;
    std::map<int, Ship*> friendly_ships_;
    std::map<int, Ship*> enemy_ships_;
    CollisionDetector collision_detector_; 
}; 