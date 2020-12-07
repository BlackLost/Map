#include <iostream>
#include <vector>
#include<stdlib.h>
#include <time.h>
#define WALL 0
#define ROUTE 1
using namespace std;

static const int N = 20;

void dig(vector<vector<int>> &maze, int x, int y)
{
    if (maze[x][y] == WALL)
    {
        if (maze[x + 1][y] + maze[x - 1][y] + maze[x][y + 1] + maze[x][y - 1] <= ROUTE)
        {
            maze[x][y] = ROUTE;
            /*if(x+2==N-1&&y+2==N-1)
            {
                maze[x+1][y]=ROUTE;
                return;
            }*/
            int direction[4] = {0, 1, 2, 3};
            for (int i = 4; i > 0; --i)
            {
                int r = rand() % i;
                swap(direction[r], direction[i - 1]);

                switch (direction[i - 1])
                {
                case 0:
                    dig(maze, x - 1, y);
                    break;
                case 1:
                    dig(maze, x + 1, y);
                    break;
                case 2:
                    dig(maze, x, y - 1);
                    break;
                case 3:
                    dig(maze, x, y + 1);
                    break;
                default:
                    break;
                }
            }
        }
    }
}
void printMaze(vector<vector<int>> &maze)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (maze[i][j] == ROUTE)
            {
                cout << "  ";
            }
            else
            {
                cout << "¹ú";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
    vector<vector<int>> maze(N, vector<int>(N, WALL));
    for (int i = 0; i < N; ++i)
    {
        maze[i][N - 1] = ROUTE;
        maze[N - 1][i] = ROUTE;
        maze[i][0] = ROUTE;
        maze[0][i] = ROUTE;
    }
    dig(maze, 2, 1);
    printMaze(maze);
    
    int tmp;
    cin >> tmp;
    return 0;
}
