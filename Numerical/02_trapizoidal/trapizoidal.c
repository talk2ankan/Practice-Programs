/*
 * TRAPEZOIDAL RULE
 */

#include <stdio.h>
#include <stdlib.h>
#define f(x) x*x*x

int main() {
	float a; //-- lower limit
	float b; //-- upper limit
	float h; //-- segmentation width
	int n;   //-- no of intervals
	int i;   //-- loop counter

	printf("+========================+\n");
	printf("+    TRAPEZOIDAL RULE    +\n");
	printf("+========================+\n");

	printf("Lower limit: ");
	scanf("%f", &a); //-- entering the lower limit

	printf("Upper limit: ");
	scanf("%f", &b); //-- the upper limit

	printf("Number of intervals: ");
	scanf("%d", &n); //-- the number of intervals

	//-- calculating the segmentation width
	h = (b-a) / n;

	//-- check if solution is possible
	if((a+h) > b) {
		printf(">>> A solution is NOT possible with these inputs!!\n");
		exit(0);
	}

	//-- calculating the value of f(x)
	float pt1 = f(a) + f(b);

	float pt2;
	for(i = 1 ; i < n ; i++) {
		float x = a + (i*h);
		pt2 += f(x);
	}

	float I = (h/2) * (pt1 + 2*pt2);

	printf("The value of f(x) is: %f\n", I);

	return 0;
}

/* --- Sample output with equation f(x) = x^3 ---
   Lower limit: 1
   Upper limit: 2
   Number of intervals: 8
   The value of f(x) is: 3.761719
   ------------------------------------------------- */
