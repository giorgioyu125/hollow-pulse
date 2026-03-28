#include "raylib.h"
#include <math.h>

int main(void){
    const int screenWidth = 900;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Walking Capsule");

    // Camera ---
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 8.0f, 10.0f };
    camera.target   = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.up       = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy     = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // --- Character state ---
    Vector3 position = { 0.0f, 0.0f, 0.0f };
    float speed      = 5.0f;
    float facing     = 0.0f;
    float walkTimer  = 0.0f;
    bool  isMoving   = false;

    // --- Capsule dimensions ---
    float bodyRadius = 0.35f;
    float bodyHalf   = 0.5f;
    float legRadius  = 0.1f;
    float legLength  = 0.6f;
    float legSpread  = 0.2f;

    SetTargetFPS(60);

    while (!WindowShouldClose()){
        float dt = GetFrameTime();

        // --- Input ---
        Vector3 moveDir = { 0 };
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))    moveDir.z -= 1.0f;
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))   moveDir.z += 1.0f;
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))   moveDir.x -= 1.0f;
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))  moveDir.x += 1.0f;

        isMoving = (moveDir.x != 0.0f || moveDir.z != 0.0f);

        if (isMoving){
            float len = sqrtf(moveDir.x * moveDir.x + moveDir.z * moveDir.z);
            moveDir.x /= len;
            moveDir.z /= len;

            position.x += moveDir.x * speed * dt;
            position.z += moveDir.z * speed * dt;

            facing = atan2f(moveDir.x, moveDir.z);
            walkTimer += dt * 12.0f;
        } else {
            walkTimer = 0.0f;
        }

        float bob = isMoving ? fabsf(sinf(walkTimer)) * 0.08f : 0.0f;

        float legSwing = isMoving ? sinf(walkTimer) * 0.7f : 0.0f;  // radians

        camera.target   = (Vector3){ position.x, 1.2f, position.z };
        camera.position = (Vector3){ position.x, 6.0f, position.z + 8.0f };

        float sinF = sinf(facing);
        float cosF = cosf(facing);
        float rightX =  cosF;
        float rightZ = -sinF;
        float fwdX = sinF;
        float fwdZ = cosF;

        // --- Body position ---
        float bodyBaseY = legLength + 0.05f + bob;
        Vector3 bodyBot = { position.x, bodyBaseY + bodyRadius, position.z };
        Vector3 bodyTop = { position.x, bodyBaseY + bodyRadius + bodyHalf * 2.0f, position.z };

        // --- Eye ---
        float eyeY = bodyTop.y;
        Vector3 eyePos = {
            position.x + fwdX * bodyRadius * 0.9f,
            eyeY,
            position.z + fwdZ * bodyRadius * 0.9f
        };

        // --- Leg positions (swing forward/back along facing direction) ---
        float lLegTopX = position.x - rightX * legSpread;
        float lLegTopZ = position.z - rightZ * legSpread;
        float lLegTopY = bodyBaseY;

        float lSwing = legSwing;
        Vector3 leftLegTop = { lLegTopX, lLegTopY, lLegTopZ };
        Vector3 leftLegBot = {
            lLegTopX + sinf(facing + lSwing) * legLength * 0.3f,
            0.0f + legRadius,
            lLegTopZ + cosf(facing + lSwing) * legLength * 0.3f
        };

        float rLegTopX = position.x + rightX * legSpread;
        float rLegTopZ = position.z + rightZ * legSpread;
        float rLegTopY = bodyBaseY;

        float rSwing = -legSwing;
        Vector3 rightLegTop = { rLegTopX, rLegTopY, rLegTopZ };
        Vector3 rightLegBot = {
            rLegTopX + sinf(facing + rSwing) * legLength * 0.3f,
            0.0f + legRadius,
            rLegTopZ + cosf(facing + rSwing) * legLength * 0.3f
        };

        // --- Draw ---
        BeginDrawing();
        ClearBackground((Color){ 200, 220, 240, 255 });

        BeginMode3D(camera);
            DrawPlane((Vector3){ 0, 0, 0 }, (Vector2){ 60, 60 }, (Color){ 120, 180, 100, 255 });
            DrawGrid(60, 1.0f);

            DrawCylinder(position, 0.5f, 0.5f, 0.01f, 16, (Color){ 0, 0, 0, 60 });

            DrawCapsule(leftLegTop,  leftLegBot,  legRadius, 8, 4, DARKBLUE);
            DrawCapsule(rightLegTop, rightLegBot, legRadius, 8, 4, DARKBLUE);

            DrawCapsule(bodyBot, bodyTop, bodyRadius, 16, 8, BLUE);
            DrawCapsuleWires(bodyBot, bodyTop, bodyRadius, 8, 4, (Color){ 0, 0, 120, 255 });

            DrawSphere(eyePos, 0.09f, WHITE);
            Vector3 pupilPos = {
                eyePos.x + fwdX * 0.06f,
                eyePos.y,
                eyePos.z + fwdZ * 0.06f
            };
            DrawSphere(pupilPos, 0.05f, BLACK);

        EndMode3D();

        DrawText("WASD / Arrow Keys to walk", 10, 10, 20, DARKGRAY);
        DrawText(TextFormat("Pos: %.1f, %.1f", position.x, position.z), 10, 35, 18, GRAY);
        DrawFPS(screenWidth - 100, 10);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
