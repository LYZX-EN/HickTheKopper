#include <inttypes.h>

#include <raylib.h>
#include <raymath.h>
#include <miku/logger.h>

bool initApplication(const int screenWidth, const int screenHeight, const uint16_t fps, const char* title) {
    

    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(fps);
    return true;
}

void updateApplication(const Color clearColor) {
    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(clearColor);

            DrawText("Hoppers are cool!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
}

void shutdownApplication() {
    CloseWindow();
}

int main() {
    Logger::SetProperty(InfoPriority);

    const int screenWidth = 800;
    const int screenHeight = 450;
    const uint16_t fps = 240;
    const char* title = "HickTheKopper";

    if (!initApplication(screenWidth, screenHeight, fps, title)) {
        LOG_CRITICAL("%s", "Initialize Application failed");
        return 1;
    }

    const Color clearColor = ColorLerp(BLACK, BLACK, 0.69f);

    updateApplication(clearColor);

    shutdownApplication();
    return 0;
}