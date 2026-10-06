#include<iostream>
using namespace std;
# define N 5

bool issafe(int Maze[N][N], int x, int y, int sol[N][N]){
    return(x >= 0 && x < N && y >= 0 && y < N && Maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMaze(int maze[N][N], int x, int y, int sol[N][N]){
    if(x == N-1 && y == N-1 && maze[x][y] == 1){
        sol[x][y] = 1;
        return true;
    }

    if (issafe(maze, x, y, sol)){
        sol[x][y] = 1;
        if (solveMaze(maze, x+1, y, sol)){return true;} // Down
        if(solveMaze(maze, x, y+1, sol)){return true;} // Right
        if(solveMaze(maze, x-1, y, sol)){return true;} // UP
        if(solveMaze(maze, x, y-1, sol)){return true;} // Left
        sol[x][y] = 0;

        return false;
    }
    return false;
}

void solveMaze(int maze[N][N]){
    int sol[N][N] = {0};

    if (!solveMaze(maze, 0, 0, sol)){
        cout << "No path found!" << endl;
        return;
    }

    cout << endl << "Solution Path (Lion's moves):\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int maze[N][N];
    
    cout << "Enter the maze (0 for obstacle, 1 for path):" << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> maze[i][j];
        }
    }
    solveMaze(maze);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}