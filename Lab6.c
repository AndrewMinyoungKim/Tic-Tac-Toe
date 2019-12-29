#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void printBoard(int board[], int playerA, int playerB) {
    char state[9] = {'1','2','3','4','5','6','7','8','9'}; // character array that is displayed
    
    for(int count = 0; count < 9; count++) { // loop to replace unoccupied space with occupied space
        if(board[count] == playerA) {
            state[count] = 'A';
        }else if(board[count] == playerB) {
            state[count] = 'B';
        }
        
    }
    
    printf("%c %c %c\n%c %c %c\n%c %c %c\n\n", state[0], state[1], state[2], state[3], state[4], state[5], state[6], state[7], state[8]); // print board
}

int requestValidInput(int board[], int playerA, int playerB) {
    int place; // declare variable of chosen space
    
    while(true) { // get valid input value that is an unoccupied space
        while(true) {
            scanf(" %d", &place);
            if((place < 1) || (place > 9)) {
                printf("Invalid input, please try again.\n");
            }else {
                break;
            }
            
        }
        
        if((board[place-1] != playerA) && (board[place-1] != playerB)) {
            return place-1;
        }else {
            printf("That position has already been played, please try again.\n");
        }
    }
}

int checkForWinner(int board[], int playerA, int playerB) {
    
    for(int count = 0; count < 3; count++) { // check for vertical win
        if((board[0+count] == board[3+count]) && (board[0+count] == board[6+count])) {
            if(board[0+count] == playerA) {
                return playerA;
            }else if(board[0+count] == playerB) {
                return playerB;
            }
        }
    }
    
    for(int count = 0; count < 9; count += 3) { // check for horizontal win
        if((board[0+count] == board[1+count]) && (board[0+count] == board[2+count])) {
            if(board[0+count] == playerA) {
                return playerA;
            }else if(board[0+count] == playerB) {
                return playerB;
            }
        }
    }
    
    if(((board[4] == board[0]) && (board[4] == board[8])) || ((board[4] == board[2]) && (board[4] == board[6]))) { // check for diagonal win
        if(board[4] == playerA) {
            return playerA;
        }else if(board[4] == playerB) {
            return playerB;
        }
    }
    
    return 0;
}

int main(void)
{
    int board[9] = {1,2,3,4,5,6,7,8,9}; // integer board values
    int playerA = 69, playerB = 420; // declare player A and player B integer representative values
    int A, B, winner;
    
    printf("The current state of the Tic-tac-toe Board:\n\n");
    printBoard(board, playerA, playerB);
    
    for(int count = 0; count < 5; count++) {
    // loop through the maximum number of turns in a game, request for valid input, update board, check for winner
        
        if(count < 4) {
            printf("It is Player A's turn.\nPlease enter a valid position to play.\n");
            A = requestValidInput(board, playerA, playerB);
            board[A] = playerA;
            
            winner = checkForWinner(board, playerA, playerB);
            if((winner == playerA) || (winner == playerB)) {
                break;
            }
            
            printf("The current state of the Tic-tac-toe Board:\n\n");
            printBoard(board, playerA, playerB);
            
            printf("It is Player B's turn.\nPlease enter a valid position to play.\n");
            B = requestValidInput(board, playerA, playerB);
            board[B] = playerB;
            
            winner = checkForWinner(board, playerA, playerB);
            if((winner == playerA) || (winner == playerB)) {
                break;
            }
            
            printf("The current state of the Tic-tac-toe Board:\n\n");
            printBoard(board, playerA, playerB);
            
        }else if(count >= 4) {
            printf("It is Player A's turn.\nPlease enter a valid position to play.\n");
            A = requestValidInput(board, playerA, playerB);
            board[A] = playerA;
            
            winner = checkForWinner(board, playerA, playerB);
            if((winner == playerA) || (winner == playerB)) {
                break;
            }
        }
        
        winner = checkForWinner(board, playerA, playerB);
        if((winner == playerA) || (winner == playerB)) {
            break;
        }
        
    }
    
    if(winner == playerA) {
        printf("Player A Wins!\n\n");
    }else if(winner == playerB) {
        printf("Player B Wins!\n\n");
    }else {
        printf("It's a draw!\n\n");
    }
    
    printBoard(board, playerA, playerB);
	return 0;
}