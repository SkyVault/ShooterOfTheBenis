#ifndef BENIS_MODELS_H
#define BENIS_MODELS_H

#include "raylib.h"

typedef struct {
    Texture2D texture;
    Material material;
} Billboard;

void create_billboard(const Texture2D tex);

#endif//BENIS_MODELS_H
