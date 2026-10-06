#include<iostream>
using namespace std;
const int N = 4;
int boardz[N][N];
int maxflags = 0;

bool safe(int board[N][N], int row, int col){
    for(int i = 0; i < row; i++){
        if(board[i][col] == 1){return false;}
    }
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 1){return false;}
    }
    for(int i = row, j = col; i >= 0 && j < N; i--, j++){
        if(board[i][j] == 1){return false;}
    }

    return true;
}

void solve(int board[N][N], int row, int flags){
    if(row == N){
        if(flags > maxflags){
            maxflags = flags;

            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    boardz[i][j] = board[i][j];
                }
            }
        }
        return;
    }

    for(int col = 0; col < N; col++){
        if (safe(board, row, col)){
            board[row][col] = 1;
            solve(board, row+1, flags+1);
            board[row][col];
        }
    }

    solve(board, row+1, flags);
}

int main(){
    int board[N][N] = {0};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            boardz[i][j] = 0;
        }
    }

    solve(board, 0, 0);

    cout << "Best placement of flags is: " << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(boardz[i][j] == 1){
                cout << "F";
            }
            else{
                cout << ".";
            }
        }
        cout << endl;
    }

    cout << "Maximum number of flags are: " << maxflags << endl;

    return 0;
}