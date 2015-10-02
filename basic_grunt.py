import pygame

from gameobject import GameObject


class BasicGrunt(GameObject):

    def __init__(self, starting_position, universe):
        self.position_ = starting_position

        self.ID_ = self.create_ID()
        self.size_ = 15
        self.speed_ = 0.5
        self.health_ = 30
        self.universe_ = universe
        self.listeners_ = []

    """
    Update Functions
    """

    def update(self, events):
        main_character_position = self.universe_.main_character().position_
        x_distance = main_character_position[0] - self.position_[0]
        y_distance = main_character_position[1] - self.position_[1]
        distance = (x_distance**2 + y_distance**2)**(1/2)

        # Outside range
        if distance > 600:
            self.position_ = (self.position_[0], self.position_[1]+self.speed_)
        # if distance <= 400:
            # self.position_ = (self.position_[0]+self.speed_, self.position_[1]+self.speed_) funny
        # Inside Range 1
        elif distance >= 100:
            x_velocity = (x_distance * self.speed_) / distance
            y_velocity = (y_distance * self.speed_) / distance
            self.position_ = (
                self.position_[0]+x_velocity, self.position_[1]+y_velocity)
        # Inside Range 2
        else:
            self.position_ = (self.position_[0], self.position_[1])

    """
    Access Functions
    """

    def collision_box(self):
        return pygame.Rect(self.position_[0]-self.size_/2,
                           self.position_[1]-self.size_/2,
                           self.size_,
                           self.size_)

    def take_damage(self, damage):
        if damage <= 0:
            print("WARNING BasicGrunt " + str(self.ID_) + " taking " + str(damage) + " damage")
            print("Disregarding non positive damage")
        elif damage >= self.health_:
            self.report_destroyed()
        else:
            self.health_ -= damage


    """
    Listener Functions
    """

    def report_destroyed(self):
        for listener in self.listeners_:
            listener.reported_destroyed(self)
    
    def register(self, listeners):
        self.listeners_.append(listeners)
        pass

