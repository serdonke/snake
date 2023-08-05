#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define BLOCK_SIZE 40
#define BLOCK_COUNT 25

//Colors RGBA
#define SAGE      CLITERAL(Color){0xCE, 0xCE, 0x5A, 0xFF}
#define ORANGISH    CLITERAL(Color){0xFD, 0x8D, 0x14, 0xFF}
#define REDISH    CLITERAL(Color){0xC5, 0x16, 0x05, 0xFF}
#define YELLOWISH CLITERAL(Color){0xFF, 0xE1, 0x7B, 0xFF}

#define WIDTH  BLOCK_SIZE * BLOCK_COUNT
#define HEIGHT BLOCK_SIZE * BLOCK_COUNT

// How far from the border to place the snake
#define WRAP_DELAY 3

typedef struct Player
{
    Rectangle player;
    int x_direction;
    int y_direction;
    double speed;
} Player;

typedef struct Food
{
    Rectangle entity;
    double roundedness;
    Color color;
} Food;

Vector2 snake_positions[1024];
Player snake;
Food food;

void Initialize_game(void);
bool DetectRectCollision(Rectangle a, Rectangle b);
void SnakeControl(double dt);
void CollisionFunctions(void);
void WrapSnakeBody(void);

void DebugFunctions(void);