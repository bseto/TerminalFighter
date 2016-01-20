#include "collision_detector.h"
#include "hitbox.h"

void CollisionDetector::check_friendly_sensor_collisions() {
    //check friendly_sensors_ against enemy_sensors_, enemy_projectiles_, enemy_ships_
    for (auto friendly_sensor : friendly_sensors_) {
        std::vector<Hitbox> friendly_sensor_hitboxes = friendly_sensor->get_hitboxes();
		int hitbox_number = 0;
        for (auto friendly_hitbox : friendly_sensor_hitboxes) {
            
            
            for (auto enemy_sensor : enemy_sensors_) {
                for (auto enemy_hitbox : enemy_sensor->get_hitboxes()) {
                    if (friendly_hitbox.is_overlapping(enemy_hitbox)) {
                        friendly_sensor->notify_collision(enemy_sensor, hitbox_number);
                    }
                }
            }
            for (auto enemy_projectile : enemy_projectiles_) {
                for (auto enemy_hitbox : enemy_projectile->get_hitboxes()) {
                    if (friendly_hitbox.is_overlapping(enemy_hitbox)) {
                        friendly_sensor->notify_collision(enemy_projectile, hitbox_number);
                    }
                }
            }
            for (auto enemy_ship : enemy_ships_) {
                for (auto enemy_hitbox : enemy_ship->get_hitboxes()) {
                    if (friendly_hitbox.is_overlapping(enemy_hitbox)) {
                        friendly_sensor->notify_collision(enemy_ship, hitbox_number);
                    }
                }
            }

            hitbox_number++;
        }
    }
}

void CollisionDetector::check_enemy_sensor_collisions() {
    //check enemy_sensors_ against friendly_sensors_, friendly_projectiles_, 
    for (auto enemy_sensor : enemy_sensors_) {
        std::vector<Hitbox> enemy_sensor_hitboxes = enemy_sensor->get_hitboxes();
		int hitbox_number = 0;
        for (auto enemy_hitbox : enemy_sensor_hitboxes) {
            
            
            for (auto friendly_sensor : friendly_sensors_) {
                for (auto friendly_sensor_hitbox : friendly_sensor->get_hitboxes()) {
                    if (enemy_hitbox.is_overlapping(friendly_sensor_hitbox)) {
                        enemy_sensor->notify_collision(friendly_sensor, hitbox_number);
                    }
                }
            }
            for (auto friendly_projectile : friendly_projectiles_) {
                for (auto friendly_hitbox : friendly_projectile->get_hitboxes()) {
                    if (enemy_hitbox.is_overlapping(friendly_hitbox)) {
                        enemy_sensor->notify_collision(friendly_projectile, hitbox_number);
                    }
                }
            }
            hitbox_number++;
        }
    }
}

void CollisionDetector::check_friendly_projectile_collisions() {
    //check friendly_projectiles_ against enemy_projectiles_, check_enemy_ship_, CHECK ENEMY SENSORS?? 
    for (auto friendly_projectile : friendly_projectiles_) {
        std::vector<Hitbox> friendly_projectile_hitboxes = friendly_projectile->get_hitboxes();
		int hitbox_number = 0;
        for (auto friendly_projectile_hitbox : friendly_projectile_hitboxes) {
            
            for (auto enemy_projectile : enemy_projectiles_) {
                for (auto enemy_hitbox : enemy_projectile->get_hitboxes()) {
                    if (friendly_projectile_hitbox.is_overlapping(enemy_hitbox)) {
                        friendly_projectile->notify_collision(enemy_projectile, hitbox_number);
                    }
                }
            }
            for (auto enemy_ship : enemy_ships_) {
                for (auto enemy_hitbox : enemy_ship->get_hitboxes()) {
                    if (friendly_projectile_hitbox.is_overlapping(enemy_hitbox)) {
                        friendly_projectile->notify_collision(enemy_ship, hitbox_number);
                    }
                }
            }

            hitbox_number++;
        }
    }
}

void CollisionDetector::check_enemy_projectile_collisions() {
    //check enemy_projectiles_ against friendly_projectiles_, friendly_ships_
	for (auto enemy_projectile : enemy_projectiles_) {
        std::vector<Hitbox> enemy_projectile_hitboxes = enemy_projectile->get_hitboxes();
		int hitbox_number = 0;
        for (auto enemy_projectile_hitbox : enemy_projectile_hitboxes) {
            
            for (auto friendly_projectile : friendly_projectiles_) {
                for (auto friendly_hitbox : friendly_projectile->get_hitboxes()) {
                    if (enemy_projectile_hitbox.is_overlapping(friendly_hitbox)) {
                        enemy_projectile->notify_collision(friendly_projectile, hitbox_number);
                    }
                }
            }
            for (auto friendly_ship : friendly_ships_) {
                for (auto friendly_hitbox : friendly_ship->get_hitboxes()) {
                    if (enemy_projectile_hitbox.is_overlapping(friendly_hitbox)) {
                        enemy_projectile->notify_collision(friendly_ship, hitbox_number);
                    }
                }
            }

            hitbox_number++;
        }
    }
    
}

void CollisionDetector::check_friendly_ship_collisions() {
    //check friendly_ships_ against enemy_ships_

 for (auto friendly_ship : friendly_ships_) {
        std::vector<Hitbox> friendly_ship_hitboxes = friendly_ship->get_hitboxes();
		int hitbox_number = 0;
        for (auto friendly_ship_hitbox : friendly_ship_hitboxes) {
            
            for (auto enemy_ship : enemy_ships_) {
                for (auto enemy_hitbox : enemy_ship->get_hitboxes()) {
                    if (friendly_ship_hitbox.is_overlapping(enemy_hitbox)) {
                        friendly_ship->notify_collision(enemy_ship, hitbox_number);
                    }
                }
            }

            hitbox_number++;
        }
    }
}

void CollisionDetector::check_enemy_ship_collisions() {
    //check enemy_ships_ against friendlys_ships_
    for (auto enemy_ship : enemy_ships_) {
        std::vector<Hitbox> enemy_ship_hitboxes = enemy_ship->get_hitboxes();
		int hitbox_number = 0;
        for (auto enemy_ship_hitbox : enemy_ship_hitboxes) {
            
            for (auto friendly_ship : friendly_ships_) {
                for (auto friendly_hitbox : friendly_ship->get_hitboxes()) {
                    if (enemy_ship_hitbox.is_overlapping(friendly_hitbox)) {
                        enemy_ship->notify_collision(friendly_ship, hitbox_number);
                    }
                }
            }

            hitbox_number++;
        }
    }
}
