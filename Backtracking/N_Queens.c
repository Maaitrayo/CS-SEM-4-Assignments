#include<stdio.h>
#include<string.h>

#define N 4

void printArray(int board[N][N]){
    char final_board[N][N];
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(board[i][j] == 1){
                final_board[i][j] = 'Q';
                printf("%c  ", final_board[i][j]);
            }
            else{
                final_board[i][j] = '*';
                printf("%c  ", final_board[i][j]);
            }
        }
        printf("\n");
    }
}

int isValid(int board[N][N], int row, int col){
    int i, j;
    for(i = 0;i<col;i++){
        if(board[row][i]){
            return 0;
        }
    }

    // upper left diagonal
    for(i= row, j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j]){
            return 0;
        }
    }

    // lower left diagonal
    for(i= row, j=col; i<N && j>=0; i++,j--){
        if(board[i][j]){
            return 0;
        }
    }
    return 1;
}

int SolveNQueen(int board[N][N], int col){
    int i;
    if (col >=N)
        return 1;
    
    for(i =0;i<N;i++){
        if(isValid(board, i, col)){
            board[i][col] = 1;

        if(SolveNQueen(board,col+1))
            return 1;
        
        // Backtracking
        board[i][col] = 0;
        }
    }
    return 0;
}

int main(){
    int i,j;

    int board[N][N];
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            board[i][j] = 0;
        }
    }

    int result = SolveNQueen(board, 0);
    if(result == 1){
        printArray(board);
    }
    else
        printf("Solution does not exist");
}