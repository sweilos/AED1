#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point* array;
    int top;
} Stack;

void initStack(Stack* stack, int capacity) {
    stack->array = (Point*)malloc(sizeof(Point) * capacity);
    stack->top = -1;
}

void push(Stack* stack, int row, int col) { // empilhar
    stack->top++;
    stack->array[stack->top].row = row;
    stack->array[stack->top].col = col;
}

void pop(Stack* stack) { // desempilhar
    stack->top--;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

Point top(Stack* stack) {
    return stack->array[stack->top];
}

int isValidMove(int maze[SIZE][SIZE], int row, int col) {
    if (col == 9 && row == 9){
        return 5;
    }

    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && maze[row][col] == 0);

}

void printMaze(int maze[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (maze[i][j] == 3){
                printf("(%d, %d)", i+1, j+1);
            }

        }
    }

}

int solveMaze(int maze[SIZE][SIZE], int row, int col)
{
    int found = 0;
    int solved = 0;
    maze[row][col] = 3;

    Stack stack;
    initStack(&stack, SIZE * SIZE);

    push(&stack, row, col);


    while(1){
        Point current = top(&stack);

        if (current.row == SIZE - 1 && current.col == SIZE - 1) {
            maze[current.row][current.col] = 3;
            return 1;
        }

        int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i = 0; i < 4; i++) {

            int newRow = current.row + moves[i][0];
            int newCol = current.col + moves[i][1];

            if (isValidMove(maze, newRow, newCol)) {
                push(&stack, newRow, newCol);
                found = 1;
                maze[newRow][newCol] = 3;
                break;
            }
        }
        if (!found)
        {
            pop(&stack);
        }
    }
}