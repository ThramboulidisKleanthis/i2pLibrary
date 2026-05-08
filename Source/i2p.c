#include <stdio.h>
#include <stdlib.h>
#include "i2p.h"

// i2p library Version 7.4  
// Book: An Introduction to the Art of Programming 
// https://sites.google.com/view/i2art-of-programming/home
// Author: Kleanthis Thramboulidis
// https://sites.google.com/site/thramboulidiskleanthis/

void clearStdin(void);

int getInt(char message[]){
	int num;
	printf("%s:",message);
	scanf("%d",&num);
	clearStdin();
	return num;
}

void printInt(char msg[],int num){
    printf("%s %d\n",msg,num);
}

float getFloat(char message[]){
	float f;
	printf("%s:",message);
	scanf("%f",&f);
    clearStdin();
	return f;
}
void printFloat(char msg[],float f){
    printf("%s %f\n",msg,f);
}

char getChar(char message[]){
	char ch;
	fflush(stdin);
	printf("%s:",message);
 	ch = getchar();
	clearStdin();
    return ch;
}
void printChar(char msg[],char ch){
    printf("%s %c\n",msg,ch);
}

int getArrayOfInts(int ar[],int maxItems){
	int numOfItems;
	int i=0;
	char format[50];
	sprintf(format,"Dose plithos stoixeiwn (max=%d):",maxItems);
	numOfItems = getInt(format);
	numOfItems = (numOfItems<maxItems)?numOfItems:maxItems;
	for(i=0;i<numOfItems;i++){
		sprintf(format,"Dose %d item:",i+1);
		ar[i]=getInt(format);
	}
	return numOfItems;
}


void getStringV1(char message[], char str[]){
    int i=0;
    char ch;
    printf("%s:",message);
    while((ch=getchar())!='\n')
        str[i++]=ch;
    str[i]='\0';
}

void getStringV2(char message[],char str[], int size){
    char ch;
	int i=0;
	printf("%s (max=%d):",message,size-1);
	while(((ch=getchar())!='\n')&& i<size-1)
        str[i++]=ch;
	str[i]='\0';
	if(ch!='\n')
        clearStdin();
}

void printString(char msg[],char s[]){
    printf("%s %s\n",msg,s);
}

int compare4inc(const void *elem1, const void *elem2);
int compare4dec(const void *elem1, const void *elem2);
int compIntInc(const void *a, const void*b);
int compIntDec(const void *a, const void*b);

void sortStringArrayInc(char *base,int numOfElements, int strWidth){
	qsort((void *)base, numOfElements,strWidth, compare4inc );
	printf("incremental_sort completed\n");
}

void *bSearchWord(char *word,char *base,int numOfElements, int strWidth){
	return bsearch((void *)word, (void *)base, (size_t)numOfElements,(size_t)strWidth, compare4inc );
}

bool getExpressionV1(char *operatorPtr,int *op1np,int *op1dp,int *op2np,int *op2dp){
    printf("Enter the expression (e.g. + 1/4 2/4) or q (for termination): ");
  	fflush(stdin);
	*operatorPtr = getchar();
	if((*operatorPtr=='q'||*operatorPtr=='Q'))
   		return false;
	scanf(" %d/%d  %d/%d",op1np,op1dp,op2np,op2dp);
   	fflush(stdin);
    return true;
}


Expression getExpressionV2(void){
	Expression exp;

 	fflush(stdin);
    printf("Enter the expression (e.g. + 1/4 2/4) or q (for termination): ");
    exp.oprtr = getchar();
	if((exp.oprtr=='q'||exp.oprtr=='Q'))
   		return exp;
	scanf(" %d/%d  %d/%d",&exp.op1.n,&exp.op1.d,&exp.op2.n,&exp.op2.d);
 	fflush(stdin);
   	return exp;
}

Date getDate(char msg[]){
	Date date;
	while(true){
		printf("%s (DD/MM/YY): ",msg);
		scanf("%d/%d/%d",&date.day,&date.month,&date.year);
		if((date.day<32 && date.month<13 && date.year<99 ) && ((date.day&&date.month&&date.year)))
			break;
		else
			printf("Enter a valid date!\n");
	}
	return date;
}

void printDate(char msg[],Date date){
	printf("%s: %d/%d/%d\n",msg,date.day,date.month,date.year);
}

int compare4inc(const void *elem1, const void *elem2){
	return(strcmp((char*)elem1,(char*)elem2));
}

void sortStringArrayDec(char *base,int numOfElements, int strWidth){
	qsort((void *)base, numOfElements,strWidth, compare4dec );
	printf("decremental_sort completed \n");
}

int compare4dec(const void *elem1, const void *elem2){
	return(-strcmp((char*)elem1,(char*)elem2));
}

void sortIntArrayInc(int ar[],int numOfElements){
	qsort((void*)ar,numOfElements,sizeof(int),compIntInc);
}

void sortIntArrayDec(int ar[],int numOfElements){
	qsort((void*)ar,numOfElements,sizeof(int),compIntDec);
}

int compIntInc(const void *a, const void*b){
	if(*(int*)a==*(int*)b)
		return 0;
	return *(int*)a>*(int*)b?1:-1;
}

int compIntDec(const void *a, const void*b){
	return -compIntInc(a,b);
}

void clearStdin(void){
	char ch;
  	while ((ch=getchar()) != '\n');
}

int getUserCommand(char menu[][MENU_MESSAGE_LEN],int numOfEl){
    printf("\n\n");
    for(int i=0;i<numOfEl;i++)
        printf("%d-%s\n",i,menu[i]);
    return getInt("\nEnter your selection:");
}
