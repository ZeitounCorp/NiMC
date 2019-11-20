//
// Created by lenny zeitoun on 15/11/2019.
//

#ifndef STICK_NIM_H
#define STICK_NIM_H


/* a = 3 ; b = 1 c = 2*/
 /*
  * 1er if => a = 1; b = 3; c = 2 ( x = a; y = b )
  * 2eme if => a = 1; b = 2; c = 3 ( x = b; y = c )
  * 3eme if => a = 3; b = 2; c = 1 ( x = c; y = a )
  */

void swap(int* x, int* y) {
    int temp = *x; /* tmp = 3 */
    *x = *y; /* c = 1 */
    *y = temp; /* a = 3 */
}

void reorganizeCols(int* c1 /* 7 */, int* c2 /* 3 */, int* c3 /* 21 */) {
    if (*c1 > *c2) {
        swap(c1, c2);
    }
    if (*c1 > *c3) {
        swap(c3, c1);
    }
    if (*c2 > *c3) {
        swap(c2, c3);
    }
}

void computerTurn( int* z /* 8 */, int xor /* 3 */, int* x, int* y) {

    int chosenCol, wantToTakeDownToC;

    chosenCol = *z;

    wantToTakeDownToC = chosenCol ^ xor;

    printf("I turned %d to %d\n", chosenCol, wantToTakeDownToC);
    *z = wantToTakeDownToC;

    if(wantToTakeDownToC == 0 && *x == 0 && *y == 0) {
        printf("Game Over - You Lost !!");
    } else {
        printf("Packet sizes are: %d %d %d\n", *x, *y, *z);
    }

}

void playerTurn(int wantToTakeDownToP, int chosenCol, int *c1 /* 7 */, int *c2 /* 3 */, int *c3 /* 21 */ ) {
    if(wantToTakeDownToP <= chosenCol && ( chosenCol == *c1 || chosenCol == *c2 || chosenCol == *c3)) {
        if(chosenCol == *c1) {
            *c1 = wantToTakeDownToP;
        } else if(chosenCol == *c2) {
            *c2 = wantToTakeDownToP;
        } else if(chosenCol == *c3) {
            *c3 = wantToTakeDownToP;
        }
        reorganizeCols(c1, c2, c3);
    } else {
        if(wantToTakeDownToP > chosenCol) {
            printf("You can't add more sticks than the ones present in the column ! \n");
        } else {
            printf("This column doesn't seem to exist ! \n");
        }
    }
}

#endif //STICK_NIM_H
