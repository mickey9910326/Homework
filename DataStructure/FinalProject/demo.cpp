#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
int count = 0;
int min = 0;
int Width = 0,Height =0;

typedef struct {
    int x;
    int y;
} Point;

Point pt(int, int);
int visit(int[][SIZE], Point, Point);
void print(int[][SIZE]);

int main(void) {
    int maze[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] =2 ;
        }
    }


    scanf("%d", &Width);
    scanf("%d", &Height);
    for (int i = 1; i <= Height; i++) {
        for (int j = 1; j <= Width; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    // print(maze);

    if(!visit(maze, pt(1, 1), pt(Height, Width))) {
        //printf("0");
    }

    printf("\n%d",min-1);

    // print(maze);
    // printf("----------------\n");
    // printf("count = %d\n",min);
    // print(maze);

    return 0;
}

Point pt(int x, int y) {
    Point p = {x, y};
    return p;
}

int visit(int maze[][SIZE], Point start, Point end) {
    count++;

    // print(maze);
    // printf("count = %d\n",count);
    // printf("start = %d,%d,%d\n",start.x,start.y,maze[start.x][start.y]);

    if(!maze[start.x][start.y]) {
         maze[start.x][start.y] = 1;
         if(
            !(visit(maze, pt(start.x    , start.y + 1), end) || //右
              visit(maze, pt(start.x + 1, start.y    ), end) || //下
              visit(maze, pt(start.x    , start.y - 1), end) || //左
              visit(maze, pt(start.x - 1, start.y    ), end) )  //上
           ) {
                 maze[start.x][start.y] = 0;
         }
    }
    if (start.x==end.x && start.y==end.y) {
        if (min > count) {
            min = count;
            maze[start.x][start.y] = 0;
            //printf("min = %d\n", min);
        }
    }
    count--;
    // printf("e--count = %d",count);
    // printf("   start = %d,%d,%d",start.x,start.y,maze[start.x][start.y]);
    // printf("   start & end= %d,%d\n",start.x==end.x,start.y==end.y);
    return maze[end.x][end.y];
}

void print(int maze[][SIZE]) {
    int i, j;
    for(i = 0; i < Height+2; i++) {
        for(j = 0; j < Width+2; j++)
            printf("%d",maze[i][j]);
        printf("\n");
    }
}
