#include "./include/raylib.h"

struct ball{
  Vector2 pos;
  float rad;
  float offest;
};
struct physics{
  float velocity;
  float gravity;
  float bounce;
  float drag;
  float weight;
};

void ballDraw(ball b,Color y){
  DrawCircle(b.pos.x,b.pos.y,b.rad,y);
}

int main(){
  Vector2 winSize = {720,690};
  float dt ;
  ball phyobj;
  physics phy;
  ball player;
  float groundPoint = 600;

  /// player property 
  player.pos={100,200};
  player.rad=9;
  float copyRad = player.rad;
  /// player property 
  // physics object properties 
  phy.gravity = .91;
  phy.velocity = 0;
  phy.bounce = -0.98;

  phyobj.rad = 12;
  phyobj.offest = 9;
  phyobj.pos = {winSize.x/2, 0 + phyobj.rad + phyobj.offest};
  // physics object properties 
  //
  ///
  Color dark = {30,30,30,0};
  InitWindow(winSize.x,winSize.y,"new window");

  {
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
    dt = GetFrameTime();

     ////////// auto update gravity
        phy.velocity += phy.gravity;
        phyobj.pos.y += phy.velocity;
        if(phyobj.pos.y>=groundPoint){
          phyobj.pos.y = groundPoint;
          phy.velocity *= phy.bounce;
        }
        phy.gravity = 1.5;
        phyobj.pos.y+=5;
      /// player action movement data ----------- 
      if(IsKeyDown(KEY_RIGHT)){
        player.pos.x += 12;
      }
      if(IsKeyDown(KEY_LEFT)){
        player.pos.x -= 12;
      }
      if(IsKeyDown(KEY_DOWN)){
        player.pos.y += 12;
      }
      if(IsKeyDown(KEY_UP)){
        player.pos.y -= 12;
      }
      if(player.pos.y >= winSize.y/2  ){
        player.rad = 20 ;
      } else{
        player.rad = copyRad;
      }
      if(phyobj.pos.y>=winSize.y/2){
        phyobj.rad = 20;
      }

      /// player action movement data ----------- 
      BeginDrawing();
      {
        ClearBackground(dark);
        // DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color)
        DrawLineEx(Vector2{0,winSize.y/2},Vector2{winSize.x,winSize.y/2},22,PURPLE);
        DrawCircle(player.pos.x,player.pos.y,player.rad,ORANGE);
        ballDraw(phyobj,WHITE);
      }

      EndDrawing();
    }
  }
  CloseWindow();
  return 0;
}
