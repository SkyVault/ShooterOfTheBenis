#include "player.h"

#define PLAYER_MOVEMENT_SENSITIVITY (20.0f)
#define CAMERA_MOUSE_MOVE_SENSITIVITY                   0.003f
#define CAMERA_MOUSE_SCROLL_SENSITIVITY                 1.5f
#define CAMERA_FIRST_PERSON_MOUSE_SENSITIVITY           0.003f
#define CAMERA_FIRST_PERSON_FOCUS_DISTANCE              25.0f
#define CAMERA_FIRST_PERSON_MIN_CLAMP                   89.0f
#define CAMERA_FIRST_PERSON_MAX_CLAMP                  -89.0f
#define CAMERA_FREE_SMOOTH_ZOOM_SENSITIVITY             0.05f
#define CAMERA_FREE_PANNING_DIVIDER                     5.1f
#define CAMERA_FIRST_PERSON_STEP_TRIGONOMETRIC_DIVIDER  5.0f
#define CAMERA_FIRST_PERSON_STEP_DIVIDER                30.0f
#define CAMERA_FIRST_PERSON_WAVING_DIVIDER              200.0f

#ifndef PI
    #define PI 3.14159265358979323846
#endif
#ifndef DEG2RAD
    #define DEG2RAD (PI/180.0f)
#endif
#ifndef RAD2DEG
    #define RAD2DEG (180.0f/PI)
#endif

void set_camera_mode(Camera camera, int mode) {
    Vector3 v1 = camera.position;
    Vector3 v2 = camera.target;

    float dx = v2.x - v1.x;
    float dy = v2.y - v1.y;
    float dz = v2.z - v1.z;

    CAMERA.targetDistance = sqrtf(dx*dx + dy*dy + dz*dz);

    // Camera angle calculation
    CAMERA.angle.x = atan2f(dx, dz);                   // Camera angle in plane XZ (0 aligned with Z, move positive CCW)
    CAMERA.angle.y = atan2f(dy, sqrtf(dx*dx + dz*dz)); // Camera angle in plane XY (0 aligned with X, move positive CW)

    CAMERA.playerEyesPosition = camera.position.y;

    // Lock cursor for first person and third person cameras
    if ((mode == CAMERA_FIRST_PERSON) || (mode == CAMERA_THIRD_PERSON)) DisableCursor();
    else EnableCursor();

    CAMERA.mode = mode;
}

void update_player(EcsWorld* ecs, Camera* camera, EntId id) {
    EntStruct* self = get_ent(ecs, id);

    if (!has_comp(ecs, self, Player) || !has_comp(ecs, self, Transform)) return;

    Transform* transform = get_comp(ecs, self, Transform);
    Player* player = get_comp(ecs, self, Player);

    static int first = 0;

    if (!first) {
        set_camera_mode(*camera, CAMERA_FIRST_PERSON);
        first = 1;
    }

    static int swingCounter = 0;    // Used for 1st person swinging movement
    static Vector2 previousMousePosition = { 0.0f, 0.0f };

    // Mouse movement detection
    Vector2 mousePositionDelta = { 0.0f, 0.0f };
    Vector2 mousePosition = GetMousePosition();

    bool direction[6] = { IsKeyDown(CAMERA.moveControl[MOVE_FRONT]),
                          IsKeyDown(CAMERA.moveControl[MOVE_BACK]),
                          IsKeyDown(CAMERA.moveControl[MOVE_RIGHT]),
                          IsKeyDown(CAMERA.moveControl[MOVE_LEFT]),
                          IsKeyDown(CAMERA.moveControl[MOVE_UP]),
                          IsKeyDown(CAMERA.moveControl[MOVE_DOWN]) };

    mousePositionDelta.x = mousePosition.x - previousMousePosition.x;
    mousePositionDelta.y = mousePosition.y - previousMousePosition.y;

    previousMousePosition = mousePosition;

    transform->translation.x += (sinf(CAMERA.angle.x)*direction[MOVE_BACK] -
                            sinf(CAMERA.angle.x)*direction[MOVE_FRONT] -
                            cosf(CAMERA.angle.x)*direction[MOVE_LEFT] +
                            cosf(CAMERA.angle.x)*direction[MOVE_RIGHT])/PLAYER_MOVEMENT_SENSITIVITY;

    transform->translation.y += (sinf(CAMERA.angle.y)*direction[MOVE_FRONT] -
                            sinf(CAMERA.angle.y)*direction[MOVE_BACK] +
                            1.0f*direction[MOVE_UP] - 1.0f*direction[MOVE_DOWN])/PLAYER_MOVEMENT_SENSITIVITY;

    transform->translation.z += (cosf(CAMERA.angle.x)*direction[MOVE_BACK] -
                            cosf(CAMERA.angle.x)*direction[MOVE_FRONT] +
                            sinf(CAMERA.angle.x)*direction[MOVE_LEFT] -
                            sinf(CAMERA.angle.x)*direction[MOVE_RIGHT])/PLAYER_MOVEMENT_SENSITIVITY;

    bool isMoving = false;  // Required for swinging

    for (int i = 0; i < 6; i++) if (direction[i]) { isMoving = true; break; }

    // Camera orientation calculation
    CAMERA.angle.x += (mousePositionDelta.x*-CAMERA_MOUSE_MOVE_SENSITIVITY);
    CAMERA.angle.y += (mousePositionDelta.y*-CAMERA_MOUSE_MOVE_SENSITIVITY);

    // Angle clamp
    if (CAMERA.angle.y > CAMERA_FIRST_PERSON_MIN_CLAMP*DEG2RAD) CAMERA.angle.y = CAMERA_FIRST_PERSON_MIN_CLAMP*DEG2RAD;
    else if (CAMERA.angle.y < CAMERA_FIRST_PERSON_MAX_CLAMP*DEG2RAD) CAMERA.angle.y = CAMERA_FIRST_PERSON_MAX_CLAMP*DEG2RAD;

    // Recalculate camera target considering translation and rotation
    Matrix m_translation = MatrixTranslate(0, 0, (CAMERA.targetDistance/CAMERA_FREE_PANNING_DIVIDER));
    Matrix m_rotation = MatrixRotateXYZ((Vector3){ PI*2 - CAMERA.angle.y, PI*2 - CAMERA.angle.x, 0 });
    Matrix m_transform = MatrixMultiply(m_translation, m_rotation);

    camera->position = transform->translation;

    camera->target.x = camera->position.x - m_transform.m12;
    camera->target.y = camera->position.y - m_transform.m13;
    camera->target.z = camera->position.z - m_transform.m14;

    if (isMoving) swingCounter++;

    // Camera position update
    // NOTE: On CAMERA_FIRST_PERSON player Y-movement is limited to player 'eyes position'
    camera->position.y = CAMERA.playerEyesPosition - sinf(swingCounter/CAMERA_FIRST_PERSON_STEP_TRIGONOMETRIC_DIVIDER)/CAMERA_FIRST_PERSON_STEP_DIVIDER;

    camera->up.x = sinf(swingCounter/(CAMERA_FIRST_PERSON_STEP_TRIGONOMETRIC_DIVIDER*2))/CAMERA_FIRST_PERSON_WAVING_DIVIDER;
    camera->up.z = -sinf(swingCounter/(CAMERA_FIRST_PERSON_STEP_TRIGONOMETRIC_DIVIDER*2))/CAMERA_FIRST_PERSON_WAVING_DIVIDER;

}
