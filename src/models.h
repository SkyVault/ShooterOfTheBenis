#ifndef BENIS_MODELS_H
#define BENIS_MODELS_H

#include "ecs.h"
#include "raylib.h"

typedef struct {
    Texture2D texture;
    Material material;
} Billboard;

void update_billboard(EcsWorld* ecs, EntId ent);
void draw_billboard(Camera* camera, EcsWorld* ecs, EntId ent);

#endif//BENIS_MODELS_H
