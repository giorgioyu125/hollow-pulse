#include "raylib.h"
#include "raymath.h"

int main(void){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "TPS Sekiro Style - CON ROTAZIONE");

    Vector3 playerPosition = { 0.0f, 0.0f, 0.0f };
    float playerSpeed = 10.0f;

    float playerRotationY = 0.0f;

    float capsuleRadius = 0.5f;
    float capsuleHeight = 2.0f;

    int slices = 16;
    int rings = 8;

    float cameraDistance = 12.0f;
    float cameraYaw = 0.0f;
    float cameraPitch = -45.0f;
    float cameraSensitivity = 0.2f;

    Camera3D camera = { 0 };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    DisableCursor();
    SetTargetFPS(0);

    while (!WindowShouldClose()){
        float dt = GetFrameTime();

        Vector2 mouseDelta = GetMouseDelta();
        cameraYaw -= mouseDelta.x * cameraSensitivity;
        cameraPitch += mouseDelta.y * cameraSensitivity;

        if (cameraPitch > 85.0f)  cameraPitch = 85.0f;
        if (cameraPitch < -5.0f)   cameraPitch = -5.0f;

        float radYaw = DEG2RAD * cameraYaw;
        float radPitch = DEG2RAD * cameraPitch;

        float offsetX = cosf(radYaw) * cosf(radPitch) * cameraDistance;
        float offsetY = sinf(radPitch) * cameraDistance;
        float offsetZ = sinf(radYaw) * cosf(radPitch) * cameraDistance;

        Vector3 cameraOffset = { offsetX, offsetY, offsetZ };
        camera.position = Vector3Add(playerPosition, cameraOffset);
        camera.target = playerPosition;

        Vector3 viewDir = Vector3Subtract(camera.target, camera.position);
        Vector3 forward = Vector3Normalize((Vector3){ viewDir.x, 0.0f, viewDir.z });
        Vector3 right = Vector3Normalize((Vector3){ forward.z, 0.0f, -forward.x });

        Vector3 moveDir = { 0 };
        if (IsKeyDown(KEY_W)) moveDir = Vector3Add(moveDir, forward);
        if (IsKeyDown(KEY_S)) moveDir = Vector3Subtract(moveDir, forward);
        if (IsKeyDown(KEY_D)) moveDir = Vector3Subtract(moveDir, right);
        if (IsKeyDown(KEY_A)) moveDir = Vector3Add(moveDir, right);

        if (IsKeyDown(KEY_LEFT_SHIFT)) moveDir.y -= 1.0f;
        if (IsKeyDown(KEY_SPACE)) moveDir.y += 1.0f;

        if (Vector3Length(moveDir) > 0){
            moveDir = Vector3Normalize(moveDir);

            playerRotationY = atan2f(moveDir.x, moveDir.z) * RAD2DEG;

            Vector3 movement = Vector3Scale(moveDir, playerSpeed * dt);
            playerPosition = Vector3Add(playerPosition, movement);
        }

        camera.target = playerPosition;
        camera.position = Vector3Add(playerPosition, cameraOffset);
        UpdateCamera(&camera, CAMERA_CUSTOM); 

        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawGrid(20, 1.0f);

                float halfHeight = capsuleHeight / 2.0f - capsuleRadius;

                Vector3 capsuleStartLocal = { 0.0f, -halfHeight, 0.0f };
                Vector3 capsuleEndLocal   = { 0.0f,  halfHeight, 0.0f };

                float rotationRad = playerRotationY * DEG2RAD;

                Matrix rotationMatrix = MatrixRotateY(rotationRad);

                Vector3 capsuleStartRotated = Vector3Transform(capsuleStartLocal, rotationMatrix);
                Vector3 capsuleEndRotated   = Vector3Transform(capsuleEndLocal, rotationMatrix);

                Vector3 capsuleStart = Vector3Add(playerPosition, capsuleStartRotated);
                Vector3 capsuleEnd   = Vector3Add(playerPosition, capsuleEndRotated);

                DrawCapsule(capsuleStart, capsuleEnd, capsuleRadius, slices, rings, BLUE);
                DrawCapsuleWires(capsuleStart, capsuleEnd, capsuleRadius, slices, rings, DARKBLUE);

                DrawLine3D(camera.position, camera.target, RED);

                Vector3 frontPos = {
                    playerPosition.x + sinf(rotationRad) * 1.0f,
                    playerPosition.y,
                    playerPosition.z + cosf(rotationRad) * 1.0f
                };
                DrawLine3D(playerPosition, frontPos, GREEN);  // Verde = direzione fronte
            EndMode3D();

            DrawFPS(70, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
