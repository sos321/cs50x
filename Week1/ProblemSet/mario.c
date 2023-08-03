#include <stdio.h>

int main (void) {
    int value = 8;

    int i, j;
    for (i = 1, j = value - 1; i < value + 1; i++, j--){       

        for (int k = j; k > 0; k--){
            printf(" ");
        }

        for (int l = i; l > 0; l--){
            printf("#");
        }

        printf(" ");
        printf(" ");

        for (int m = i; m > 0; m--){
            printf("#");
        }
        
        printf("\n");
    }

    return 0;
}