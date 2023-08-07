@echo off

if not exist build (
   mkdir build
)

if "%1"=="c" (
    del build\game.exe
    echo Built executable yeeted
) else if "%1"=="" (
    gcc -I./include -L./lib -Wall -Wextra main.c -o build/game -lraylib -lopengl32 -lgdi32 -lwinmm
    echo Build done
    echo Running
    build\game.exe
) else if "%1"=="d" (
    gcc -g -I./include -L./lib main.c -o build/game -lraylib -lopengl32 -lgdi32 -lwinmm
    echo Debug Build done
)
