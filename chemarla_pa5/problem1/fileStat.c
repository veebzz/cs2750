#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	FILE *filep;
	char input;
	char filename[100];
	int charCount=0, lineCount=0, wordCount=0;


	strcpy(filename, argv[1]);

	filep = fopen(filename, "r");

	if (filep)
	{
		while ((input = getc(filep)) != EOF){
			if(input != ' ' && input != '\n'){
				charCount++;
			}
			if(input ==' ' || input =='\n'){
				wordCount++;
			}
			if(input == '\n'){
				lineCount++;
			}
		}
		if(charCount > 0){
			lineCount++;
			wordCount++;
		}
	}
	else	
	{
	printf("Failed to open file\n");
	}
	printf("Characters: %d \n",charCount);
	printf("Words: %d \n", wordCount);
	printf("Lines: %d \n", lineCount);
	getchar();
	return 0;
}


