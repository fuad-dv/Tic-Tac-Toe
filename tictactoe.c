#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];

void initializeBoard();
void printBoard();
void playerMove();
void computerMove();

char checkWinner();
int checkFreeSpaces();

int tryWinMove();   
int tryBlockMove();
int tryCenter();    
int tryCorner();    

int main() {

    char winner = ' ';

    srand(time(0));

    initializeBoard();

    printf("=== TIC TAC TOE ===\n");
    printf("You = X\n");
    printf("Computer = O\n");

    while(winner == ' ' && checkFreeSpaces() > 0) {

        printBoard();

        playerMove();

        winner = checkWinner();

        if(winner != ' ' || checkFreeSpaces() == 0) {
            break;
        }

        computerMove();

        winner = checkWinner();
    }

    printBoard();

    
    if(winner == 'X') {
        printf("Congratulations! You win!\n");
    }
    else if(winner == 'O') {
        printf("Computer wins!\n");
    }
    else {
        printf("It's a draw!\n");
    }

    return 0;
}

void initializeBoard() {

    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {

            board[i][j] = ' ';
        }
    }
}

void printBoard() {

    printf("\n");

    for(int i = 0; i < 3; i++) {

        printf(" %c | %c | %c ",
               board[i][0],
               board[i][1],
               board[i][2]);

        if(i < 2) {
            printf("\n---|---|---\n");
        }
    }

    printf("\n\n");
}

void playerMove() {

    int row, col;

    while(1) {

        printf("Enter row (1-3): ");
        scanf("%d", &row);

        printf("Enter column (1-3): ");
        scanf("%d", &col);

        row--;
        col--;

       
        if(row < 0 || row > 2 || col < 0 || col > 2) {

            printf("Invalid position! Try again.\n");
            continue;
        }

        if(board[row][col] != ' ') {

            printf("Cell already occupied! Try again.\n");
            continue;
        }

        board[row][col] = 'X';
        break;
    }
}

void computerMove() {

    int row, col;

    printf("Computer is making a move...\n");

    if(tryWinMove()) {
        return;
    }

    if(tryBlockMove()) {
        return;
    }

    if(tryCenter()) {
        return;
    }

    if(tryCorner()) {
        return;
    }

    do {

        row = rand() % 3;
        col = rand() % 3;

    } while(board[row][col] != ' ');

    board[row][col] = 'O';
}
int tryWinMove() {

    for(int i = 0; i < 3; i++) {

        int oCount = 0;
        int emptyCol = -1;

        for(int j = 0; j < 3; j++) {

            if(board[i][j] == 'O') {
                oCount++;
            }
            else if(board[i][j] == ' ') {
                emptyCol = j;
            }
        }

        if(oCount == 2 && emptyCol != -1) {

            board[i][emptyCol] = 'O';
            return 1;
        }
    }

    for(int j = 0; j < 3; j++) {

        int oCount = 0;
        int emptyRow = -1;

        for(int i = 0; i < 3; i++) {

            if(board[i][j] == 'O') {
                oCount++;
            }
            else if(board[i][j] == ' ') {
                emptyRow = i;
            }
        }

        if(oCount == 2 && emptyRow != -1) {

            board[emptyRow][j] = 'O';
            return 1;
        }
    }

    int oCount = 0;
    int emptyIndex = -1;

    for(int i = 0; i < 3; i++) {

        if(board[i][i] == 'O') {
            oCount++;
        }
        else if(board[i][i] == ' ') {
            emptyIndex = i;
        }
    }

    if(oCount == 2 && emptyIndex != -1) {

        board[emptyIndex][emptyIndex] = 'O';
        return 1;
    }

    oCount = 0;
    int emptyRow = -1;
    int emptyCol = -1;

    for(int i = 0; i < 3; i++) {

        int j = 2 - i;

        if(board[i][j] == 'O') {
            oCount++;
        }
        else if(board[i][j] == ' ') {

            emptyRow = i;
            emptyCol = j;
        }
    }

    if(oCount == 2 && emptyRow != -1) {

        board[emptyRow][emptyCol] = 'O';
        return 1;
    }

    return 0;
}

int tryBlockMove() {
    for(int i = 0; i < 3; i++) {

        int xCount = 0;
        int emptyCol = -1;

        for(int j = 0; j < 3; j++) {

            if(board[i][j] == 'X') {
                xCount++;
            }
            else if(board[i][j] == ' ') {
                emptyCol = j;
            }
        }

        if(xCount == 2 && emptyCol != -1) {

            board[i][emptyCol] = 'O';
            return 1;
        }
    }
    for(int j = 0; j < 3; j++) {

        int xCount = 0;
        int emptyRow = -1;

        for(int i = 0; i < 3; i++) {

            if(board[i][j] == 'X') {
                xCount++;
            }
            else if(board[i][j] == ' ') {
                emptyRow = i;
            }
        }

        if(xCount == 2 && emptyRow != -1) {

            board[emptyRow][j] = 'O';
            return 1;
        }
    }
    int xCount = 0;
    int emptyIndex = -1;

    for(int i = 0; i < 3; i++) {

        if(board[i][i] == 'X') {
            xCount++;
        }
        else if(board[i][i] == ' ') {
            emptyIndex = i;
        }
    }
    if(xCount == 2 && emptyIndex != -1) {

        board[emptyIndex][emptyIndex] = 'O';
        return 1;
    }
    xCount = 0;
    int emptyRow = -1;
    int emptyCol = -1;

    for(int i = 0; i < 3; i++) {

        int j = 2 - i;

        if(board[i][j] == 'X') {
            xCount++;
        }
        else if(board[i][j] == ' ') {

            emptyRow = i;
            emptyCol = j;
        }
    }

    if(xCount == 2 && emptyRow != -1) {

        board[emptyRow][emptyCol] = 'O';
        return 1;
    }

    return 0;
}
int tryCenter() {

    if(board[1][1] == ' ') {

        board[1][1] = 'O';
        return 1;
    }

    return 0;
}
int tryCorner() {

    int corners[4][2] = {{0,0},{0,2},{2,0},{2,2}};

    for(int i = 0; i < 4; i++) {

        int r = corners[i][0];
        int c = corners[i][1];

        if(board[r][c] == ' ') {

            board[r][c] = 'O';
            return 1;
        }
    }

    return 0;
}
char checkWinner() {
    for(int i = 0; i < 3; i++) {

        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2] &&
           board[i][0] != ' ') {

            return board[i][0];
        }
    }
    for(int i = 0; i < 3; i++) {

        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i] &&
           board[0][i] != ' ') {

            return board[0][i];
        }
    }
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2] &&
       board[0][0] != ' ') {

        return board[0][0];
    }
    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0] &&
       board[0][2] != ' ') {

        return board[0][2];
    }

    return ' ';
}

int checkFreeSpaces() {

    int freeSpaces = 0;

    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {

            if(board[i][j] == ' ') {
                freeSpaces++;
            }
        }
    }

    return freeSpaces;
}