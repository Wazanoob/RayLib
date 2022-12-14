#include "raylib.h"
#include "./projects/VS2017/examples/Apple.h"
#include "./projects/VS2017/examples/Snake.h"
#include "./projects/VS2017/examples/Collisions.h"
#include "./projects/VS2017/examples/TextDisplay.h"
#include <string>

using namespace std;

void Update();
void Draw();
Vector2 RandomPos();

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int m_playerPoint = 0;
int m_result = 0;

Texture2D m_wallTexture;
Apple m_apple;
Snake m_snake;

TextDisplay m_playerScoreText = TextDisplay(100, 100, to_string(m_playerPoint), 20, LIGHTGRAY);
TextDisplay m_outcomeText = TextDisplay(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 3, "", 40, LIGHTGRAY);
TextDisplay m_restartText = TextDisplay(SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2, "", 40, LIGHTGRAY);

int main(int argc, char* argv[])
{
    //Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SNAKE GAME");
    SetTargetFPS(60);

    Vector2 randomPos = RandomPos();

    m_apple = Apple(randomPos.x, randomPos.y, 32);
    m_snake = Snake(384, 288, 32, 2);

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
            //UpperWall
            int offset = 1;
            int coordX = m_wallTexture.width / (divideTexture);
            Vector2 newXPos = { coordX * i, m_wallTexture.height / (2 * divideTexture) - offset };
            Rectangle m_wallXPos = { newXPos.x, newXPos.y, (m_wallRectangle.width / divideTexture), (m_wallRectangle.height / divideTexture) };

            DrawTexturePro(
                m_wallTexture,
                m_wallRectangle,
                m_wallXPos,
                m_wallCenter,
                0,
                WHITE);

            //LowerWall
            offset = 9;
            Vector2 newXSecondPos = { coordX * (i + 1), SCREEN_HEIGHT - (m_wallTexture.height / (2 * divideTexture)) + offset};
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
            int offset = 3;
            int coordY = m_wallTexture.height / (divideTexture);
            Vector2 newYPos = { (m_wallTexture.width / (2 * divideTexture)) - offset, coordY * (i + 1) };
            Rectangle m_wallYPos = { newYPos.x, newYPos.y, (m_wallRectangle.width / divideTexture), (m_wallRectangle.height / divideTexture) };

            DrawTexturePro(
                m_wallTexture,
                m_wallRectangle,
                m_wallYPos,
                m_wallCenter,
                0,
                WHITE);

            Vector2 newXSecondPos = { SCREEN_WIDTH - (m_wallTexture.width / (2 * divideTexture)) + offset, coordY * i };
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
    if (m_result == 0)
    {
        m_apple.Update();
        m_snake.Update();

        //RectangleI appleRect = m_apple.GetRect();
        //RectangleI snakeRect = m_snake.GetRect();

        //bool colliding = Collisions::AABBCollision(appleRect, snakeRect);

        if (m_snake.GetX() == m_apple.GetX() && m_snake.GetY() == m_apple.GetY())
        {
            Vector2 randomPos = RandomPos();
            m_apple.NextPos(randomPos);

            ++m_playerPoint;

            m_snake.AddBody();
            m_snake.SetSpeed(1.25f);

            m_playerScoreText.SetText(to_string(m_playerPoint));
        }

        //Points
        if (m_snake.GetX() < 32 ||
            m_snake.GetX() >= (SCREEN_WIDTH - 32) ||
            m_snake.GetY() < 32 ||
            m_snake.GetY() >= SCREEN_HEIGHT - 32)
        {
            m_outcomeText.SetText("Defeat");
            m_result = 1;
        }
    }
    else
    {
        m_restartText.SetText("Press R to restart");

        if (IsKeyDown(KEY_R))
        {
            //Restart the Game;
            m_restartText.~TextDisplay();
            m_outcomeText.~TextDisplay();
            m_playerPoint = 0;
            m_snake.Restart();

            Vector2 randomPos = RandomPos();
            m_apple.NextPos(randomPos);

            m_result = 0;
        }
    }
}

void Draw()
{
    m_playerScoreText.Draw();
    m_apple.Draw();
    m_snake.Draw();
    m_outcomeText.Draw();
    m_restartText.Draw();
}

Vector2 RandomPos()
{
    int x = GetRandomValue(1, 23) * 32;
    int y = GetRandomValue(1, 17) * 32;

    Vector2 newPos = { x, y };
    return newPos;
}

