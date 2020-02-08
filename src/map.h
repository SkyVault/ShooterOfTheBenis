#ifndef BENIS_MAP_H
#define BENIS_MAP_H

#include <stdlib.h>

#include "game.h"
#include "components.h"
#include "ecs.h"
#include "assets.h"
#include "physics.h"
#include "raylib.h"
#include "raymath.h"

#define MAX_MAP_WIDTH (100)
#define MAX_MAP_HEIGHT (100)

#define CUBE_SIZE (5)
#define CUBE_HEIGHT (CUBE_SIZE * 2)

struct LvlData {
    int w, h;
    char* d;
};

static const struct LvlData map_data[] = {
    [0] = {
        .w = 18,
        .h = 10,
        .d = "########## #######"
             "#        ###     #"
             "#   #    |       #"
             "#        ###     #"
             "#  ##-## # ###-###"
             "#        |   #   #"
             "#        #####   #"
             "#    #   #       #"
             "#        #       #"
             "############ #####" }
};

typedef struct {
    int active;
    Model model;
} Wall;

typedef struct {
    int current_map;
    Wall walls[MAX_MAP_WIDTH*MAX_MAP_HEIGHT];
    Model floor_tile_models[1];
} Map;

Map* load_map(int map, Game* game);

void update_map(Map* map, Game* game);
void draw_map(Map* map, Game* game);

#endif//BENIS_MAP_H
