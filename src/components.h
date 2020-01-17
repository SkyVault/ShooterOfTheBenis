#ifndef VAULT_COMPONENTS_H
#define VAULT_COMPONENTS_H

#include "ecs.h"
#include "maths.h"
#include "raylib.h"

typedef struct {
    V2 pos;
    V2 size;
} Body;

int contains(Body* a, Body* b);
V2 center(Body* b);

typedef struct {
    float time_left;
} TimedDestroy;

void update_timed_destroy(EcsWorld* world, EntId id);

#endif//VAULT_COMPONENTS_H
