#include "./include/raylib.h"
#define MAX_SPAWN 12 

struct Button {
  Vector2 position;
  Color color;
  float radius;
  Vector2 text_pos;
};

Color randColor(){
  Color other;
  other.r = GetRandomValue(100,250); 
  other.g = GetRandomValue(100,255);
  other.b = GetRandomValue(100,255); 
  other.a = GetRandomValue(230,255); 
  return other;
}

struct point{
  Vector2 position;
  Color colr;
};

int main(){

  /*-------------- INITIALIZATIONS ----------------------------------*/
  Vector2 winSize = {1023,600};
  point dots[MAX_SPAWN];
  int clickCount=0;
  int clickRemaning=MAX_SPAWN;
  Color bg = {30,30,40,(unsigned char)0.9};
  Button btn;

  btn.radius = 25;
  btn.position = {0+btn.radius+12,winSize.y-btn.radius-12};
  btn.color = MAROON;

  /*-------------- INITIALIZATIONS ----------------------------------*/

  InitWindow(winSize.x,winSize.y,"window");
  {
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
      DrawCircleV(btn.position,btn.radius,btn.color);
      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && clickCount<MAX_SPAWN){
        dots[clickCount].position = GetMousePosition();  
        dots[clickCount].colr = randColor();
        ++clickCount;
        clickRemaning--;
      }
      BeginDrawing();
      ClearBackground(bg);
      for(int i=0;i<clickCount;i++){
        DrawCircleV(dots[i].position,12.7,dots[i].colr);
        if(i>0){
          DrawLineEx(dots[i-1].position,dots[i].position,9,dots[i].colr);
        }
      }
      if(clickRemaning>0){
        DrawText(TextFormat("Points Remaning : %d",clickRemaning),0,0,44,PINK);
      }else{
        DrawText(TextFormat("Out of Points"),0,0,44,RED);
      }
      EndDrawing();
    }
  }
  CloseWindow();


  return 0;
}
