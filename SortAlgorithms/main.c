#include <stdio.h>

#include "Sort.h"
#include "SortAlg.h"

int main() {
    int arr[7] = {3, 6, 4, 5, 1, 7, 2};
    printArray(arr, 7);
//    insertionSort(arr, 10);
//    selectionSort(arr, 10);
//    quickSort(arr,0,7);
    shellSort(arr,7);
    printArray(arr, 7);

    return 0;
}
