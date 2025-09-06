#include "./include/raylib.h"
#include <iostream>
class player {
  private:
    Vector2 initPosition;
    float radius;
    Color color=RED;
  public:
    player(Vector2 pos,float r, Color c):initPosition(pos),radius(r),color(c){};
    player():initPosition((Vector2){100,100}),radius(11),color(RED){}

    void randPos(){

    } 

      
    void invoke(){
      DrawCircleV(initPosition,radius,color); 
    }
};
Vector2 winSize = {1030,720};
int main(){

  Vector2 playerPos={200,200};
  InitWindow(winSize.x,winSize.y,"something");
  while (!WindowShouldClose()) {
  player p(playerPos,12,ORANGE);
    if(IsKeyPressed(KEY_W)){
      playerPos.x+=50;
    }
    BeginDrawing();
    p.invoke();
    EndDrawing();

  }
  CloseWindow();

  return 0;
}
