#include "raylib.h"

int main(void)
{
    /*
    int ballX = 400;
    int ballY = 400;
    */
    Color green = {20, 160, 133, 255};

    const int screenWidth = 800;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "gikorun");

    Texture2D player = LoadTexture("resources/gikokitty.png");
    Vector2 playerPosition = { screenWidth/2.0f - player.width/2.0f, screenHeight/2.0f - player.height/2.0f };

    Color fontColor = RED;
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT))
        {
            playerPosition.x += 2.0f; 
        } else if (IsKeyDown(KEY_LEFT)){
            playerPosition.x -= 2.0f; 
        } else if (IsKeyDown(KEY_UP))
        {
            playerPosition.y -= 2.0f; 
        } else if (IsKeyDown(KEY_DOWN))
        {
            playerPosition.y += 2.0f; 
        }

        BeginDrawing();
        ClearBackground(green);
        DrawFPS(1, 1);
        DrawTextureV(player, playerPosition, WHITE);
        EndDrawing();
    }

    UnloadTexture(player);
    CloseWindow();
    return 0;

}
