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

        SnakeControl(dt);

        if(DetectRectCollision(snake.player, food.entity))
        {
            food.entity.x = GetRandomValue(0, BLOCK_COUNT - 1);
            food.entity.y = GetRandomValue(0, BLOCK_COUNT - 1);
            snake_size++;
        }

        if (IsKeyReleased(KEY_SPACE))
        {
            printf("Frame-Time: %lf\n", dt);
        }

        BeginDrawing();
            ClearBackground(BLACK);

            DrawRectangleRounded((Rectangle){(int)food.entity.x * BLOCK_SIZE, (int)food.entity.y * BLOCK_SIZE, food.entity.width, food.entity.height}, food.roundedness, 1, food.color);

            DrawRectangleRec((Rectangle){(int)snake.player.x * BLOCK_SIZE, (int)snake.player.y * BLOCK_SIZE, snake.player.width, snake.player.height}, RED);

        EndDrawing();

        DrawFPS(10, 10);
    }
    
    CloseWindow();
    return 0;
}

void Initialize_game(void)
{
    snake.player.height = BLOCK_SIZE;
    snake.player.width  = BLOCK_SIZE;
    snake.player.x = 5;
    snake.player.y = 10;
    snake.speed = 15.0f;

    food.entity.height = BLOCK_SIZE;
    food.entity.width  = BLOCK_SIZE;
    food.entity.x = 0;
    food.entity.y = 10;
    food.roundedness = 0.95;
    food.color = LIME;
}

bool DetectRectCollision(Rect a, Rect b)
{
    return ((floor(a.x) == floor(b.x)) && (floor(a.y) == floor(b.y)));
}

void SnakeControl(double dt)
{
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
}