// Main Dependencies
#include "raylib.h"
#include <string>
#include <sstream>
#include <cmath>

// Custom Dependencies
#include "assets/cpp/typeClasses.h"
#include "assets/cpp/objectClasses.h"
#include "assets/cpp/mathCalc.h"
#include "assets/cpp/typeParser.h"

// Project setup for future reference: https://github.com/raysan5/raylib/wiki/Easy-Raylib-Setup-for-Windows-with-Visual-Studio

void FixedUpdate() {

}

// Main Functions
int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Project Spud Shuttle");
    int framesCounter = 0; 

    Player player;
    player.setAllParam(screenWidth/2.0f, screenHeight/2.0f, screenWidth, screenHeight, 6, 0, WHITE, (char *)"spud-1");
    player.cache();

    SSCamera mainCamera = { screenWidth/2, screenHeight/2, 0.0f, 1.0f, player.posX, player.posY };

    SetTargetFPS(60);

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        framesCounter++;
        if (((framesCounter/60)%2) == 1) {
            FixedUpdate();
            framesCounter = 0;
        };

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
            DrawText(player.textureFull.c_str(), 10, 40, 10, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}