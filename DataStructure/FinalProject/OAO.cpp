#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
int count = 0;
int min = 20;

typedef struct {
    int x;
    int y;
} Point;

Point pt(int, int);
int visit(int[][SIZE], Point, Point);
void print(int[][SIZE]);

int main(void) {
    int maze[SIZE][SIZE] = {{2, 2, 2, 2, 2, 2, 2},
                            {2, 0, 0, 0, 2, 0, 2},
                            {2, 0, 2, 0, 2, 0, 2},
                            {2, 0, 0, 0, 2, 0, 2},
                            {2, 2, 2, 2, 2, 0, 2},
                            {2, 0, 0, 0, 0, 0, 2},
                            {2, 2, 2, 2, 2, 2, 2}};

    if(!visit(maze, pt(1, 1), pt(3, 3))) {
        printf("\n沒有找到出口！\n");
    }
    print(maze);
    printf("----------------\n");
    printf("count = %d\n",min);
    print(maze);

    return 0;
}

Point pt(int x, int y) {
    Point p = {x, y};
    return p;
}

int visit(int maze[][SIZE], Point start, Point end) {
    print(maze);
    count++;
    printf("count = %d\n",count);
    printf("start = %d,%d,%d\n",start.x,start.y,maze[start.x][start.y]);

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
            printf("min = %d\n", min);
        }
    }
    count--;
    printf("e--count = %d",count);
    printf("   start = %d,%d,%d",start.x,start.y,maze[start.x][start.y]);
    printf("   start & end= %d,%d\n",start.x==end.x,start.y==end.y);
    return maze[end.x][end.y];
}

void print(int maze[][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) switch(maze[i][j]) {
            case 0 : printf("0 "); break;
            case 1 : printf("1 "); break;
            case 2 : printf("2 ");
        }
        printf("\n");
    }
}
