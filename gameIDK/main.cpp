#include "./include/raylib.h"
#define BACKGROUND {30,30,30,13};
struct Snake{
  Vector2 position;
  float radius;
  Color color;
  float speed;
};

struct Food{
  Vector2 position;
  float radius;
  Color color;
};
Vector2 randPosition(Vector2 range,float radius){
  Vector2 other;
  other.x=GetRandomValue(0+radius,range.x-radius);
  other.y=GetRandomValue(0+radius,range.y-radius);
  return other;
}

int main(){
  //////// --------------- INITIALIZATIONS . --------------------------------------
  Vector2 winSize = {1200,720};
  float dt;

  Snake s;
  s.position = {100,100};
  s.radius = 9;
  s.color = WHITE;
  s.speed = 150;
  
  Food f;
  f.radius=12;
  f.color = GREEN;

  int points = 0;
  bool isEaten = true;
  Vector2 direction={1,0}; // {x,y}
  Color bgcolor = BACKGROUND;
  //////// --------------- INITIALIZATIONS . --------------------------------------

  
  InitWindow(winSize.x,winSize.y,"SnakeGame");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    dt=GetFrameTime();

    ////-----------inputs -------------``////

    if(IsKeyPressed(KEY_RIGHT)&& (direction.y==1 || direction.y==-1)){
     direction = {1,0}; 
    }
    if(IsKeyPressed(KEY_LEFT)&& (direction.y==1 || direction.y==-1)){
     direction = {-1,0}; 
    }
    if(IsKeyPressed(KEY_DOWN)&& (direction.x==1 || direction.x==-1)){
     direction = {0,1}; 
    }
    if(IsKeyPressed(KEY_UP)&& (direction.x==1 || direction.x==-1)){
     direction = {0,-1};
    }
    
    //////////// ------------------- COLLIDING EVENTS ----------------------/////////////////////

    if(CheckCollisionCircles(s.position,s.radius,f.position,f.radius)){
          isEaten=true;
          points++;
    }

    ///////////------------ auto events ----------------
      s.position.x += s.speed*dt*direction.x; ///default goint right snake    
      s.position.y += s.speed*dt*direction.y; ///default goint right snake    
    BeginDrawing();
    ClearBackground(bgcolor);
    if(isEaten){
      f.position = randPosition(winSize,f.radius);
      isEaten = false;
    }
    DrawCircleV(f.position,f.radius,f.color);
    DrawCircleV(s.position,s.radius,s.color);
    DrawText(TextFormat("Score : %d ",points),10,5,45,ORANGE);
    EndDrawing();
  }
  CloseWindow();
}
