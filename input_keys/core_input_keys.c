/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 400;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] GAMES- keyboard input");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/4 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    int t = 0;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT) && ballPosition.x < 350) ballPosition.x += 10.0f;
        if (IsKeyDown(KEY_LEFT) && ballPosition.x > 50) ballPosition.x -= 10.0f;
        if (IsKeyDown(KEY_UP) && ballPosition.y > 50) {
          ballPosition.y -= 10.0f;
          t = 0;
        }
        if (IsKeyDown(KEY_DOWN) && ballPosition.y < 400) ballPosition.y += 10.0f;

        //if (ballPosition.y < 400) ballPosition.y = ballPosition.y + 4.9*((float)t/60)²;
        if (!IsKeyDown(KEY_UP) && ballPosition.y < 400) ballPosition.y = ballPosition.y + 4.9*(float)t/60.0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 50, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
        t++;
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
