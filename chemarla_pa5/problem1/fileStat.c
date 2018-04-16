#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int count_nonspace();
int count_word();
int main(int argc, char *argv[]){
	FILE *filep;
	char input;
	char prevInput = '\n';

	int charCount=0, lineCount=0, wordCount=0;

	for (int i = 1; i < argc; i++){

	filep = fopen(argv[i], "r");

		if (filep)
		{
		printf("File: %s\n", argv[i]);
			charCount=0, lineCount=0, wordCount=0;
			while ((input = getc(filep)) != EOF){
				
				if(input != ' ' && input != '\n'){
					charCount++;
				}
				if((input == ' '&& prevInput == ' ')||(input == '\n' && prevInput == '\n')){
					continue;
				}
				if(input ==' '&& prevInput != ' '){
					wordCount++;
				}
				if(input != ' ' && prevInput == '\n'){
					wordCount++;
				}
				prevInput = input;
				if(input == '\n'){
					lineCount++;
				}
			}
		}
		else if(!filep)	
		{
			char str[100];
			printf("Failed to find/open file\n");
			printf("Enter a sentence: ");
			fgets(str, sizeof(str), stdin);
		
			printf("Characters:  %d\n", count_nonspace(str));
			printf("Words: %i\n", count_word(str));
			printf("Lines: 1\n");
			return 0;
				
		}
	}
		
	printf("Characters: %d \n",charCount);
	printf("Words: %d \n", wordCount);
	printf("Lines: %d \n", lineCount);
	
	
	return 0;

}

int count_nonspace(const char* str){
	int ccount =0;

	while(*str){
		if(!isspace(*str++))
			ccount++;
	}
		return ccount;
}

int count_word(const char* str){
	int wcount = 0;
	int len = 0;
	char lastC;
	len = strlen(str);
	if(len > 0)
	{
		lastC = str[0];
	}
	for (int i = 0; i <= len; i++){
		if((str[i]==' ' || str[i] == '\0'|| str[i] == '\t') && lastC != ' ')
		{
			wcount++;
		}
		lastC = str[i];
	}
	return wcount;
}

