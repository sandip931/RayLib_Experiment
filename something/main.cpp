#include "./include/raylib.h"
struct ball{
 Vector2 pos;
 float rad;
 Color color;
};
Vector2 RandomFruitPosition(Vector2 winSize,float rad){
  Vector2 position;
  position.x =  GetRandomValue(0,(int)winSize.x-rad);
  position.y =  GetRandomValue(0,(int)winSize.y-rad);
  return position;
}
int main(){
  int points=0;
  Vector2 winSize={872,645};
  Vector2 direction = {1,0};
  bool isGameStart = false;
  ball man; 
  ball fruit;
  int count=0;
  ////
  man.pos = {100,100};
  man.rad = 13;
  man.color = PURPLE;
  int speed = 4;
  fruit.rad = 12;
  fruit.color = GREEN;
  bool Eaten = true;
  ////
 InitWindow(winSize.x,winSize.y,"New Window");
 SetTargetFPS(60);
   while (!WindowShouldClose()) {
     if(count>5){
       speed+=5;
       count = 0;
     }
     if(CheckCollisionCircles(man.pos,man.rad,fruit.pos,fruit.rad)){
        Eaten = true;
        points++;
        count++;
     }
     if(IsKeyPressed(KEY_SPACE)){
       isGameStart = true;
     }
     if(Eaten){
       fruit.pos = RandomFruitPosition(winSize,fruit.rad);
       Eaten = false;
     }
     BeginDrawing();
     {
       ClearBackground(Color{32, 33, 36, 255});
       // DrawCircle(200, 200,20 ,PURPLE);
       DrawCircleV(man.pos,man.rad,man.color);
       DrawCircleV(fruit.pos,fruit.rad,fruit.color);
       DrawText(TextFormat("Score: %d",points),0,0,35,PINK);
       if(!isGameStart){
        DrawText(TextFormat("Press Space key to start game "),100,winSize.y/2,33,WHITE);
        DrawText(TextFormat("the speed increases every 5+ points"),100,winSize.y/3,40,ORANGE);
       }
     }
     EndDrawing();
     /////// processesss ////////
     if(isGameStart){
       if(IsKeyPressed(KEY_A) && direction.x!=1){
         direction = {-1,0};
       }
       if(IsKeyPressed(KEY_D)&& direction.x!=-1){
         direction = {1,0};
       }
       if(IsKeyPressed(KEY_W)&& direction.y !=1){
         direction ={0,-1};
       }
       if(IsKeyPressed(KEY_S)&& direction.y !=-1){
         direction = {0,1};
       }
       man.pos.x += speed*direction.x; 
       man.pos.y += speed*direction.y;
       if(man.pos.x>winSize.x){
         man.pos.x = 0;
       }

       if(man.pos.x<0){
         man.pos.x = winSize.x;
       }

       if(man.pos.y>winSize.y){
         man.pos.y = 0;
       }

       if(man.pos.y<0){
         man.pos.y = winSize.y;
       }

     }
    
     // bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);
   }
   CloseWindow();
   return 0;
}
