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
		else	
		{
			char str[100];
			printf("Failed to open file\n");
			printf("Enter a sentence: ");
			fgets(str, sizeof(str), stdin);
		
			printf("charcount:  %d\n", count_nonspace(str));
			printf("wcount: %d\n", count_word(str));
		//	for(int i = 0; i < strlen(p); i++){
		//		if(isspace(p[i])){
		//			continue;
		//		}
		//		else if(isaplha(p[i])){
		//			charCount++;
		//		}
		//		else if(!isspace(p[i])&& isspace(p[i-1])){
		//			wordCount++;
		//		}
				
			
		//	}
		//	lineCount =1;
			 //printf("Characters: %d \n",charCount);
			// printf("Words: %d \n", wordCount);
			// printf("Lines: %d \n", lineCount);
			// return 0;
			break;
				
		}
	}
		
	printf("Characters: %d \n",charCount);
	printf("Words: %d \n", wordCount);
	printf("Lines: %d \n", lineCount);
	getchar();
	
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
	while(*str){
		if(isspace(*str) && !isspace(*str++)){
		wcount++;
		}
	}
	return wcount;
}	
