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
  
  /// rolling ball player properties 
  ball player2;
  player2.rad = 12;
  player2.pos={player2.rad + 22,groundPoint- player2.pos.y};
  Vector2 rotatingBallTempPos = player2.pos;
  /// rolling ball player properties 

  // physics object properties 
  phy.gravity = .91;
  phy.velocity = 0;
  phy.bounce = -1;

  phyobj.rad = 12;
  phyobj.offest = 9;
  phyobj.pos = {winSize.x/2, 0 + phyobj.rad + phyobj.offest};
  Vector2 tempPos = phyobj.pos;

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
      /// ball movement towards x axis right 
      player2.pos.x += 3; 
      
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

      // revert physics object position 

      if(IsKeyPressed(KEY_SPACE)){
        phyobj.pos = tempPos;
      }

      if(IsKeyPressed(KEY_TAB)){
        player2.pos = rotatingBallTempPos;
      }

      BeginDrawing();
      {
        ClearBackground(dark);
        // DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color)
        
        // GROUND LINE  
        DrawLineEx(Vector2{0,winSize.y/2},Vector2{winSize.x,winSize.y/2},22,GRAY);
        // GROUND LINE 

        // player line axis from left
        DrawLineEx(Vector2{0,winSize.y/2},Vector2{player.pos.x,player.pos.y},2,MAROON);

       // player line axis from right  
        DrawLineEx(Vector2{winSize.x,winSize.y/2},Vector2{player.pos.x,player.pos.y},2,RED);
        
        // moving line from ball to player 

        DrawLineEx(Vector2{phyobj.pos.x,phyobj.pos.y},Vector2{player.pos.x,player.pos.y},2,GREEN);

        //// line for bouncing object 
        DrawLineEx(Vector2{winSize.x/2,0},Vector2{phyobj.pos.x,phyobj.pos.y},2,PURPLE);
        //// line for bouncing object 
        
        // line from x axis moving object to player  
        DrawLineEx(Vector2{player2.pos.x,player2.pos.y},Vector2{player.pos.x,player.pos.y},2,RAYWHITE);
        // END OF line from x axis moving object to player  
        
        // player object moving object 
        DrawCircle(player.pos.x,player.pos.y,player.rad,ORANGE);


        // rolling circle 
        DrawCircle(player2.pos.x,player2.pos.y,player2.rad,MAGENTA);

        // DrawLineEx((Vector2){0, groundPoint}, (Vector2){winSize.x, groundPoint}, 4.0f, DARKGRAY);
        DrawLineEx(
            (Vector2){0, groundPoint + phyobj.rad},
            (Vector2){winSize.x, groundPoint + phyobj.rad},
            4.0f,
            DARKGRAY
            );

        ballDraw(phyobj,WHITE);
      }

      EndDrawing();
    }
  }
  CloseWindow();
  return 0;
}
