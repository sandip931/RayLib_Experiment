// from ray
#include "./include/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "./include/raygui.h"

// locals 
#define maxPositions 10

struct food{
  Vector2 position[maxPositions]={-3};
  float radius;
  Color color;
};

Color randColor(){
  Color other;
  other=WHITE;
  // other.r = GetRandomValue(90,220); 
  // other.g = GetRandomValue(90,120); 
  // other.b = GetRandomValue(90,220); 
  // other.a = 0; 
  return other;
}

Color bgColor = {30,20,30,5};
Vector2 winSize = {1023,700};
food f;
int count=0;

int main(){

  f.radius=10;
  f.color = randColor();
  bool isEaten = true;
  bool showPosition=true;
  int start = 0;
  bool isClicked = false;
  bool lightMode = false;
   
  Vector2 widthtoogleTheme = {240,35};
  Rectangle toogleTheme = {winSize.x - widthtoogleTheme.x,winSize.y - widthtoogleTheme.y,widthtoogleTheme.x,widthtoogleTheme.y};

  InitWindow(winSize.x,winSize.y,"storing positions and drawing points accordingly");

  {

    GuiSetStyle(DEFAULT, TEXT_SIZE, 24);

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
      if(GuiButton(toogleTheme,"#810#mode")){
        lightMode = !lightMode;
      }

      
      if(!isClicked){
        if(GuiButton((Rectangle){ 24, 24, 190, 30 }, "#191#Start Game")){
          isClicked = true; 
        }
      }
      if(IsKeyPressed(KEY_SPACE)){
        isEaten=true;
      }

      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && count < maxPositions){
        f.position[count] = GetMousePosition();
        count++; 
      }
      if(isEaten && isClicked){
        start++;
        isEaten = false;
      }

      BeginDrawing();
      {

      if(lightMode){
        ClearBackground(RAYWHITE);
        f.color = BLACK;
      }
      else{
        ClearBackground(bgColor);
        f.color = WHITE;
      }
      DrawText(TextFormat("log: isClicked:%d",isClicked),0,winSize.y-35,30,WHITE);  

      if(showPosition){
        if(start<maxPositions){
          for(int i=0;i<count;i++){
            DrawCircleV(f.position[i],3,GREEN);
            if(i==maxPositions-1 && isClicked){
              showPosition = false;
            }
          }
        }
      }

      if(count==maxPositions && start<maxPositions && isClicked){
        DrawCircleV(f.position[start],f.radius,f.color);
      }
      }

      EndDrawing();
    }
  }
  CloseWindow();
}
