#include <stdint.h>
#include <stdlib.h>

#define BLOCK_SIZE 40
#define BLOCK_COUNT 25

#define WIDTH  BLOCK_SIZE * BLOCK_COUNT
#define HEIGHT BLOCK_SIZE * BLOCK_COUNT

#define SNAKE_SZ 2048

typedef struct Rect
{
  int x;
  int y;
  float width;
  float height;
} Rect;

typedef struct Player
{
    Rect player;
    int x_direction;
    int y_direction;
    double speed;
} Player;

typedef struct Food
{
    Rect entity;
    double roundedness;
    Color color;
} Food;

Vector2 snake_positions[1024];
Player snake;
Food food;

void Initialize_game(void);
bool DetectRectCollision(Rect a, Rect b);
void SnakeControl(double dt);