#pragma once
#include "sensor.h"
#include "ship.h"
#include "projectile.h"

class I_CollisionHandler {
public:
    virtual void check_friendly_sensor_collisions() = 0;
    virtual void check_enemy_sensor_collisions() = 0;
    virtual void check_friendly_projectile_collisions() = 0;
    virtual void check_enemy_projectile_collisions() = 0;
    virtual void check_friendly_ship_collisions() = 0;
    virtual void check_enemy_ship_collisions() = 0;

    virtual void add_friendly_sensor(Sensor *friendly_sensor) = 0;
    virtual void add_friendly_ship(Ship *friendly_ship) = 0; 
    virtual void add_friendly_projectile(Projectile *friendly_projectile) = 0; 
    virtual void add_enemy_sensor(Sensor *enemy_sensor) = 0; 
    virtual void add_enemy_ship(Ship *enemy_ship) = 0; 
    virtual void add_enemy_projectile(Projectile *enemy_projectile) = 0; 

    virtual void remove_friendly_sensor(Sensor *friendly_sensor) = 0; 
    virtual void remove_friendly_ship(Ship *friendly_ship) = 0; 
    virtual void remove_friendly_projectile(Projectile *friendly_projectile) = 0; 
    virtual void remove_enemy_sensor(Sensor *enemy_sensor) = 0; 
    virtual void remove_enemy_ship(Ship *enemy_ship) = 0; 
    virtual void remove_enemy_projectile(Projectile *enemy_projectile) = 0; 

};