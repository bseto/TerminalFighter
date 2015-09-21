import sys

import pygame

from universe import Universe
from gamemaster import GameMaster

pygame.init()
pygame.font.init()
pygame.key.set_repeat(100, 25)

DRAWING_SCALE = 2
GAME_WIDTH = 1000
GAME_HEIGHT = 700
WHITE = 0, 0, 0

screen = pygame.display.set_mode((GAME_WIDTH*DRAWING_SCALE, GAME_HEIGHT*DRAWING_SCALE))

universe = Universe((GAME_WIDTH, GAME_HEIGHT))
gamemaster = GameMaster(universe, DRAWING_SCALE)

# pygame ticks, one tick is 1/1000 second
# 15 pygame ticks per update is approximately 50 updates per second
UPDATE_LENGTH_MS = 20

prev_update_start_time = 0

while 1:
    update_start_time = pygame.time.get_ticks()
    # print("Elapsed time since last update : " + str(update_start_time - prev_update_start_time))
    prev_update_start_time = update_start_time

    events = pygame.event.get()

    for event in events:
        if event.type == pygame.QUIT:
            sys.exit()

    background = pygame.Surface(screen.get_size())
    background = background.convert()
    background.fill((255, 255, 255))
    screen.blit(background, (0, 0))

    gamemaster.update(events)
    gamemaster.draw(screen)

    pygame.display.flip()

    update_end_time = pygame.time.get_ticks()
    update_time_elapsed = update_end_time - update_start_time
    if update_time_elapsed < UPDATE_LENGTH_MS:
        pygame.time.wait(UPDATE_LENGTH_MS - update_time_elapsed)
