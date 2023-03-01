#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>

void printBoard(board paramBoard);
void boardInitialize(board paramBoard);
void initEasiestPuzzle(board paramBoard);
void initEasyPuzzle(board paramBoard);
bool checkOpenSquare(board paramBoard, uint8_t boxNum, uint8_t indexNum);
void insertIntoBoard(board paramBoard, uint8_t boxNum, uint8_t indexNum, uint8_t insert);
bool hasOpenSquares(board paramBoard);
const int sizeOfBoard = 9;
const int sizeOfBox = 9;

int main() {
    //Board index Outline
    //
    //  0 1 2 | 0 1 2 | 0 1 2
    //  3 4 5 | 3 4 5 | 3 4 5
    //  6 7 8 | 6 7 8 | 6 7 8
    //  ---------------------
    //  0 1 2 | 0 1 2 | 0 1 2
    //  3 4 5 | 3 4 5 | 3 4 5
    //  6 7 8 | 6 7 8 | 6 7 8
    //  ---------------------
    //  0 1 2 | 0 1 2 | 0 1 2
    //  3 4 5 | 3 4 5 | 3 4 5
    //  6 7 8 | 6 7 8 | 6 7 8
    //
    board mainBoard;
    boardInitialize(mainBoard);

    //Easy Puzzle
    printf("Easy Solve\n");
    initEasiestPuzzle(mainBoard);


    printBoard(mainBoard);
    printf("\nSolved Puzzle: \n");

    //Solve It
    int numOfIterations = 0;
    while(hasOpenSquares(mainBoard) && numOfIterations < 1000) {
        for(int i = 0; i < sizeOfBoard; i++) {
            for(int j = 0; j < sizeOfBoard; j++) {
                checkOpenSquare(mainBoard, i, j);
            }
        }
        numOfIterations++;
    }
    
    printBoard(mainBoard);

    board easyBoard;
    boardInitialize(easyBoard);
    //Medium Puzzle
    printf("\n\nMedium Puzzle\n");
    initEasyPuzzle(easyBoard);
    printBoard(easyBoard);

    //Solve It
    int numOfIterations1 = 0;
    while(hasOpenSquares(easyBoard) && numOfIterations1 < 1000) {
        for(int i = 0; i < sizeOfBoard; i++) {
            for(int j = 0; j < sizeOfBoard; j++) {
                checkOpenSquare(easyBoard, i, j);
            }
        }
        numOfIterations1++;
    }
    printf("\nSolved Puzzle: \n");
    printBoard(easyBoard);
}
    //Check if the board still has open squares
    bool hasOpenSquares(board paramBoard) {
    for(int i = 0; i < sizeOfBoard; i++) {
        for(int j = 0; j < sizeOfBox; j++) {
            if(paramBoard[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}
    
    //Init the board with a simple puzzle
    void initEasiestPuzzle(board paramBoard) {
    paramBoard[0][1] = 2;
    paramBoard[0][3] = 4;
    paramBoard[0][4] = 5;
    paramBoard[0][5] = 7;
    paramBoard[0][6] = 6;
    paramBoard[0][7] = 8;
    paramBoard[0][8] = 9;

    paramBoard[1][0] = 4;
    paramBoard[1][1] = 5;
    paramBoard[1][2] = 6;
    paramBoard[1][4] = 8;
    paramBoard[1][6] = 2;
    paramBoard[1][7] = 3;
    paramBoard[1][8] = 7;

    paramBoard[2][0] = 7;
    paramBoard[2][1] = 8;
    paramBoard[2][2] = 9;
    paramBoard[2][3] = 2;
    paramBoard[2][4] = 3;
    paramBoard[2][5] = 6;
    paramBoard[2][7] = 4;

    paramBoard[3][2] = 5;
    paramBoard[3][3] = 2;
    paramBoard[3][4] = 7;
    paramBoard[3][5] = 4;
    paramBoard[3][6] = 3;
    paramBoard[3][7] = 9;
    paramBoard[3][8] = 6;

    paramBoard[4][0] = 3;
    paramBoard[4][1] = 6;
    paramBoard[4][2] = 2;
    paramBoard[4][4] = 9;
    paramBoard[4][6] = 5;
    paramBoard[4][7] = 7;
    paramBoard[4][8] = 4;

    paramBoard[5][0] = 9;
    paramBoard[5][1] = 7;
    paramBoard[5][2] = 4;
    paramBoard[5][3] = 6;
    paramBoard[5][4] = 5;
    paramBoard[5][5] = 3;
    paramBoard[5][6] = 8;

    paramBoard[6][1] = 4;
    paramBoard[6][3] = 7;
    paramBoard[6][4] = 6;
    paramBoard[6][5] = 1;
    paramBoard[6][6] = 9;
    paramBoard[6][7] = 3;
    paramBoard[6][8] = 8;

    paramBoard[7][0] = 6;
    paramBoard[7][1] = 1;
    paramBoard[7][2] = 8;
    paramBoard[7][4] = 4;
    paramBoard[7][6] = 7;
    paramBoard[7][7] = 2;
    paramBoard[7][8] = 5;

    paramBoard[8][0] = 3;
    paramBoard[8][1] = 9;
    paramBoard[8][2] = 7;
    paramBoard[8][3] = 5;
    paramBoard[8][4] = 2;
    paramBoard[8][5] = 8;
    paramBoard[8][7] = 6;

}
    
    //Init the board with a easy puzzle
    void initEasyPuzzle(board paramBoard) {
        paramBoard[0][3] = 6;
        paramBoard[0][4] = 8;
        paramBoard[0][6] = 1;
        paramBoard[0][7] = 9;
        paramBoard[1][0] = 2;
        paramBoard[1][1] = 6;
        paramBoard[1][4] = 7;
        paramBoard[1][8] = 4;
        paramBoard[2][0] = 7;
        paramBoard[2][2] = 1;
        paramBoard[2][4] = 9;
        paramBoard[2][6] = 5;
        paramBoard[3][0] = 8;
        paramBoard[3][1] = 2;
        paramBoard[3][5] = 4;
        paramBoard[3][7] = 5;

        paramBoard[4][0] = 1;
        paramBoard[4][3] = 6;
        paramBoard[4][5] = 2;
        paramBoard[4][8] = 3;

        paramBoard[5][1] = 4;
        paramBoard[5][3] = 9;
        paramBoard[5][7] = 2;
        paramBoard[5][8] = 8;

        paramBoard[6][2] = 9;
        paramBoard[6][4] = 4;
        paramBoard[6][6] = 7;
        paramBoard[6][8] = 3;

        paramBoard[7][0] = 3;
        paramBoard[7][4] = 5;
        paramBoard[7][7] = 1;
        paramBoard[7][8] = 8;
        
        paramBoard[8][1] = 7;
        paramBoard[8][2] = 4;
        paramBoard[8][4] = 3;
        paramBoard[8][5] = 6;

    }

    //Initialize the board with all zeros
    void boardInitialize(board paramBoard) {
        for (int i = 0; i < sizeOfBoard; i++) {
            for (int j = 0; j < sizeOfBox; j++) {
               paramBoard[i][j] = 0;
            }
       }
    }
    
    //Print the board in easy to read format
    void printBoard(board paramBoard){
        //print top 3 boxes
        printf("%d %d %d | %d %d %d | %d %d %d\n%d %d %d | %d %d %d | %d %d %d\n%d %d %d | %d %d %d | %d %d %d\n", 
        paramBoard[0][0], paramBoard[0][1], paramBoard[0][2], paramBoard[1][0], paramBoard[1][1], paramBoard[1][2], paramBoard[2][0], paramBoard[2][1], paramBoard[2][2],
        paramBoard[0][3], paramBoard[0][4], paramBoard[0][5], paramBoard[1][3], paramBoard[1][4], paramBoard[1][5], paramBoard[2][3], paramBoard[2][4], paramBoard[2][5],
        paramBoard[0][6], paramBoard[0][7], paramBoard[0][8], paramBoard[1][6], paramBoard[1][7], paramBoard[1][8], paramBoard[2][6], paramBoard[2][7], paramBoard[2][8]
        );
        //print middle 3 boxes
        printf("---------------------\n");
        printf("%d %d %d | %d %d %d | %d %d %d\n%d %d %d | %d %d %d | %d %d %d\n%d %d %d | %d %d %d | %d %d %d\n", 
        paramBoard[3][0], paramBoard[3][1], paramBoard[3][2], paramBoard[4][0], paramBoard[4][1], paramBoard[4][2], paramBoard[5][0], paramBoard[5][1], paramBoard[5][2],
        paramBoard[3][3], paramBoard[3][4], paramBoard[3][5], paramBoard[4][3], paramBoard[4][4], paramBoard[4][5], paramBoard[5][3], paramBoard[5][4], paramBoard[5][5],
        paramBoard[3][6], paramBoard[3][7], paramBoard[3][8], paramBoard[4][6], paramBoard[4][7], paramBoard[4][8], paramBoard[5][6], paramBoard[5][7], paramBoard[5][8]
        );
        //print bottom 3 boxes
        printf("---------------------\n");
        printf("%d %d %d | %d %d %d | %d %d %d\n%d %d %d | %d %d %d | %d %d %d\n%d %d %d | %d %d %d | %d %d %d\n", 
        paramBoard[6][0], paramBoard[6][1], paramBoard[6][2], paramBoard[7][0], paramBoard[7][1], paramBoard[7][2], paramBoard[8][0], paramBoard[8][1], paramBoard[8][2],
        paramBoard[6][3], paramBoard[6][4], paramBoard[6][5], paramBoard[7][3], paramBoard[7][4], paramBoard[7][5], paramBoard[8][3], paramBoard[8][4], paramBoard[8][5],
        paramBoard[6][6], paramBoard[6][7], paramBoard[6][8], paramBoard[7][6], paramBoard[7][7], paramBoard[7][8], paramBoard[8][6], paramBoard[8][7], paramBoard[8][8]
        );
    }
    
    //check if number exists in column
    int * checkColumn(board paramBoard, int boxNum, int indexNum){
        int *retu = malloc(sizeof(int) * 9);
        retu[0] = 0;
        retu[1] = 0;
        retu[2] = 0;
        retu[3] = 0;
        retu[4] = 0;
        retu[5] = 0;
        retu[6] = 0;
        retu[7] = 0;
        retu[8] = 0;
        //Get Column Number
        int colNum;
        if((boxNum == 0) || boxNum == 3 || (boxNum == 6)) {
            if(((indexNum == 0) || (indexNum == 3)) || (indexNum == 6)) {
                colNum = 0;
            }
            if(((indexNum == 1) || (indexNum == 4)) || (indexNum == 7)) {
                colNum = 1;
            }
            if(((indexNum == 2) || (indexNum == 5)) || (indexNum == 8)) {
                colNum = 2;
            }
        }
        if((boxNum == 1) || boxNum == 4 || (boxNum == 7)) {
            if(((indexNum == 0) || (indexNum == 3)) || (indexNum == 6)) {
                colNum = 3;
            }
            if(((indexNum == 1) || (indexNum == 4)) || (indexNum == 7)) {
                colNum = 4;
            }
            if(((indexNum == 2) || (indexNum == 5)) || (indexNum == 8)) {
                colNum = 5;
            }
        }
        if((boxNum == 2) || boxNum == 5 || (boxNum == 8)) {
            if(((indexNum == 0) || (indexNum == 3)) || (indexNum == 6)) {
                colNum = 6;
            }
            if(((indexNum == 1) || (indexNum == 4)) || (indexNum == 7)) {
                colNum = 7;
            }
            if(((indexNum == 2) || (indexNum == 5)) || (indexNum == 8)) {
                colNum = 8;
            }
        }
        if(colNum == 0) {
            retu[0] = paramBoard[0][0];
            retu[1] = paramBoard[0][3];
            retu[2] = paramBoard[0][6];
            retu[3] = paramBoard[3][0];
            retu[4] = paramBoard[3][3];
            retu[5] = paramBoard[3][6];
            retu[6] = paramBoard[6][0];
            retu[7] = paramBoard[6][3];
            retu[8] = paramBoard[6][6];
        }
        if(colNum == 1) {
            retu[0] = paramBoard[0][1];
            retu[1] = paramBoard[0][4];
            retu[2] = paramBoard[0][7];
            retu[3] = paramBoard[3][1];
            retu[4] = paramBoard[3][4];
            retu[5] = paramBoard[3][7];
            retu[6] = paramBoard[6][1];
            retu[7] = paramBoard[6][4];
            retu[8] = paramBoard[6][7];
        }
        if(colNum == 2) {
            retu[0] = paramBoard[0][2];
            retu[1] = paramBoard[0][5];
            retu[2] = paramBoard[0][8];
            retu[3] = paramBoard[3][2];
            retu[4] = paramBoard[3][5];
            retu[5] = paramBoard[3][8];
            retu[6] = paramBoard[6][2];
            retu[7] = paramBoard[6][5];
            retu[8] = paramBoard[6][8];
        }       
        if(colNum == 3) {
            retu[0] = paramBoard[1][0];
            retu[1] = paramBoard[1][3];
            retu[2] = paramBoard[1][6];
            retu[3] = paramBoard[4][0];
            retu[4] = paramBoard[4][3];
            retu[5] = paramBoard[4][6];
            retu[6] = paramBoard[7][0];
            retu[7] = paramBoard[7][3];
            retu[8] = paramBoard[7][6];
        }
        if(colNum == 4) {
            retu[0] = paramBoard[1][1];
            retu[1] = paramBoard[1][4];
            retu[2] = paramBoard[1][7];
            retu[3] = paramBoard[4][1];
            retu[4] = paramBoard[4][4];
            retu[5] = paramBoard[4][7];
            retu[6] = paramBoard[7][1];
            retu[7] = paramBoard[7][4];
            retu[8] = paramBoard[7][7];
        }
        if(colNum == 5) {
            retu[0] = paramBoard[1][2];
            retu[1] = paramBoard[1][5];
            retu[2] = paramBoard[1][8];
            retu[3] = paramBoard[4][2];
            retu[4] = paramBoard[4][5];
            retu[5] = paramBoard[4][8];
            retu[6] = paramBoard[7][2];
            retu[7] = paramBoard[7][5];
            retu[8] = paramBoard[7][8];
        }
        if(colNum == 6) {
            retu[0] = paramBoard[2][0];
            retu[1] = paramBoard[2][3];
            retu[2] = paramBoard[2][6];
            retu[3] = paramBoard[5][0];
            retu[4] = paramBoard[5][3];
            retu[5] = paramBoard[5][6];
            retu[6] = paramBoard[8][0];
            retu[7] = paramBoard[8][3];
            retu[8] = paramBoard[8][6];
        }
        if(colNum == 7) {
            retu[0] = paramBoard[2][1];
            retu[1] = paramBoard[2][4];
            retu[2] = paramBoard[2][7];
            retu[3] = paramBoard[5][1];
            retu[4] = paramBoard[5][4];
            retu[5] = paramBoard[5][7];
            retu[6] = paramBoard[8][1];
            retu[7] = paramBoard[8][4];
            retu[8] = paramBoard[8][7];
        }
        if(colNum == 8) {
            retu[0] = paramBoard[2][2];
            retu[1] = paramBoard[2][5];
            retu[2] = paramBoard[2][8];
            retu[3] = paramBoard[5][2];
            retu[4] = paramBoard[5][5];
            retu[5] = paramBoard[5][8];
            retu[6] = paramBoard[8][2];
            retu[7] = paramBoard[8][5];
            retu[8] = paramBoard[8][8];
        }
        return retu;
    }
    
    //Get Box list of possible numbers
    int * returnBox(board paramBoard, int boxNum){
        int *ret = malloc(sizeof(int) * 9);
        ret[0] = 0;
        ret[1] = 0;
        ret[2] = 0;
        ret[3] = 0;
        ret[4] = 0;
        ret[5] = 0;
        ret[6] = 0;
        ret[7] = 0;
        ret[8] = 0;
        for(int i = 0; i < 9; i++) {
            ret[i] = paramBoard[boxNum][i];
        }      
        return ret;
    }
    
    //check if number exists in row
    int * checkRow(board paramBoard, uint8_t boxNum, uint8_t indexNum){
        int *ret = malloc(sizeof(int) * 9);
        ret[0] = 0;
        ret[1] = 0;
        ret[2] = 0;
        ret[3] = 0;
        ret[4] = 0;
        ret[5] = 0;
        ret[6] = 0;
        ret[7] = 0;
        ret[8] = 0;
        //find row  number
        int rowNum = 0;
        if((boxNum ==0) || (boxNum == 1) || (boxNum == 2)) {
            if((indexNum == 0) || (indexNum == 1) || (indexNum == 2)) {
                rowNum = 0;
            }
            if((indexNum == 3) || (indexNum == 4) || (indexNum == 5)) {
                rowNum = 1;
            }
            if((indexNum == 6) || (indexNum == 7) || (indexNum == 8)) {
                rowNum = 2;
            }
        }
        if((boxNum == 3 ) || (boxNum == 4) || (boxNum == 5)) {
            if((indexNum == 0) || (indexNum == 1) || (indexNum == 2)) {
                rowNum = 3;
            }
            if((indexNum == 3) || (indexNum == 4) || (indexNum == 5)) {
                rowNum = 4;
            }
            if((indexNum == 6) || (indexNum == 7) || (indexNum == 8)) {
                rowNum = 5;
            }
        }
        if((boxNum == 6 ) || (boxNum == 7) || (boxNum == 8)) {
            if((indexNum == 0) || (indexNum == 1) || (indexNum == 2)) {
                rowNum = 6;
            }
            if((indexNum == 3) || (indexNum == 4) || (indexNum == 5)) {
                rowNum = 7;
            }
            if((indexNum == 6) || (indexNum == 7) || (indexNum == 8)) {
                rowNum = 8;
            }
        }
        if(rowNum == 0) {
            ret[0] = paramBoard[0][0];
            ret[1] = paramBoard[0][1];
            ret[2] = paramBoard[0][2];
            ret[3] = paramBoard[1][0];
            ret[4] = paramBoard[1][1];
            ret[5] = paramBoard[1][2];
            ret[6] = paramBoard[2][0];
            ret[7] = paramBoard[2][1];
            ret[8] = paramBoard[2][2];
        }
        if(rowNum == 1) {
            ret[0] = paramBoard[0][3];
            ret[1] = paramBoard[0][4];
            ret[2] = paramBoard[0][5];
            ret[3] = paramBoard[1][3];
            ret[4] = paramBoard[1][4];
            ret[5] = paramBoard[1][5];
            ret[6] = paramBoard[2][3];
            ret[7] = paramBoard[2][4];
            ret[8] = paramBoard[2][5];
        }
        if(rowNum == 2) {
            ret[0] = paramBoard[0][6];
            ret[1] = paramBoard[0][7];
            ret[2] = paramBoard[0][8];
            ret[3] = paramBoard[1][6];
            ret[4] = paramBoard[1][7];
            ret[5] = paramBoard[1][8];
            ret[6] = paramBoard[2][6];
            ret[7] = paramBoard[2][7];
            ret[8] = paramBoard[2][8];
        }
        if(rowNum == 3) {
            ret[0] = paramBoard[3][0];
            ret[1] = paramBoard[3][1];
            ret[2] = paramBoard[3][2];
            ret[3] = paramBoard[4][0];
            ret[4] = paramBoard[4][1];
            ret[5] = paramBoard[4][2];
            ret[6] = paramBoard[5][0];
            ret[7] = paramBoard[5][1];
            ret[8] = paramBoard[5][2];
        }
        if(rowNum == 4) {
            ret[0] = paramBoard[3][3];
            ret[1] = paramBoard[3][4];
            ret[2] = paramBoard[3][5];
            ret[3] = paramBoard[4][3];
            ret[4] = paramBoard[4][4];
            ret[5] = paramBoard[4][5];
            ret[6] = paramBoard[5][3];
            ret[7] = paramBoard[5][4];
            ret[8] = paramBoard[5][5];
            
        }
        if(rowNum == 5) {
            ret[0] = paramBoard[3][6];
            ret[1] = paramBoard[3][7];
            ret[2] = paramBoard[3][8];
            ret[3] = paramBoard[4][6];
            ret[4] = paramBoard[4][7];
            ret[5] = paramBoard[4][8];
            ret[6] = paramBoard[5][6];
            ret[7] = paramBoard[5][7];
            ret[8] = paramBoard[5][8];
        }
        if(rowNum == 6) {
            ret[0] = paramBoard[6][0];
            ret[1] = paramBoard[6][1];
            ret[2] = paramBoard[6][2];
            ret[3] = paramBoard[7][0];
            ret[4] = paramBoard[7][1];
            ret[5] = paramBoard[7][2];
            ret[6] = paramBoard[8][0];
            ret[7] = paramBoard[8][1];
            ret[8] = paramBoard[8][2];
        }
        if(rowNum == 7) {
            ret[0] = paramBoard[6][3];
            ret[1] = paramBoard[6][4];
            ret[2] = paramBoard[6][5];
            ret[3] = paramBoard[7][3];
            ret[4] = paramBoard[7][4];
            ret[5] = paramBoard[7][5];
            ret[6] = paramBoard[8][3];
            ret[7] = paramBoard[8][4];
            ret[8] = paramBoard[8][5];
        }
        if(rowNum == 8) {
            ret[0] = paramBoard[6][6];
            ret[1] = paramBoard[6][7];
            ret[2] = paramBoard[6][8];
            ret[3] = paramBoard[7][6];
            ret[4] = paramBoard[7][7];
            ret[5] = paramBoard[7][8];
            ret[6] = paramBoard[8][6];
            ret[7] = paramBoard[8][7];
            ret[8] = paramBoard[8][8];
        }
        return ret;
    }

    //check if the only possible number
    bool checkOpenSquare(board paramBoard, uint8_t boxNum, uint8_t indexNum){
        //get box list of possible numbers
        int *box = returnBox(paramBoard, boxNum);
        //check column
        int *column = checkColumn(paramBoard, boxNum, indexNum);
        //check row
        int *row = checkRow(paramBoard, boxNum, indexNum);

        //compare all possible values and see if one remains
        int possible[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int i = 0; i < sizeOfBox; i++) {
            for(int j = 0; j < sizeOfBox; j++) {
                if(possible[i] == box[j]){
                    possible[i] = 0;
                }
            } 
            for(int j = 0; j < sizeOfBox; j++) {
                if(possible[i] == column[j]){
                    possible[i] = 0;
                }
            }
            for(int j = 0; j < sizeOfBox; j++) {
                if(possible[i] == row[j]){
                    possible[i] = 0;
                }
            }
        }

        int numOfPossible = 0;
        int onlyPossibleNumber = 0;
        for(int i = 0; i < 9; i++) {
            if(possible[i] != 0) {
                numOfPossible++;
                onlyPossibleNumber = possible[i];
            }
        }
        if((numOfPossible == 1) && (onlyPossibleNumber != 0)) {
            insertIntoBoard(paramBoard, boxNum, indexNum, onlyPossibleNumber);
        }

        free(row);
        free(column);
        free(box);
        if (true) {
            return true;
        } else {
            return false;
        }
    }

    //insert number into board
    void insertIntoBoard(board paramBoard, uint8_t boxNum, uint8_t indexNum, uint8_t insert){
        if(paramBoard[boxNum][indexNum] == 0) {
            paramBoard[boxNum][indexNum] = insert;
        }
    };

    //check if square empty
    bool isEmpty(board paramBoard, uint8_t BoxNum, uint8_t indexNum){
        if(paramBoard[BoxNum][indexNum] == 0) {
            return true;
        } else {
            return false;
        }
    }

    //Check every square on board (Main solving function)
    void boardChecker(board paramBoard){
        int s[9] = {1, 2, 3, 4, 5, 6, 7, 8 ,9};
        for(int i = 0; i < sizeOfBoard; i++) { //iterate through each box
            for(int j = 0; j < sizeOfBox; j++) { //iterate through square in each box
                //check if empty
                if(isEmpty(paramBoard, i, j)) {
                    continue;
                } 
                else { //if not empty
                    //check for possible numbers
                    if(checkOpenSquare(paramBoard, i, j)) {
                        //if only possible number
                        insertIntoBoard(paramBoard, i, j, 0);
                    } else { 
                        //if not only possible number
                        continue;
                    }
                }   
            };
        };
        printf("\n");
        printBoard(paramBoard);
    }

