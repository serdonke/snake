#include "setup.h"

uint64_t snake_size = 0;

int main(void)
{
    Initialize_game();

    InitWindow(WIDTH, HEIGHT, "Gaym");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        double dt = GetFrameTime();

        SnakeControl(dt);

        //TODO: Switch to a better collision function
        //NOTE: Maye AABB might help
        CollisionFunctions();

        DebugFunctions();

        BeginDrawing();
            ClearBackground(SAGE);

            DrawRectangleRounded((Rectangle){(int)food.entity.x * BLOCK_SIZE, (int)food.entity.y * BLOCK_SIZE, food.entity.width, food.entity.height}, food.roundedness, 1, food.color);

            DrawRectangleRec((Rectangle){(int)snake.player.x * BLOCK_SIZE, (int)snake.player.y * BLOCK_SIZE, snake.player.width, snake.player.height}, REDISH);

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
    snake.player.y = 14;
    snake.speed = 15.0f;

    food.entity.height = BLOCK_SIZE;
    food.entity.width  = BLOCK_SIZE;
    food.entity.x = 0;
    food.entity.y = 10;
    food.roundedness = 0.95;
    food.color = ORANGISH;
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

    WrapSnakeBody();
}

void CollisionFunctions(void)
{
    if(DetectRectCollision(snake.player, food.entity))
    {
        food.entity.x = 0;
        food.entity.y = GetRandomValue(0, BLOCK_COUNT - 1);
        snake_size++;

        //dbg
        printf("Snake {%lf, %lf}, FOOD {%lf, %lf}\n", snake.player.x, snake.player.y, food.entity.x, food.entity.y);
    }

}

//NOTE This is a bit buggy rn, the snake head can change directions while off screen.
void WrapSnakeBody(void)
{
    if (snake.player.x < 0 && snake.x_direction == -1)
    {
        snake.player.x += (BLOCK_COUNT + WRAP_DELAY);
    }
    else if (snake.player.x > BLOCK_COUNT && snake.x_direction == 1)
    {
        snake.player.x -= (BLOCK_COUNT + WRAP_DELAY);
    }
    
    
    if (snake.player.y < 0 && snake.y_direction == -1)
    {
        snake.player.y += (BLOCK_COUNT + WRAP_DELAY);
    }
    else if (snake.player.y > BLOCK_COUNT && snake.y_direction == 1)
    {
        snake.player.y -= (BLOCK_COUNT + WRAP_DELAY);
    }
    
}

bool DetectRectCollision(Rectangle a, Rectangle b)
{
    return ((floor(a.x) == floor(b.x)) && (floor(a.y) == floor(b.y)));
}

void DebugFunctions(void)
{
    if (IsKeyReleased(KEY_SPACE))
    {
        printf("Frame-Time: %lf\n", GetFrameTime());
    }

}
