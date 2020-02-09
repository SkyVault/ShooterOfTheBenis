#ifndef BENIS_PHYSICS_TYPE_H
#define BENIS_PHYSICS_TYPE_H

#include "raylib.h"

typedef struct {
    Vector3 velocity;
    float friction;
} Physics;

Physics create_physics();

#endif//BENIS_PHYSICS_TYPE_H
