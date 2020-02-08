#include "raymath.h"

#include <stdio.h>

#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"

#include "physics.h"
#include "models.h"
#include "player.h"
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
    EcsWorld* ecs = make_ecs_world();

    Game* game = create_game(assets, &camera, ecs);
    GfxState* gfx = create_gfx_state();

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

    // Create player
    {
        EntId player_id = create_ent(ecs);
        EntStruct* player = get_ent(ecs, player_id);

        add_comp(ecs, player, Transform, .translation = (Vector3){10.0f, 1.0f, 20.0f});
        add_comp(ecs, player, Player);
        add_comp_obj(ecs, player, Physics, create_physics());
    }

    // Create some entities
    {
        EntId anibae_id = create_ent(ecs);
        EntStruct* anibae = get_ent(ecs, anibae_id);

        add_comp(ecs, anibae, Transform, .translation=(Vector3){camera.position.x, 0, camera.position.z - 5});
        add_comp(ecs, anibae, Billboard, .texture = assets->textures[TEX_EWW], .material = (Material){0});
        add_comp_obj(ecs, anibae, Physics, create_physics());

        get_comp(ecs, anibae, Transform)->translation.y = -ACTOR_HEIGHT/4;
    }

    {
        EntId anibae_id = create_ent(ecs);
        EntStruct* anibae = get_ent(ecs, anibae_id);

        add_comp(ecs, anibae, Transform, .translation=(Vector3){camera.position.x - 2, 0, camera.position.z - 5});
        add_comp(ecs, anibae, Billboard, .texture = assets->textures[TEX_EWW2], .material = (Material){0});
        add_comp_obj(ecs, anibae, Physics, create_physics());

        get_comp(ecs, anibae, Transform)->translation.y = -ACTOR_HEIGHT/4;
    }

    while (!WindowShouldClose() && game->state == STATE_RUNNING) {
        //UpdateCamera(&camera);

        for (int i = 0; i < ecs->max_num_entities; i++) {
            if (!is_ent_alive(ecs, i)) continue;
            update_billboard(ecs, i);
            update_player(ecs, assets, &camera, i);
            update_physics(ecs, game, i);
        }

        update_map(map, game);

        for (int i = 0; i < MAX_LIGHTS; i++) {
            lights[i].position = camera.position;
            UpdateLightValues(*shader, lights[i]);
        }
        
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(camera);
                draw_map(map, game);

                for (int i = 0; i < ecs->max_num_entities; i++) {
                    if (!is_ent_alive(ecs, i)) continue;
                    draw_billboard(gfx, &camera, ecs, i);
                }

                // Do the final draw to the screen
                flush_graphics(gfx, &camera);

            EndMode3D();

        EndDrawing();
    }

    CloseWindow();
}
