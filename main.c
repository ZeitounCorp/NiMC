#include <stdio.h>
#include "nim.h"

int c1, c2, c3;
char tmpTO[5];
int xorValue;

int main() {
    int wantToTakeDownToC;
    int wantToTakeDownToP;
    int chosenCol;

    printf("Please enter 3 numbers: ");
    scanf("%d %d %d", &c1, &c2, &c3);

    while (c1 < 0 || c2 < 0 || c3 < 0) {
        printf("Please enter 3 numbers: ");
        scanf("%d %d %d", &c1, &c2, &c3);
    }

    reorganizeCols(&c1, &c2, &c3);

    printf("Packet sizes are: %d %d %d\n", c1, c2, c3);


    while(c1 != 0 || c2 != 0 || c3 != 0 ) {
        xorValue = c1^c2^c3;

        if( xorValue != 0 ) {
            computerTurn(&c3, xorValue, &c1, &c2);
        } else {
            printf("Your Turn! Please state how much to take ? \n");
            scanf("%d %s %d", &chosenCol, tmpTO, &wantToTakeDownToP);
            playerTurn(wantToTakeDownToP, chosenCol, &c1, &c2, &c3);
            reorganizeCols(&c1, &c2, &c3);
            xorValue = c1^c2^c3;
            if( xorValue != 0 ) {
                computerTurn(&c3, xorValue, &c1, &c2);
            }
        }
    }

    return 0;
}



