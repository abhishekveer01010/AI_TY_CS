#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void main(){
    char ch;
    printf("\n Ready...!!! (y/n)");
    scanf(" %c ",&ch);
    while(ch != 'n'){
        int userMove;
        srand(time(0));
        int computerMove = (rand() % 3) + 1;

        printf("Enter Your Move ( Stone -> 1 || Paper -> 2 || Scissors -> 3) : ");
        scanf("%d", &userMove);
        if (userMove > 3 || userMove < 1){
            printf(" \nInvalid Move !!! ");
            // return 0;
        }

        printf("\nUser Move : %d", userMove);
        printf("\nComputer Move : %d", computerMove);

        if (userMove == 1 && computerMove == 2){
            printf("\nComputer Wins...!!!");
            printf("\nBetter luck next time !!!");
        }else if (userMove == 1 && computerMove == 3){
            printf("\nYeah, You Win !!");
        }else if (userMove == 2 && computerMove == 3){
            printf("\nComputer Wins...!!!");
            printf("\nBetter luck next time !!!");
        }else if (userMove == 2 && computerMove == 1){
            printf("\nYeah, You Win !!");
        }else if (userMove == 3 && computerMove == 1){
            printf("\nComputer Wins...!!!");
            printf("\nBetter luck next time !!!");
        }else if (userMove == 3 && computerMove == 2){
            printf("\nYeah, You Win !!");
        }else{
            printf(" Match Draws !!!");
        }   
    }
    // return 0;
}