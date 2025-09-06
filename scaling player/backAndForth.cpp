#include "./include/raylib.h"
#include<iostream>
#include <vector>
#include "./include/raymath.h"

struct ball{
  Vector2 pos;
  float rad;
  Color color;
};
int main(){
//// VARS ---------------------
  // window  
  Vector2 winSize={1011,700};
  char title[77] = "new window";
  
  // player
  bool setMotion=false;
  ball player;
  player.rad = 14;
  player.pos = {winSize.x/2,winSize.y/2};
  player.color = ORANGE;
  float speed  = 3;
  InitWindow(winSize.x,winSize.y,"something");
  Vector2 playerInitPos=player.pos;
  int df ;
  int count=0;

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    /// processess
    ///
    if(IsKeyPressed(KEY_X)){
     setMotion = true; 
    }
    if(setMotion){
      player.pos.x+= speed*df;
      player.pos.y-= speed*df;
      count++;
      if(count == 30){
        df = -df;
        count=0;
      }
    }
    /// DRAWINGS 
    BeginDrawing();
    ClearBackground(BLACK);
    DrawCircleV(player.pos,player.rad,player.color);
    // DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color)
    DrawLineEx(playerInitPos,player.pos,7,ORANGE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
} 
