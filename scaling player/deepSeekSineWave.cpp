#include "include/raylib.h"
#include <ctime>
#include <math.h>

int main(void)
{
    // Initialize window
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Sine Wave Movement");
    
    // Circle properties
    Vector2 circlePosition = { 100, screenHeight/2 };
    Vector2 circlePosition1 = {50,screenHeight/2};
    float circleRadius = 20;
    Color circleColor = BLUE;
    
    // Sine wave properties
    float amplitude = 100.0f;   // Height of the wave
    float amplitude1 = 130.0f;
    float frequency = 0.05f;    // How often the wave oscillates
    float frequency1 = 0.01f;    // How often the wave oscillates
    float time = 0.0f;          // Time counter
    float speed = 1.0f;         // Horizontal speed
    float speed1 = 3.0f;
    
    SetTargetFPS(60);           // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        time += GetFrameTime(); // Update time with delta time
        
        // Calculate new position using sine wave formula
        circlePosition.x += speed;
        circlePosition.y = screenHeight/2 + sinf(circlePosition.x * frequency + time) * amplitude;

        circlePosition1.x += speed1;
        circlePosition1.y = screenHeight/2 + sinf(circlePosition1.x*frequency1+time)*amplitude1;
        
        // Wrap around when circle goes off screen
        if (circlePosition.x > screenWidth + circleRadius)
            circlePosition.x = -circleRadius;

        if (circlePosition1.x > screenWidth + circleRadius)
            circlePosition1.x = -circleRadius;

        // Draw
        BeginDrawing();
            ClearBackground(BLACK);
            
            // Draw the moving circle
            DrawCircleV(circlePosition, circleRadius, circleColor);
            ///// sandip --- draw text with position under both circles .... 
            DrawCircleV(circlePosition1,circleRadius,ORANGE);
            // DrawLineEx();
            // DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color)
            
            // Draw some information text
            DrawText("Circle moving in a sine wave pattern", 10, 10, 20, DARKGRAY);
            DrawText("Press ESC to exit", 10, 40, 20, DARKGRAY);
            
            // Draw the sine wave path
            for (int x = 0; x < screenWidth; x += 2) {
                int y = screenHeight/2 + sinf(x * frequency + time) * amplitude;
                DrawPixel(x, y, RAYWHITE);
            }
            for (int x = 0; x < screenWidth; x += 3) {
                int y = screenHeight/2+sinf(x*frequency1+time)*amplitude1;
                DrawPixel(x,y,WHITE);
            }
            
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
