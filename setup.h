#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define BLOCK_SIZE 40
#define BLOCK_COUNT 25

#define WIDTH  BLOCK_SIZE * BLOCK_COUNT
#define HEIGHT BLOCK_SIZE * BLOCK_COUNT

typedef struct Rect
{
  float x;
  float y;
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