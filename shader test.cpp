#include <string>

#include "raylib.h"
#include "raymath.h"

#include "CircleTextureDrawing.h"

#define GLSL_VERSION            330


int main()
{
    const int screenWidth = GetMonitorWidth(GetCurrentMonitor());
    const int screenHeight = GetMonitorHeight(GetCurrentMonitor());


    InitWindow(screenWidth, screenHeight, "raylib [shaders] example - texture drawing");

    SetWindowPosition(0, GetScreenHeight() / 36);

    Texture2D testT = LoadTexture("test.png");

    float radius = 100;
    Vector2 target = { 0,0 };


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    // -------------------------------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        target = GetMousePosition();

        radius -= 10*GetMouseWheelMove();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground({ 230, 230, 230, 255 });

        DrawText("Wheel - radius", 100, 60, 20, BLACK);

        DrawTextureCircle(testT, { 100,200 }, target, radius, WHITE, "CircleTexture.frag", GLSL_VERSION);
        DrawCircleV({ 100,200 }, 10, RED);
        DrawRectangleLines(100, 200, testT.width, testT.height, RED);
        DrawText("DrawTextureCircle (circle relative to texture pos)", 100, 170, 20, BLACK);


        DrawCollisionTextureCircle(testT, { 840,200 }, target, radius, WHITE, "CircleTexture.frag", GLSL_VERSION);
        DrawCircleV({ 840,200 }, 10, RED);
        DrawRectangleLines(840, 200, testT.width, testT.height, RED);
        DrawText("DrawCollisionTextureCircle", 840, 170, 20, BLACK);

        DrawCircleLines(target.x, target.y, radius, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(testT);

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

