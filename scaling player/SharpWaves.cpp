
#include "./include/raylib.h"
#include <iostream>
#include <vector>
#include "./include/raymath.h"

struct ball {
    Vector2 pos;
    float rad;
    Color color;
};

int main() {
    //// VARS ---------------------
    Vector2 winSize = {1011, 700};
    char title[77] = "new window";
    int amplitude = 10;

    bool setMotion = false;
    ball player;
    player.rad = 14;
    player.pos = {20, winSize.y / 2};
    player.color = ORANGE;
    float speed = 3;

    InitWindow(winSize.x, winSize.y, "something");

    Vector2 playerInitPos = player.pos;
    int df = 1;        // start direction
    int count = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        /// processes
        if (IsKeyPressed(KEY_SPACE)) {
            setMotion = true;
        }

        if (setMotion) {
            player.pos.x += speed;  
            player.pos.y += speed*df;      
            // if(player.pos.y>20);
           count++;
            if (count == amplitude) {   // after 30 frames, flip direction
                df = -df;
                count = 0;
            }
        }

        /// DRAWINGS
        BeginDrawing();
        ClearBackground(BLACK);
        // DrawText(const char *text, int posX, int posY, int fontSize, Color color)
        DrawText(TextFormat("Position :  %d , %d",(int)player.pos.x,(int)player.pos.y),0,0,23,RED);
        DrawCircleV(player.pos, player.rad, player.color);
        // DrawLineEx(playerInitPos, player.pos, 3, ORANGE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
