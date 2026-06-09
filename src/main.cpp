#include <inttypes.h>

#include <raylib.h>

bool initApplication(const int screenWidth, const int screenHeight, uint16_t fps) {
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(fps);
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    const uint16_t fps = 240;

    if (!initApplication(screenWidth, screenHeight, fps)) {
        return 1;
    }
    

    while (!WindowShouldClose()) {


        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Hoppers are cool!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}