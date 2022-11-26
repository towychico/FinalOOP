#include <iostream>
#include "raylib.h"
#include "gameWorldData.h"
#include "Player.h"
#include "Enemy.h"
int main() {

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    bool gameIsRunning = true;
    Vector2 mousePosition = {0,50};
    Vector2 playePosition = { (float)screenWidth/2, (float)screenHeight/2 };
    gameWorldData data = gameWorldData();
    InitWindow(data.getScreenWidth(), data.getScreenHeight(), "raylib [core] example - basic window");

    Player player   = Player(data);
    Vector2 testPosition = {1500,1000};
    Enemy test = Enemy(data,testPosition );
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        mousePosition = GetMousePosition();
        //if (IsKeyDown(KEY_RIGHT)) player.texturePosition.x += 20.0f;
        //if (IsKeyDown(KEY_LEFT)) player.texturePosition.x -= 20.0f;
        //if (IsKeyDown(KEY_UP)) player.texturePosition.y -= 20.0f;
        //if (IsKeyDown(KEY_DOWN)) player.texturePosition.y += 20.0f;
        //----------------------------------------------------------------------------------
        if (CheckCollisionRecs(player.getColition(), test.getTextureTransform())){
           std::cout<<"waaaaaaaaaa"<<std::endl;
           std::cout<<"waaaaaaaaaa"<<std::endl;
           std::cout<<"waaaaaaaaaa"<<std::endl;
           std::cout<<"waaaaaaaaaa"<<std::endl;
           std::cout<<"waaaaaaaaaa"<<std::endl;
            gameIsRunning = false;
        }

            // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
        test.updatePosition(data);
        if(gameIsRunning){
            DrawTexturePro(player.updateTexture(mousePosition,data),player.getTextureTransform(),player.getTexturePosition(),Vector2 {float(player.getTexture().width)/2,float(player.getTexture().height)/2},player.updateRotation(mousePosition),WHITE);
            }
            DrawTexturePro(test.updateTexture(data),test.getTextureTransform(),test.getTexturePosition(),Vector2 {float(test.getTexture().width)/2,float(test.getTexture().height)/2},test.getInitialRotation(),WHITE);

            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
//UnloadTexture(player.getTexture());
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------



    return 0;
}
// Sprites by: RedFoc.
// https://redfoc.com,