/*
 * Simple program to create a heap
 * compile using gcc as,
 *      gcc main.c heapify.c
 *
 * TODO: buildMinHeap
 */

#include "heapify.h"

int main() {
    int i;
    int n, Arr[MAXSIZE];

    printf("How many numbers do you want to enter into the heap? ");
    scanf("%d", &n);

    printf("Insert %d integer number(s) to build a heap: ", n);
    for(i = 0 ; i < n ; i++)
        scanf("%d", &Arr[i]);

    /* build a max heap using the array */
    buildMaxHeap(Arr, n);

    /* display max heap */
    printf("Displaying max-heap: ");
    for(i = 0 ; i < n ; i++)
        printf("%d ", Arr[i]);

    printf("\n");

    return 0;
}
