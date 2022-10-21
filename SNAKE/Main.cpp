#include "raylib.h"
#include <string>

using namespace std;

Texture2D m_wallTexture;
Texture2D m_appleTexture;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[])
{
    //Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SNAKE GAME");
    SetTargetFPS(60);

    //image = LoadImage("C:/Users/cpaya/Documents/ArtFx/RayLib/BasicInteraction_RaylibVSCommunity/resources/wall.png");
    //m_wallTexture = LoadTextureFromImage(image);
    //UnloadImage(image);

    //image = LoadImage("C:/Users/cpaya/Documents/ArtFx/RayLib/BasicInteraction_RaylibVSCommunity/resources/apple.png");
    //m_appleTexture = LoadTextureFromImage(image);
    //UnloadImage(image);

#ifndef Walls
    m_wallTexture = LoadTexture("C:/Users/cpaya/Documents/ArtFx/Raylib/Snake/resources/wall.png");

    int divideTexture = 8;
    int numberOfWallsX = SCREEN_WIDTH / (m_wallTexture.width / (divideTexture));
    int numberOfWallsY = SCREEN_HEIGHT / (m_wallTexture.width / (divideTexture));

    Rectangle m_wallRectangle = { 0, 0, m_wallTexture.width, m_wallTexture.height };
    Vector2 m_wallCenter = { m_wallTexture.width / (2 * divideTexture), m_wallTexture.height / (2 * divideTexture) };
#endif // !Walls

#ifndef Apple
    m_appleTexture = LoadTexture("C:/Users/cpaya/Documents/ArtFx/Raylib/Snake/resources/apple.png");

    int multiplyTexture = 2;
    Rectangle m_appleRectangle = { 0, 0, m_appleTexture.width, m_appleTexture.height };
    Vector2 m_appleCenter = { m_appleTexture.width / (2 / multiplyTexture), m_appleTexture.height / (2 / multiplyTexture) };
#endif // !Apple

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update

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

        //DRAW THE APPLE ?
        Rectangle m_applePos = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, (m_appleRectangle.width * multiplyTexture), (m_appleRectangle.height * multiplyTexture) };

        DrawTexturePro(
            m_appleTexture,
            m_appleRectangle,
            m_applePos,
            m_appleCenter,
            0,
            WHITE);


        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(m_wallTexture);       // Texture unloading

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}