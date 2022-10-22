#include "raylib.h"
#include "./projects/VS2017/examples/Apple.h"
#include "./projects/VS2017/examples/Snake.h"
#include "./projects/VS2017/examples/Collisions.h"
#include <string>

using namespace std;

void Update();
void Draw();
Vector2 RandomPos();

Texture2D m_wallTexture;
Apple m_apple;
Snake m_snake;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[])
{
    //Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SNAKE GAME");
    SetTargetFPS(60);

    Vector2 randomPos = RandomPos();

    m_apple = Apple(randomPos.x, randomPos.y, 32);
    m_snake = Snake(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 32, 2);

#ifndef Walls
    m_wallTexture = LoadTexture("C:/Users/cpaya/Documents/ArtFx/Raylib/Snake/resources/wall.png");

    int divideTexture = 8;
    int numberOfWallsX = SCREEN_WIDTH / (m_wallTexture.width / (divideTexture));
    int numberOfWallsY = SCREEN_HEIGHT / (m_wallTexture.width / (divideTexture));

    Rectangle m_wallRectangle = { 0, 0, m_wallTexture.width, m_wallTexture.height };
    Vector2 m_wallCenter = { m_wallTexture.width / (2 * divideTexture), m_wallTexture.height / (2 * divideTexture) };
#endif // !Walls

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        Update();

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        //DRAW THE WALLS LEL
        for (size_t i = 0; i < numberOfWallsX; i++)
        {
            int coordX = m_wallTexture.width / (divideTexture);
            Vector2 newXPos = { coordX * i, m_wallTexture.height / (2 * divideTexture) };
            Rectangle m_wallXPos = { newXPos.x, newXPos.y, (m_wallRectangle.width / divideTexture), (m_wallRectangle.height / divideTexture) };

            DrawTexturePro(
                m_wallTexture,
                m_wallRectangle,
                m_wallXPos,
                m_wallCenter,
                0,
                WHITE);

            Vector2 newXSecondPos = { coordX * (i + 1), SCREEN_HEIGHT - (m_wallTexture.height / (2 * divideTexture)) };
            Rectangle m_wallXSecondPos = { newXSecondPos.x, newXSecondPos.y, (m_wallRectangle.width / divideTexture), (m_wallRectangle.height / divideTexture) };

            DrawTexturePro(
                m_wallTexture,
                m_wallRectangle,
                m_wallXSecondPos,
                m_wallCenter,
                0,
                WHITE);
        }
        for (size_t i = 0; i < numberOfWallsY; i++)
        {
            int coordY = m_wallTexture.height / (divideTexture);
            Vector2 newYPos = { m_wallTexture.width / (2 * divideTexture), coordY * (i + 1) };
            Rectangle m_wallYPos = { newYPos.x, newYPos.y, (m_wallRectangle.width / divideTexture), (m_wallRectangle.height / divideTexture) };

            DrawTexturePro(
                m_wallTexture,
                m_wallRectangle,
                m_wallYPos,
                m_wallCenter,
                0,
                WHITE);

            Vector2 newXSecondPos = { SCREEN_WIDTH - (m_wallTexture.width / (2 * divideTexture)), coordY * i };
            Rectangle m_wallXSecondPos = { newXSecondPos.x, newXSecondPos.y, (m_wallRectangle.width / divideTexture), (m_wallRectangle.height / divideTexture) };

            DrawTexturePro(
                m_wallTexture,
                m_wallRectangle,
                m_wallXSecondPos,
                m_wallCenter,
                0,
                WHITE);
        }

        Draw();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(m_wallTexture);       // Texture unloading

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void Update()
{
    m_apple.Update();
    m_snake.Update();
}

void Draw()
{
    m_apple.Draw();
    m_snake.Draw();
}

Vector2 RandomPos()
{
    int x = GetRandomValue(16, 750);
    int y = GetRandomValue(16, 350);
    Vector2 newPos = { x, y };
    return newPos;
}

