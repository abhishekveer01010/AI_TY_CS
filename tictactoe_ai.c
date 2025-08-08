#include<stdio.h>
#include<stdlib.h>

char playerX = 'X';
char playerO = 'O';

void printBoard(char board[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
        {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}
int main(){
    char board[3][3] = {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}
    };
    
    printf("You are O and AI is X \n");

    printBoard(board);
    return 0;
}
