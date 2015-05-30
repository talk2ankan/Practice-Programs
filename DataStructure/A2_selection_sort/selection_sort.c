/*
 * program to perform a selection sort
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXITEMS 100

void display(int a[], int nItems) {
  int i;

  for(i = 0 ; i < nItems ; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");
}

void swap(int* x, int* y) {
  *x = *x+*y;
  *y = *x-*y;
  *x = *x-*y;
}

void sort(int* a, int nItems) {
  int i, j;
  int iMin;

  for(j = 0 ; j < nItems-1 ; j++) {
    /* find the smallest element in unsorted array a[j ... n-1] */
    iMin = j;   //-- assume that the first element is the smallest

    /* test against elements after j to find the smallest */
    for(i = j+1 ; i < nItems ; i++) {
      /*  if current element is less then it is the new minimum */
      if(a[i] < a[iMin]) {
        iMin = i;
      }
    }

    if(iMin != j) {
      swap(&a[iMin], &a[j]);
    }
  }
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    printf("Enter an unsorted sequence of numbers as arguments!\n");
    printf("ex. Usage: ./a.out 3 7 1 9 4\n");
  }
  else {
    int i;
    int nItems;

    int A[MAXITEMS];

    nItems = argc-1;

    for(i = 0 ; i < nItems ; i++) {
      A[i] = atoi(argv[i+1]);
    }

    sort(A, nItems);

    printf("The sorted array is: ");
    display(A, nItems);

    return 0;
  }
}

