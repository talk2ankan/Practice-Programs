#include "heapify.h"

void buildMaxHeap(int *Arr, int n) {
	int i;

	/* call maxHeapify recursively on every non-leaf node */
	for(i = n/2 ; i >= 0 ; i--)
		maxHeapify(Arr, i, n);

	return;
}

void maxHeapify(int* Arr, int i, int n) {
	int leftChild, rightChild, max;

	/* these two variables hold the indexes of the left and the right child */
	leftChild = 2*i + 1;
	rightChild = 2*i + 2;

	/* the max variable holds the index of the parent */
	max = i;

	/* if the left child is greater than the parent set max = leftChild*/
	if(leftChild < n && Arr[leftChild] > Arr[max])
		max = leftChild;

	/* if the right child is greater than the parent set max = rightChild */
	if(rightChild < n && Arr[rightChild] > Arr[max])
		max = rightChild;

	/* if max is not the parent swap the parent with the largest value */
	if(max != i) {
		swap(&Arr[i], &Arr[max]);

		/* call maxHeapify on the child with the new value */
		maxHeapify(Arr, max, n);
	}

	return;
}

void swap(int* a, int* b) {
	*a = *a+*b;
	*b = *a-*b;
	*a = *a-*b;

	return;
}
