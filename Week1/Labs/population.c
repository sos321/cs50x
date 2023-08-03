#include <stdio.h>

int calculateYearGrowth(int start);

int main (void) {
    int current = 0;
    int end = 0; 
    int years = 0;

    do {
        printf("Enter starting population: ");
        scanf("%i", &current);
    } while (current < 9);
    
    do {
        printf("Enter ending population: ");
        scanf("%i", &end);
    } while (end < current);

    while (current < end) {
        years ++;

        current = current + calculateYearGrowth(current);
    }

    printf("Years: %i\n", years);
}

int calculateYearGrowth(int start) {
    return start / 3 - start / 4;
}