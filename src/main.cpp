#include <inttypes.h>

#include <raylib.h>
#include <rlgl.h>
#include <raymath.h>
#include <miku/logger.h>

struct Application {
    Camera2D camera;
    Color clearColor;
};

bool initApplication(Application& app, const int screenWidth, const int screenHeight, const uint16_t fps, const char* title) {
    app.camera = { 0.0f };
    app.camera.zoom = 1.0f;

    app.clearColor = ColorLerp(BLACK, BLACK, 0.69f);

    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(fps);
    return true;
}

void updateApplication(Application& app) {
    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(app.clearColor);

            DrawText("Hoppers are cool!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
}

void shutdownApplication(Application& app) {
    CloseWindow();
}

int main() {
    Logger::SetProperty(InfoPriority);

    const int screenWidth = 800;
    const int screenHeight = 450;
    const uint16_t fps = 240;
    const char* title = "HickTheKopper";

    Application app;
    if (!initApplication(app, screenWidth, screenHeight, fps, title)) {
        LOG_CRITICAL("%s", "Initialize Application failed");
        return 1;
    }

    

    updateApplication(app);

    shutdownApplication(app);
    return 0;
}