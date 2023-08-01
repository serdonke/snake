#include <raylib.h>
#include <stdio.h>
#include "setup.h"

int main(void)
{
    Initialize_game();

    uint64_t snake_size = 0;

    InitWindow(WIDTH, HEIGHT, "Gaym");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        double dt = GetFrameTime();

        if (IsKeyReleased(KEY_RIGHT) && snake.x_direction != -1)
        {
            snake.y_direction = 0;
            snake.x_direction = 1;
        }
        else if (IsKeyReleased(KEY_LEFT) && snake.x_direction != 1)
        {
            snake.y_direction = 0;
            snake.x_direction = -1;
        }
        else if (IsKeyReleased(KEY_UP) && snake.y_direction != 1)
        {
            snake.x_direction = 0;
            snake.y_direction = -1;
        }
        else if (IsKeyReleased(KEY_DOWN) && snake.y_direction != -1)
        {
            snake.x_direction = 0;
            snake.y_direction = 1;
        }
        
        if (snake.y_direction == 0)
        {
            snake.player.x += (snake.speed * snake.x_direction) * dt;
        }
        if (snake.x_direction == 0)
        {
            snake.player.y += (snake.speed * snake.y_direction) * dt;
        }

        if(CheckCollisionRecs(snake.player, food.entity))
        {
            food.entity.x = GetRandomValue(0, WIDTH);
            food.entity.y = GetRandomValue(0, HEIGHT - food.entity.y);
            snake_size++;
        }

        if (IsKeyReleased(KEY_SPACE))
        {
            printf("Frame-Time: %lf\n", dt);
        }

        BeginDrawing();
            ClearBackground(BLACK);
            DrawRectangleRounded(food.entity, food.roundedness, 1, food.color);
            DrawRectangleRec(snake.player, RED);
        EndDrawing();

        DrawFPS(10, 10);
    }
    
    CloseWindow();
    return 0;
}

void Initialize_game(void)
{
    snake.player.height = 10;
    snake.player.width  = 10;
    snake.player.x = WIDTH / 2;
    snake.player.y = HEIGHT / 2;
    snake.speed = 200.0f;

    food.entity.height = 10;
    food.entity.width  = 10;
    food.entity.x = WIDTH / 2;
    food.entity.y = HEIGHT / 2;
    food.roundedness = 0.75;
    food.color = LIME;
}