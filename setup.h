#include <stdint.h>
#include <stdlib.h>

#define WIDTH  1280
#define HEIGHT 720

#define SNAKE_SZ 2048

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