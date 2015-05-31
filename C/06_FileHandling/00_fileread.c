/*
 * Basic file handling in C. Open and read a text file.
 */
#include <stdio.h>
#define MAXSIZE 100

int main() {
	FILE * fp;  //-- Create a FILE pointer
	char c;

	/* Open desired file in read mode */
	fp = fopen("sample.txt", "r");

	/* Read every character untill EOF */ 
	while(1) {
		c = fgetc(fp);

		if(c == EOF)
			break;

		printf("%c", c);
	}

	/* Finally close the file */
	fclose(fp);

	return 0;
}
