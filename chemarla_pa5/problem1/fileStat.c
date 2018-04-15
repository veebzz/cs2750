#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	FILE *filep;
	char input;
	char prevInput = '\n';
	//char filename[100];
	int charCount=0, lineCount=0, wordCount=0;

	for (int i = 1; i < argc; i++){
	//strcpy(filename, argv[1]);

	filep = fopen(argv[i], "r");

		if (filep)
		{
			charCount=0, lineCount=0, wordCount=0;
			while ((input = getc(filep)) != EOF){
				
				if(input != ' ' && input != '\n'){
					charCount++;
				}
				if(input ==' '&& prevInput != ' '){
					wordCount++;
				}
				prevInput = input;
				if(input == '\n'){
					lineCount++;
				}
			}
	//	if(charCount > 0){
	//		lineCount++;
	//		wordCount++;
	//	}
	}
	else	
	{
	printf("Failed to open file\n");
	}
	printf("Characters: %d \n",charCount);
	printf("Words: %d \n", wordCount);
	printf("Lines: %d \n", lineCount);
	getchar();
	}
	return 0;

}


