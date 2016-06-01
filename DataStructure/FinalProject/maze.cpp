#include <iostream>
#define Length 4
#define Width 4

class Point {
private:
    int _x;
    int _y;
public:
    Point(){
        _x = 0;
        _y = 0;
    };
    Point (int x,int y){
        _x = x;
        _y = y;
    };
    int x() { return _x; };
    int y() { return _y; };
    // virtual ~Point ();
};


class Maze {
public:
    int graph[ Length ][ Width ];
    Point start;
    Point end;
public:
    Maze(){};
    Maze(int g[4][4],Point s,Point e){
        int i,j;
        for(i = 0; i < Length ; i++) {
            for(j = 0; j < Width ; j++)
                graph[i][j] = g[i][j];
        }
        start = s;
        end   = e;
    }
    void catch_graph(int g[4][4]) {
        int i,j;
        for(i = 0; i < Length ; i++) {
            for(j = 0; j < Width ; j++)
                graph[i][j] = g[i][j];
        }
    };
    void catch_point(Point s) {
        start = s;
    }
    // maze (int* mg,Point* s,Point* e) {};
    // virtual ~maze ();
    void print(){
        int i, j;
        for(i = 0; i < Length ; i++) {
            for(j = 0; j < Width ; j++)
                std::cout << graph[i][j];
            std::cout << std::endl;
        }
    };
    int visit(Point s,Point e){
        if(!graph[start.x][start.y]) {
        maze[start.x][start.y] = 1;
        if(!maze[end.x][end.y] &&
            !(visit(maze, pt(start.x, start.y + 1), end) ||
              visit(maze, pt(start.x + 1, start.y), end) ||
              visit(maze, pt(start.x, start.y - 1), end) ||
              visit(maze, pt(start.x - 1, start.y), end))) {
             maze[start.x][start.y] = 0;
            }
        }
    };

};
void p_point(Point p) {
    std::cout << p.x() << "," << p.y() << std::endl;
}
int main(int argc, char const *argv[]) {
    int maze_graph[ Length ][ Width ] = {
        {0,0,0,1},
        {1,0,0,1},
        {1,0,1,0},
        {1,0,0,0}
    };
    p_point(Point(1,2));
    Maze mymaze(maze_graph,Point(0,0),Point(4,4));

    mymaze.print();

    std::cout << mymaze.start.x() << std::endl;
    std::cout << mymaze.start.y() << std::endl;
    std::cout << mymaze.end.x() << std::endl;
    std::cout << mymaze.end.y() << std::endl;
    return 0;
}
