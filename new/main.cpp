#include "./include/raylib.h"
#include "color.h"

// globals 
Vector2 winSize = {1025,702};

struct ball{
  Vector2 position;
  float radius;
  Color color;
};
int main(){
  //// -------------------- VARIABLE INITIALIZATIONS --------------------------
  /// ------------ obect 1 properties 
  ball b1;
  b1.position = {100,100};
  b1.radius = 30;
  b1.color = COLOR_DARKRED;
  /// ------------ obect 1 properties 

  //// physics //
  float gravity = 8;
  float velocity = 0;
  float bounce = -0.999;
  ///
  InitWindow(winSize.x,winSize.y,"newWindow");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    // ClearBackground(COLOR_CORNSILK);
    ClearBackground(COLOR_SILVER);
    DrawCircleV(b1.position,b1.radius,b1.color);
    DrawLineEx(Vector2{0,600},Vector2{200,600},30,ORANGE);
    velocity += gravity;
    b1.position.y+=velocity;
    
    if(b1.position.y>=600){
      b1.position.y = 600;
      velocity *= bounce;
    }

    EndDrawing();

  }
  CloseWindow();
}
