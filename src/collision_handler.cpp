#include "collision_handler.h"
#include "hitbox.h"

void CollisionHandler::check_friendly_sensor_collisions() {
    //check friendly_sensors_ against enemy_sensors_, enemy_projectiles_, enemy_ships_
    for (auto friendly_sensor : friendly_sensors_) {
        std::vector<Hitbox> friendly_sensor_hitboxes = friendly_sensor->get_hitboxes();
		int hitbox_number = 0;
        for (auto friendly_hitbox : friendly_sensor_hitboxes) {
            
            
            for (auto enemy_sensor : enemy_sensors_) {
                for (auto enemy_hitbox : enemy_sensor->get_hitboxes()) {
                    if (collision_detector_.is_overlapping(friendly_hitbox, enemy_hitbox)) {
                        friendly_sensor->notify_collision(enemy_sensor, hitbox_number);
                    }
                }
            }
            for (auto enemy_projectile : enemy_projectiles_) {
                for (auto enemy_hitbox : enemy_projectile->get_hitboxes()) {
                    if (collision_detector_.is_overlapping(friendly_hitbox,enemy_hitbox)) {
                        friendly_sensor->notify_collision(enemy_projectile, hitbox_number);
                    }
                }
            }
            for (auto enemy_ship : enemy_ships_) {
                for (auto enemy_hitbox : enemy_ship->get_hitboxes()) {
                    if (collision_detector_.is_overlapping(friendly_hitbox, enemy_hitbox)) {
                        friendly_sensor->notify_collision(enemy_ship, hitbox_number);
                    }
                }
            }

            hitbox_number++;
        }
    }
}

void CollisionHandler::check_enemy_sensor_collisions() {
    //check enemy_sensors_ against friendly_sensors_, friendly_projectiles_, friendly_ships_
    for (auto enemy_sensor : enemy_sensors_) {
        std::vector<Hitbox> enemy_sensor_hitboxes = enemy_sensor->get_hitboxes();
		int hitbox_number = 0;
        for (auto enemy_hitbox : enemy_sensor_hitboxes) {
            
            
            for (auto friendly_sensor : friendly_sensors_) {
                for (auto friendly_sensor_hitbox : friendly_sensor->get_hitboxes()) {
                    if (collision_detector_.is_overlapping(enemy_hitbox, friendly_sensor_hitbox)) {
                        enemy_sensor->notify_collision(friendly_sensor, hitbox_number);
                    }
                }
            }
            for (auto friendly_projectile : friendly_projectiles_) {
                for (auto friendly_hitbox : friendly_projectile->get_hitboxes()) {
                    if (collision_detector_.is_overlapping(enemy_hitbox, friendly_hitbox)) {
                        enemy_sensor->notify_collision(friendly_projectile, hitbox_number);
                    }
                }
            }
            for (auto friendly_ship : friendly_ships_) {
                for (auto friendly_hitbox : friendly_ship->get_hitboxes()) {
                    if (collision_detector_.is_overlapping(enemy_hitbox, friendly_hitbox)) {
                        enemy_sensor->notify_collision(friendly_ship, hitbox_number);
                    }
                }
            }
            hitbox_number++;
        }
    }
}

void CollisionHandler::check_friendly_projectile_collisions() {
    //check friendly_projectiles_ against enemy_projectiles_, check_enemy_ship_, CHECK ENEMY SENSORS?? 
    for (auto friendly_projectile : friendly_projectiles_) {
        std::vector<Hitbox> friendly_projectile_hitboxes = friendly_projectile->get_hitboxes();
		int hitbox_number = 0;
        for (auto friendly_projectile_hitbox : friendly_projectile_hitboxes) {
            
            for (auto enemy_projectile : enemy_projectiles_) {
                for (auto enemy_hitbox : enemy_projectile->get_hitboxes()) {
                    if (collision_detector_.is_overlapping(friendly_projectile_hitbox, enemy_hitbox)) {
                        friendly_projectile->notify_collision(enemy_projectile, hitbox_number);
                    }
                }
            }
            for (auto enemy_ship : enemy_ships_) {
                for (auto enemy_hitbox : enemy_ship->get_hitboxes()) {
                    if (collision_detector_.is_overlapping(friendly_projectile_hitbox, enemy_hitbox)) {
                        friendly_projectile->notify_collision(enemy_ship, hitbox_number);
                    }
                }
            }

            hitbox_number++;
        }
    }
}

void CollisionHandler::check_enemy_projectile_collisions() {
    //check enemy_projectiles_ against friendly_projectiles_, friendly_ships_
	for (auto enemy_projectile : enemy_projectiles_) {
        std::vector<Hitbox> enemy_projectile_hitboxes = enemy_projectile->get_hitboxes();
		int hitbox_number = 0;
        for (auto enemy_projectile_hitbox : enemy_projectile_hitboxes) {
            
            for (auto friendly_projectile : friendly_projectiles_) {
                for (auto friendly_hitbox : friendly_projectile->get_hitboxes()) {
                    if (collision_detector_.is_overlapping(enemy_projectile_hitbox, friendly_hitbox)) {
                        enemy_projectile->notify_collision(friendly_projectile, hitbox_number);
                    }
                }
            }
            for (auto friendly_ship : friendly_ships_) {
                for (auto friendly_hitbox : friendly_ship->get_hitboxes()) {
                    if (collision_detector_.is_overlapping(enemy_projectile_hitbox, friendly_hitbox)) {
                        enemy_projectile->notify_collision(friendly_ship, hitbox_number);
                    }
                }
            }

            hitbox_number++;
        }
    }
    
}

void CollisionHandler::check_friendly_ship_collisions() {
    //check friendly_ships_ against enemy_ships_

 for (auto friendly_ship : friendly_ships_) {
        std::vector<Hitbox> friendly_ship_hitboxes = friendly_ship->get_hitboxes();
		int hitbox_number = 0;
        for (auto friendly_ship_hitbox : friendly_ship_hitboxes) {
            
            for (auto enemy_ship : enemy_ships_) {
                for (auto enemy_hitbox : enemy_ship->get_hitboxes()) {
                    if (collision_detector_.is_overlapping(friendly_ship_hitbox, enemy_hitbox)) {
                        friendly_ship->notify_collision(enemy_ship, hitbox_number);
                    }
                }
            }

            hitbox_number++;
        }
    }
}

void CollisionHandler::check_enemy_ship_collisions() {
    //check enemy_ships_ against friendlys_ships_
    for (auto enemy_ship : enemy_ships_) {
        std::vector<Hitbox> enemy_ship_hitboxes = enemy_ship->get_hitboxes();
		int hitbox_number = 0;
        for (auto enemy_ship_hitbox : enemy_ship_hitboxes) {
            
            for (auto friendly_ship : friendly_ships_) {
                for (auto friendly_hitbox : friendly_ship->get_hitboxes()) {
                    if (collision_detector_.is_overlapping(enemy_ship_hitbox, friendly_hitbox)) {
                        enemy_ship->notify_collision(friendly_ship, hitbox_number);
                    }
                }
            }

            hitbox_number++;
        }
    }
}

/*** ADD FUNCTIONS ***/
void CollisionHandler::add_friendly_sensor(Sensor *friendly_sensor) {
    friendly_sensors_[friendly_sensor->id()] = friendly_sensor; 
}

void CollisionHandler::add_friendly_ship(Ship *friendly_ship){
   friendly_ships_[friendly_ship->id()] = friendly_ship; 
}

void CollisionHandler::add_friendly_projectile(Projectile *friendly_projectile){
    friendly_projectiles_[friendly_projectile->id()] = friendly_projectile; 
}

void CollisionHandler::add_enemy_sensor(Sensor *enemy_sensor){
    enemy_sensors_[enemy_sensor->id()] = enemy_sensor; 
    
}

void CollisionHandler::add_enemy_ship(Ship *enemy_ship){
    enemy_ships_[enemy_ship->id()] = enemy_ship; 
}

void CollisionHandler::add_enemy_projectile(Projectile *enemy_projectile){
     enemy_projectiles_[enemy_projectile->id()] = enemy_projectile; 
}

/*** REMOVE FUNCTIONS ***/ 

void CollisionHandler::remove_friendly_sensor(Sensor *friendly_sensor){
   friendly_sensors_.erase(friendly_sensor->id());
}
void CollisionHandler::remove_friendly_ship(Ship *friendly_ship){
    friendly_ships_.erase(friendly_ship->id());
}
void CollisionHandler::remove_friendly_projectile(Projectile *friendly_projectile){
    friendly_projectiles_.erase(friendly_projectile->id());
}
void CollisionHandler::remove_enemy_sensor(Sensor *enemy_sensor){
    enemy_sensors_.erase(enemy_sensor->id());
}
void CollisionHandler::remove_enemy_ship(Ship *enemy_ship){
    enemy_ships_.erase(enemy_ship->id());
}
void CollisionHandler::remove_enemy_projectile(Projectile *enemy_projectile){
    enemy_projectiles_.erase(enemy_projectile->id());
}