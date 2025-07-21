#include <string.h>
#include <search.h>
#include <stdbool.h>
#define MENU_MESSAGE_LEN        30
// i2p library Version 7.3
// Author: Kleanthis Thramboulidis
typedef struct fraction{
	int n;  // for numerator
	int d; // for denominator
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

char getChar(char message[]);
void getStringV1(char message[], char str[]);
void getStringV2(char message[],char str[], int strSize);

Date getDate(char msg[]);
void printDate(char msg[],Date date);

void sortStringArrayInc(char base[],int numOfElements, int strWidth);
void sortStringArrayDec(char base[],int numOfElements, int strWidth);
void *bSearchWord(char *word,char *base,int numOfElements, int strWidth);

void sortIntArrayInc(int ar[],int numOfElements);
void sortIntArrayDec(int ar[],int numOfElements);

bool getExpressionV1(char *operatorPtr,int *op1np,int *op1dp,int *op2np,int *op2dp); // reads an expression of the following form + 1/5 3/15
Expression getExpressionV2(void); // reads an expression of the following form + 1/5 3/15

int getUserCommand(char menu[][MENU_MESSAGE_LEN],int numOfEl);
