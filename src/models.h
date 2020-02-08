#ifndef BENIS_MODELS_H
#define BENIS_MODELS_H

#define ACTOR_HEIGHT (1.8)

#include "ecs.h"
#include "raylib.h"
#include "billboard.h"

void update_billboard(EcsWorld* ecs, EntId ent);
void draw_billboard(Camera* camera, EcsWorld* ecs, EntId ent);

#endif//BENIS_MODELS_H
