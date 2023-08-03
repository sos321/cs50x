int main (void){
    int arr [5];
    int searched;

    linear_search(arr, 5, searched);
}

int linear_search (int arr [], int size, int searched){
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        if (arr[i] == searched){
            return i;
        }
    }

    return -1;
}