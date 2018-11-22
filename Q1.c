/// this code is to open a text file you can Modify it to a desired file type.
                       ////// BAKARY TRAORE//////


#include <stdio.h>  // Input and Output 
#include <stdlib.h> // library for exit function
int main()
{
	char ch[1000]; // Number of Character
	FILE *f; // Define File pointer
f = fopen("program.txt", "r+")) // Opening the file
	if ( f== NULL)
	{
		printf("Error! regarding this file");
		// Program will stop if file pointer returns NULL.
		exit(1);
	}

	// reads text until newline 
	fscanf(f, "%[^\n]", ch);

	printf("Data from the file:\n%s", ch);
	fclose(f);

	return 0;
}