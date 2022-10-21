#include "./projects/VS2017/examples/Ball.h"
#include "./projects/VS2017/examples/Paddle.h"
#include "./projects/VS2017/examples/TextDisplay.h"

using std::to_string;

void Update();
void Draw();

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

int m_playerFail = 0;
int m_result = 0;

Ball m_ball;
Paddle m_leftPaddle;
Music m_music;

TextDisplay m_playerScoreText = TextDisplay(100, 100, to_string(m_playerFail), 20, LIGHTGRAY);
TextDisplay m_outcomeText = TextDisplay(SCREEN_WIDTH / 2 -50, SCREEN_HEIGHT / 3, "", 40, LIGHTGRAY);
TextDisplay m_restartText = TextDisplay(SCREEN_WIDTH / 2 -200, SCREEN_HEIGHT / 2, "", 40, LIGHTGRAY);

int main(int argc, char* argv[])
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "PONG");
    SetTargetFPS(60);
    InitAudioDevice();

    m_ball = Ball(100, 100, 32, 5);
    m_leftPaddle = Paddle(0, 200, 32, 128, 4);

    //Ca arrive po à load je sais pas pourquoi help :((
    m_music = LoadMusicStream("resources/Adtr.wav");
    PlayMusicStream(m_music);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateMusicStream(m_music);

        // Update
        Update();

        // Draw
        Draw();
    }

    UnloadMusicStream(m_music);
    CloseWindow();
    CloseAudioDevice();

    return 0;
}

void Update()
{
    if (m_result == 0)
    {
        m_ball.Update();
        m_leftPaddle.Update();

        RectangleI ballRect = m_ball.GetRect();
        RectangleI leftPaddleRect = m_leftPaddle.GetRect();

        bool colliding = Collisions::AABBCollision(ballRect, leftPaddleRect);

        if (colliding)
        {
            m_ball.HorizontalBounce(leftPaddleRect.x + leftPaddleRect.width);
        }

        //Points
        if (m_ball.GetX() < 0)
        {
            ++m_playerFail;
            m_ball.SetX(SCREEN_WIDTH / 2); //Needs to be replaced with random location and random speed.
            m_playerScoreText.SetText(to_string(m_playerFail));

            if (m_playerFail >= 3)
            {
                m_result = 1;
                m_outcomeText.SetText("Defeat");
            }
        }
        //else if (m_ball.GetX() > SCREEN_WIDTH - m_ball.GetWidth())
        //{
        //    ++m_playerPoints;
        //    m_ball.SetX(SCREEN_WIDTH/2);
        //}
    }
    else   //End Game
    {
        m_restartText.SetText("Press R to restart");
        if (IsKeyDown(KEY_R))
        {
            //Restart the Game;
            m_restartText.~TextDisplay();
            m_outcomeText.~TextDisplay();
            m_playerFail = 0;
            m_result = 0;
        }
    }
}

void Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    m_playerScoreText.Draw(); //First being draw, so its behind
    m_ball.Draw();
    m_leftPaddle.Draw();
    m_outcomeText.Draw();
    m_restartText.Draw();

    EndDrawing();
}