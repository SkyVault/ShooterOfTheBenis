#include <raylib.h>
#include <stdio.h>

#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"

#include "models.h"
#include "ecs.h"
#include "game.h"
#include "map.h"
#include "assets.h"

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION 330
#else
#define GLSL_VERSION 100
#endif

#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT ((SCREEN_WIDTH) * (160.0 / 240.0))
#define MAX_COLUMNS (20)

void custom_logger(int msg_type, const char *text, va_list args) {
    // TODO(Dustin): Route this information somewhere
}

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT); 
    //SetTraceLogLevel(0);
    //SetTraceLogCallback(custom_logger);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "DevWindow");
    SetTargetFPS(60);

    // Define the camera to look into our 3d world (position, target, up vector)
    Camera camera = { 0 };
    camera.position = (Vector3){ 10.0f, 1.0f, 20.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 75.0f;
    camera.type = CAMERA_PERSPECTIVE;

    Assets* assets = create_and_load_assets();
    EcsWorld* ent_world = make_ecs_world();

    Game* game = create_game(assets, &camera, ent_world);

    Shader* shader = &assets->shaders[SHADER_PHONG_LIGHTING];
    shader->locs[LOC_MATRIX_MODEL] = GetShaderLocation(*shader, "matModel");
    shader->locs[LOC_VECTOR_VIEW] = GetShaderLocation(*shader, "viewPos");

    int ambientLoc = GetShaderLocation(*shader, "ambient");
    SetShaderValue(*shader, ambientLoc, (float[4]){0.2f, 0.2f, 0.2f, 1.0f}, UNIFORM_VEC4);

    Light lights[MAX_LIGHTS] = { 0 };
    lights[0] = CreateLight(LIGHT_POINT, (Vector3){ -10, 0, -10 }, (Vector3){0}, WHITE, *shader);

    for (int i = 0; i < MAX_LIGHTS; i++) {
        UpdateLightValues(*shader, lights[i]);
    }

    Map* map = load_map(0, game);

    // Create some entities
    {
        EntId anibae_id = create_ent(ent_world);
        EntStruct* anibae = get_ent(ent_world, anibae_id);

        add_comp(ent_world, anibae, Transform, .translation=(Vector3){camera.position.x, 0, camera.position.z - 5});
        add_comp(ent_world, anibae, Billboard, .texture = assets->textures[TEX_CHAR_1], .material = (Material){0});
    }

    SetCameraMode(camera, CAMERA_FIRST_PERSON); // Set a first person camera mode

    while (!WindowShouldClose() && game->state == STATE_RUNNING) {
        UpdateCamera(&camera);                  // Update camera

        update_map(map, game);

        for (int i = 0; i < ent_world->max_num_entities; i++) {
            if (!is_ent_alive(ent_world, i)) continue;
            update_billboard(ent_world, i);
        }

        for (int i = 0; i < MAX_LIGHTS; i++) {
            lights[i].position = camera.position;
            UpdateLightValues(*shader, lights[i]);
        }
        
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(camera);
                draw_map(map, game);

                for (int i = 0; i < ent_world->max_num_entities; i++) {
                    if (!is_ent_alive(ent_world, i)) continue;
                    draw_billboard(&camera, ent_world, i);
                }

            EndMode3D();

        EndDrawing();
    }

    CloseWindow();
}
