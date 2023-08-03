#include <stdio.h>
#include <math.h>

int main (void){
    int arr [7];
    int sorted_arr [7];
    int searched = 0;

    // Find the highest number
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        if (arr[i] > searched){
            searched = arr[i];
        };
    }
    


}