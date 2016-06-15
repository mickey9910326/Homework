#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void DFS(std::vector< std::vector<int> > &maze, int now_x , int now_y ,int &shortest,int step);

int main() {
    int val;
    int width,height;
    std::cin >> height >> width;

    if(height<=0 || width<=0 ) {
        std::cout << "Worng input of the height or width." << std::endl;
        return 0;
    }

    std::vector< std::vector<int> > maze(height, ( std::vector<int>(width)) );

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //std::cout << "(" << i << "," << j << "):";
            std::cin  >> val;
            if(val!=1 && val!=0) {
                std::cout << "Worng input of the grid of the maze." << std::endl;
                return 0;
            }
            maze[i][j]=val;
        }
    }

    int shortest=height*width;
    DFS(maze,0,0,shortest,0);
    if (shortest == height*width )
        std::cout << 0 << std::endl;
    else
        std::cout << shortest << std::endl;

    return 0;
}

void DFS(std::vector< std::vector<int> > &maze, int now_x , int now_y ,int &shortest,int step) {
    static int height = maze.size();
    static int width  = maze[0].size();
    static int min_shortest = height + width - 2;
    static const int cx[]={1,0,-1,0};  //右、下、左、上
    static const int cy[]={0,1,0,-1};

    //std::cout << now_x <<","<< now_y <<endl;
    if( now_x == height-1 && now_y==width-1 && shortest > step)
		shortest = step;
    if(shortest == min_shortest)
        return;
    for(int i=0;i<4;i++){
        int new_x = now_x+cx[i];
        int new_y = now_y+cy[i];
        //std::cout <<"  new:"<< new_x <<","<< new_y << std::endl;
        if(new_y==-1 || new_y==width || new_x==-1 || new_x==height) //邊界問題
       		continue;

        if(maze[new_x][new_y]==2) //牆
			continue;
        if(maze[new_x][new_y]==1) //走過的點
    		continue;

        maze[new_x][new_y]=2;
        DFS(maze,new_x,new_y,shortest,step+1);
        maze[new_x][new_y]=0;
    }
}
