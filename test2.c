
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp;
FILE *out_fp;
bool lexicalError = false;
int lexemeCount = 0;


int lookup(char ch);
void addChar(void);
void getChar(void);
void getNonBlank(void);
int lex(void);
void lexError(void);

#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99


#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26
#define MOD_OP 27
#define GREATER_THAN 28
#define LESS_THAN 29
#define SEMICOLON 31
#define LEFT_BRACE 32
#define RIGHT_BRACE 33
#define NOT_EQUAL 34
#define LEFT_BRACKET 35
#define RIGHT_BRACKET 36
#define UNDERSCORE 37
#define EQUAL 38
#define GREATER_THAN_EQUAL 39
#define LESS_THAN_EQUAL 40
#define TREVOR_LOOP 50
#define TREVOR_SELECTION 51
#define TREVOR_ALT_SELECTION 52
#define JUST_ONE_BYTE 60
#define JUST_TWO_BYTES 61
#define JUST_FOUR_BYTES 62
#define JUST_EIGHT_BYTES 63


int lookup(char ch) {
	 switch (ch) {
		 case '(':
			 addChar();
			 nextToken = LEFT_PAREN;
			 break;
		 case ')':
			 addChar();
			 nextToken = RIGHT_PAREN;
			 break;
		 case '+':
			 addChar();
			 nextToken = ADD_OP;
			 break;
		 case '-':
			 addChar();
			 nextToken = SUB_OP;
			 break;
		 case '*':
			 addChar();
			 nextToken = MULT_OP;
			 break;
		 case '/':
			 addChar();
			 nextToken = DIV_OP;
			 break;
		 case '%':
			 addChar();
			 nextToken = MOD_OP;
			 break;
		 case '>':
			 addChar();
			 nextToken = GREATER_THAN;
			 break;
		 case '<':
			 addChar();
			 nextToken = LESS_THAN;
			 break;
		 case '=':
			 addChar();
			 nextToken = ASSIGN_OP;
			 break;
		 case ';':
			 addChar();
			 nextToken = SEMICOLON;
			 break;
		 case '{':
			 addChar();
			 nextToken = LEFT_BRACE;
			 break;
		 case '}':
			 addChar();
			 nextToken = RIGHT_BRACE;
			 break;
		 case '[':
			 addChar();
			 nextToken = LEFT_BRACKET;
			 break;
		 case ']':
			 addChar();
			 nextToken = RIGHT_BRACKET;
			 break;
		 case '!':
			 addChar();
			 nextToken = NOT_EQUAL;
			 break;
		 case '_':
			 addChar();
			 nextToken = UNDERSCORE;
			 break;
		 case '|':
			 addChar();
			 nextToken = EQUAL;
			 break;
		 case '@':
			 addChar();
			 nextToken = GREATER_THAN_EQUAL;
			 break;
		 case '$':
			 addChar();
			 nextToken = LESS_THAN_EQUAL;
			 break;
		 default:
			 addChar();
			 lexError();
			 printf("Lexeme '%s' not in language\n", lexeme);
			 nextToken = EOF;
			 break;
	 }
	 return nextToken;
}

