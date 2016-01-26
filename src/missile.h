#pragma once
#include <SDL2/SDL.h>

#include "projectile.h"
class Ship;

class Missile : public Projectile {
public:
    Missile(double x_pos, double y_pos, double x_vel, double y_vel);

    void update();
    void draw(GraphicsHandler *graphics);
    std::vector<Hitbox> get_hitboxes();
    
    static void set_texture(SDL_Texture* texture);

	void notify_collision(Projectile* sensed_sensor, int hitbox_number);
	void notify_collision(Ship* sensed_sensor, int hitbox_number);

private:
    static SDL_Texture* missile_texture_;
};
