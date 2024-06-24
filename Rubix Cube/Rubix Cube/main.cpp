/*******************************************************************************************
*
*   Rubix Cube - Jeffrey Kedda
*

*
********************************************************************************************/

#include "RubixCube.h"
#include "rcamera.h"
#include <iostream>

// Global variables to track pitch and yaw angles
float cameraPitch = 0.0f;
float cameraYaw = 90.0f;

void CustomUpdateCamera(Camera* camera, int cameraMode, int radius) {
    // Rotation
    cameraYaw += GetMouseDelta().x * 0.5f;

    // Clamp pitch to avoid camera flipping
    cameraPitch += GetMouseDelta().y * 0.5f;
    if (cameraPitch > 89.9f)
        cameraPitch = 89.9f;
    if (cameraPitch < -89.9f)
        cameraPitch = -89.9f;

    camera->position.x = radius * cosf(DEG2RAD * cameraYaw);
    camera->position.z = radius * sinf(DEG2RAD * cameraYaw);
    camera->position.y = radius * sinf(DEG2RAD * cameraPitch);

    // Update camera target based on rotation
    camera->target = Vector3{ 0.0f, 0.0f, 0.0f };
}


int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Rubix Cube - Jeffrey Kedda");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetWindowMinSize(screenWidth, screenHeight);

    Texture2D raylib = LoadTexture("resources/Raylib.png");

    Camera camera = { 0 };
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;                           
    camera.projection = CAMERA_PERSPECTIVE;        
    int cameraMode = CAMERA_THIRD_PERSON;
    float radius = 4.0f;

    CustomUpdateCamera(&camera, cameraMode, radius);

    SetTargetFPS(60); 

    //Cubie cubie = Cubie(camera.target);
    RubixCube cube = RubixCube();
    float movement = 0.0f;

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawTexture(raylib, 0.0f, 0.0f, WHITE);
        BeginMode3D(camera);

        cube.drawCubes();
        cube.updateCubes();

        EndMode3D();
        EndDrawing();

        movement = GetMouseWheelMove();


        if (movement != 0.0f) {
            radius += movement * .5; // Accumulate the scroll value
            CustomUpdateCamera(&camera, cameraMode, radius);
        }
        if (IsMouseButtonDown(0)) {
            CustomUpdateCamera(&camera, cameraMode, radius);
        }        
    }

    
    CloseWindow();       

    return 0;
}