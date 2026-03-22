#include <stdio.h>
#include <stdlib.h>

#include "utility.h"
#include "raylib.h"

int main(void){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Hollow Pulse");

    SetTargetFPS(60);

    sv hello = SV_STATIC("Congrats! You created your first window!");

    // Main game loop
    while (!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawSV(hello, 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
