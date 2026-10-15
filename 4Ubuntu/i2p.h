#include <string.h>
#include <search.h>
#include <stdbool.h>
#define MENU_MESSAGE_LEN        30

// i2p library Version 7.4
// Book: An Introduction to the Art of Programming
// https://sites.google.com/view/i2art-of-programming/home
// Author: Kleanthis Thramboulidis
// https://sites.google.com/site/thramboulidiskleanthis/

typedef struct fraction{
	int ar;
	int par;
}Fraction;

typedef struct expression{
	char oprtr;  // for operator
	Fraction op1;
	Fraction op2;
}Expression;

typedef struct date{
	int year;
    int month;
    int day;
}Date;

int getInt(char message[]);
void printInt(char msg[],int num);
int getArrayOfInts(int ar[],int maxItems);

float getFloat(char message[]);
void printFloat(char msg[],float f);

char getChar(char message[]);
void printChar(char msg[],char ch);

void getStringV1(char message[], char str[]);
void getStringV2(char message[],char str[], int strSize);
void printString(char msg[],char s[]);

Date getDate(char msg[]);
void printDate(char msg[],Date date);

void sortIntArrayInc(int ar[],int numOfElements);
void sortIntArrayDec(int ar[],int numOfElements);

void sortStringArrayInc(char base[],int numOfElements, int strWidth);
void sortStringArrayDec(char base[],int numOfElements, int strWidth);
void *bSearchWord(char *word,char *base,int numOfElements, int strWidth);


bool getExpressionV1(char *operatorPtr,int *op1np,int *op1dp,int *op2np,int *op2dp); // reads an expression of the following form + 1/5 3/15
Expression getExpressionV2(void); // reads an expression of the following form + 1/5 3/15

int getUserCommand(char menu[][MENU_MESSAGE_LEN],int numOfEl);
