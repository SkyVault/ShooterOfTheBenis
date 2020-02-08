#ifndef BENIS_PHYSICS_H
#define BENIS_PHYSICS_H

#include "game.h"
#include "ecs.h"
#include "raylib.h"

typedef struct {
    Vector3 velocity;

    float friction;
} Physics;

Physics* create_physics();

void update_physics(EcsWorld* ecs, Game* game, EntId ent);

#endif//BENIS_PHYSICS_H
