/*
 * myio.c
 *
 *  Created on: Jun 7, 2017
 *      Author: guak
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<ctype.h>
#include "myio.h"


int ReadInteger(void){
	char *str = getLine();
	int length = getLength(str), i = 0, flag = 1;


	for(; i < length; i++){
		if(str[i] >= '9' || str[i] <= '0'){
			flag = 0;
		}
	}

	if(flag){
		return atoi(str);
	}
	else{
		printf("Only input integers...\n");
		int x = ReadInteger();
		return x;
	}

}

double ReadDouble(void){
	char *str = getLine();
	int length = getLength(str), i = 0, flag = 1;

	for(; i < length; i++){
			if((str[i] >= '9' || str[i] <= '0') && str[i] != '.'){
				flag = 0;
			}
		}

	if(flag && length < 17){
			return strtod(str, NULL);
		}
		else{
			printf("Only input type double...\n");
			double x = ReadDouble();
			return x;
		}
}

//Retrieved from https://stackoverflow.com/questions/314401/how-to-read-a-line-from-the-console-in-c
char * getLine(void) {
	char * line = malloc(100), * linep = line;
	size_t lenmax = 100, len = lenmax;
	int c;

	if(line == NULL)
		return NULL;

	for(;;) {
		c = fgetc(stdin);
		if(c == EOF)
			break;

		if(--len == 0) {
			len = lenmax;
			char * linen = realloc(linep, lenmax *= 2);

			if(linen == NULL) {
				free(linep);
				return NULL;
			}
			line = linen + (line - linep);
			linep = linen;
		}

		if((*line++ = c) == '\n'){
			break;
		}
	}
	*line = '\0';
	return linep;
}

int getLength(char *line){
	int c, i = 0;
	char *temp = line;
	for(;;) {
		c = *temp;
		if(c == EOF)
			break;

		if((*temp++ = c) == '\n'){
			break;
		}
		i++;
	}
	return i;
}
