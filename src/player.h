#ifndef BENIS_PLAYER_H
#define BENIS_PLAYER_H

#include <math.h>

#include "assets.h"
#include "models.h"
#include "physics.h"
#include "raymath.h"
#include "ecs.h"
#include "raylib.h"

typedef struct {} Player;

typedef enum {
    MOVE_FRONT = 0,
    MOVE_BACK,
    MOVE_RIGHT,
    MOVE_LEFT,
    MOVE_UP,
    MOVE_DOWN
} CameraMove;

typedef struct {
    int mode;                     // Current camera mode
    float targetDistance;         // Camera distance from position to target
    float playerEyesPosition;     // Default player eyes position from ground (in meters)
    Vector2 angle;                // Camera angle in plane XZ
    int moveControl[6];
    int smoothZoomControl;        // raylib: KEY_LEFT_CONTROL
    int altControl;               // raylib: KEY_LEFT_ALT
    int panControl;               // raylib: MOUSE_MIDDLE_BUTTON
} CameraData;

static CameraData CAMERA = {
    .mode = 0,
    .targetDistance = 0,
    .playerEyesPosition = 1.85f,
    .angle = { 0 },
    .moveControl = { KEY_W, 'S', 'D', 'A', 'E', 'Q' },
    .smoothZoomControl = 341,
    .altControl = 342,
    .panControl = 2
};

void update_player(EcsWorld* ecs, Assets* ass, Camera* camera, EntId self);

#endif//BENIS_PLAYER_H
