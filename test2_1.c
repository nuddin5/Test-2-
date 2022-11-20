#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void getNonBlank(void) {
	while (isspace(nextChar))
	getChar();
}


int lex(void) {
	 lexLen = 0;
	 getNonBlank();
	 switch (charClass) {
	
		 case LETTER:
			 addChar();
			 getChar();
			 while (charClass == LETTER || charClass == UNDERSCORE) {
				 addChar();
				 getChar();
			 }
			
			if (!strcmp(lexeme, "TREVOR_LOOP")){
				printf("Loop found\n");
				nextToken = TREVOR_LOOP;
				break;
			}
			if (!strcmp(lexeme, "TREVOR_SELECTION")){
				printf("Selection found\n");
				nextToken = TREVOR_SELECTION;
				break;
			}
			if (!strcmp(lexeme, "TREVOR_ALT_SELECTION")){
				printf("Selection found\n");
				nextToken = TREVOR_ALT_SELECTION;
				break;
			}
			if (!strcmp(lexeme, "JUST_ONE_BYTE")){
				printf("JUST_ONE_BYTE found\n");
				nextToken = JUST_ONE_BYTE;
				break;
			}
			if (!strcmp(lexeme, "JUST_TWO_BYTES")){
				printf("JUST_TWO_BYTES found\n");
				nextToken = JUST_TWO_BYTES;
				break;
			}
			if (!strcmp(lexeme, "JUST_FOUR_BYTES")){
				printf("JUST_FOUR_BYTES found\n");
				nextToken = JUST_FOUR_BYTES;
				break;
			}
			if (!strcmp(lexeme, "JUST_EIGHT_BYTES")){
				printf("JUST_EIGHT_BYTES found\n");
				nextToken = JUST_EIGHT_BYTES;
				break;
			}
	
			if (lexLen < 6){
				printf("%s is too short to be a valid name\n", lexeme);
				printf("Variable names must be between 6 and 8 characters\n");
				lexError();
				break;
			} else if (lexLen > 8){
				printf("%s is too long to be a valid name\n", lexeme);
				printf("Variable names must be between 6 and 8 characters\n");
				lexError();
				break;
			}
			 nextToken = IDENT;
			 break;
			 end;
			 