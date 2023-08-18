#include "maze.h"

int main()
{
    int maze[SIZE][SIZE] =
    {
            {0, 1, 0, 1, 1, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
            {1, 1, 1, 0, 1, 0, 1, 1, 1, 0},
            {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 1, 1, 1, 1, 0},
            {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
            {1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 1, 0, 1, 1, 0, 1},
            {0, 0, 1, 1, 1, 0, 0, 0, 0, 0}
    };

    if (solveMaze(maze, 0, 0))
    {
        printf("O labirinto possui saida\n");
        printMaze(maze);
    }
    else
    {
        printf("O labirinto nao possui saida\n");
    }

    return 0;
}
