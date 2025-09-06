#include "./include/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "./include/raygui.h"

int main()
{
  Vector2 winSize = {1204,700};
    InitWindow(winSize.x, winSize.y, "raygui - controls test suite");
    SetTargetFPS(60);

    Vector2 checkboxwidth = {80,35};
    Rectangle checkbox = {winSize.x - checkboxwidth.x,winSize.y- checkboxwidth.y,checkboxwidth.x,checkboxwidth.y};
    bool showMessageBox = false;
    bool ischecked=false;

    while (!WindowShouldClose())
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            if (GuiButton((Rectangle){ 24, 24, 120, 30 }, "#191#Show Message")) showMessageBox = true;

            if (showMessageBox)
            {
                int result = GuiMessageBox((Rectangle){ 85, 70, 250, 100 },
                    "#191#Message Box", "Hi! This is a message!", "Nice;Cool");

                if (result >= 0) showMessageBox = false;
            }
            if(ischecked){
                  
            }else{
              ischecked = GuiButton(checkbox,"#1900#check");
            }

            EndDrawing();
    }

    CloseWindow();
    return 0;
}
