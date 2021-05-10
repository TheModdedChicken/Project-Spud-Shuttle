// Main Dependencies
#include "raylib.h"
#include <string>
#include <sstream>
#include <cmath>

// Custom Dependencies
#include "assets/cpp/objectClasses.h"
#include "assets/cpp/mathCalc.h"

// Main Functions
int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Project Spud Shuttle");

    Player player;
    player.setAllParam(screenWidth/2.0f, screenHeight/2.0f, screenWidth, screenHeight, 6, 0, WHITE, (char *)"spud-1");
    player.cache();

    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.posX + 20.0f, player.posY + 20.0f };
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        Point2D mousePos = {GetMousePosition().x, GetMousePosition().y};
        Point2D playerPos = {player.posX, player.posY};
        player.rotation = findAngle2d(playerPos, mousePos);
        if (IsKeyDown(KEY_D)) player.posX += 2.0f;
        if (IsKeyDown(KEY_A)) player.posX -= 2.0f;
        if (IsKeyDown(KEY_W)) player.posY -= 2.0f;
        if (IsKeyDown(KEY_S)) player.posY += 2.0f;

        BeginDrawing();

            ClearBackground(RAYWHITE);

            player.draw();

            DrawFPS(10, 10);
            const char *test = player.textureFull;
            DrawText(test, 10, 40, 10, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}