#include <raylib.h>
#include <stdio.h>

#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT ((SCREEN_WIDTH) * (160.0 / 240.0))
#define MAX_COLUMNS (20)

void custom_logger(int msg_type, const char *text, va_list args) {
    // TODO(Dustin): Route this information somewhere
}

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); 
    SetTraceLogLevel(0);
    SetTraceLogCallback(custom_logger);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "DevWindow");
    SetTargetFPS(60);

    // Define the camera to look into our 3d world (position, target, up vector)
    Camera camera = { 0 };
    camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.type = CAMERA_PERSPECTIVE;

    // Generates some random columns
    float heights[MAX_COLUMNS] = { 0.0f };
    Vector3 positions[MAX_COLUMNS] = { 0 };
    Color colors[MAX_COLUMNS] = { 0 };

    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        heights[i] = (float)GetRandomValue(1, 12);
        positions[i] = (Vector3){ GetRandomValue(-15, 15), heights[i]/2, GetRandomValue(-15, 15) };
        colors[i] = (Color){ GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255 };
    }

    SetCameraMode(camera, CAMERA_FIRST_PERSON); // Set a first person camera mode


    while (!WindowShouldClose()) {
        UpdateCamera(&camera);                  // Update camera
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);

                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY); // Draw ground
                DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
                DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
                DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall

                // Draw some cubes around
                for (int i = 0; i < MAX_COLUMNS; i++)
                {
                    DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
                    DrawCubeWires(positions[i], 2.0f, heights[i], 2.0f, MAROON);
                }

            EndMode3D();

        EndDrawing();
    }

    CloseWindow();
}
