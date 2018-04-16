#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int count_nonspace();
int count_word();
char str[100];
int tChar=0, tWord=0, tLine=0;//total stat variables
int main(int argc, char *argv[]){
	FILE *filep;
	char input;
	char prevInput = '\n';

	int charCount=0, lineCount=0, wordCount=0;
		for (int i = 1; i < argc; i++){
			// open file
			filep = fopen(argv[i], "r");
			//if the open file exits in the directory 
			if (filep)
			{
				charCount=0, lineCount=0, wordCount=0;
				//while loop that counts the characters, words, and lines
				while ((input = getc(filep)) != EOF){
				
					if((input == ' '&& prevInput == ' ')||(input == '\n' && prevInput == '\n')||(input == '\t'&& prevInput == '\t')){
						continue;	//skip iteration
					}
					if(input ==' '&& prevInput != ' '){
						wordCount++;
						tWord++;
					}
					if( input != ' ' && prevInput == '\n'){
						wordCount++;
						tWord++;
					}
					if((input != ' ')&&( input != '\n')&&(input != '\t')){
					 	charCount++;
						tChar++;
				       	}
					
					//let preInput equal input for next iteration
					prevInput = input;
					//purposely chose to only counts lines with text
					//project pdf doesnt specify that it has imitate wc command which counts
					//empty lines(wc command is just a suggestion)
					if(input == '\n'){
						lineCount++;
						tLine++;
					}

				}
				//add 1 to word count because of a EOF issue
				wordCount++;
				tWord++;
				//Display each file's stat	
				printf("File: %s\n",argv[i]);
				printf("Characters: %d \n",charCount);
				printf("Words: %d \n", wordCount);
				printf("Lines: %d \n", lineCount);
				printf("---------------------------------\n");

			}
		

	//given argument doesnt exist
	//ask user for sentence to read from stdio stream
	if(!filep)
	{
			
			printf("Failed to find/open file\n");
			printf("Enter a sentence: ");
			fgets(str, sizeof(str), stdin);
		
			printf("Characters:  %d\n", count_nonspace(str));
			printf("Words: %i\n", count_word(str));
			printf("Lines: 1\n");
			//end for main funcition if the user chose to input a sentence
			return 0;
				
		}
	}
	//if no command line arguments given ask user for sentence
	if(argc < 2)
	{
			
			printf("No command line arguments given\n");
			printf("Enter a sentence: ");
			fgets(str, sizeof(str), stdin);
		
			printf("Characters:  %d\n", count_nonspace(str));
			printf("Words: %i\n", count_word(str));
			printf("Lines: 1\n");
			//end for main funcition if the user chose to input a sentence
			return 0;
				
		}
	//if 1 or more command line arguments given display total stats at the end	
	if(argc > 1){
	//Display total statistic at last iteration of for loop
	printf("Total Statistics\n");
	printf("Total Characters: %d \n",tChar);
	printf("Total Words: %d \n", tWord);
	printf("Total Lines: %d \n", tLine);
	}
	return 0;

}
// function to count characters if user input a sentence
int count_nonspace(const char* str){
	int ccount =0;

	while(*str){
		if(!isspace(*str++))
			ccount++;
	}
		return ccount;
}
//function to count words if user inputs a sentence
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

