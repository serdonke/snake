#include <stdint.h>

#define WIDTH  1280
#define HEIGHT 720

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
