#include <stdio.h>
#include <math.h>

int main (void){
    int sorted_arr [7];
    int searched;

    binary_search(sorted_arr, 7, searched);
}

int binary_search (int arr [], int size, int searched){
    int low = 0;
    int high = size - 1;
    int mid;
    int found = 0;
    while (low <= high && !found){
        mid = (low + high) / 2;

        // If we found the number
        if (arr[mid] == searched){
            found = 1;
        }
        // If the number is too low
        else if (arr[mid] < searched){
            low = mid + 1;
        }
        // If the number is too high
        else {
            high = mid - 1;
        }
    }

    // If the number was found
    if (found){
        return mid;
    }
    // If the number was not found
    else {
        return -1;
    }
}