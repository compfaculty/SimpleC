#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEL_LEN 10
#define MAX_NUMBERS 3
#define INIT_SIZE 20

typedef enum{
	HOME = 1,
	WORK,
	MOBILE
}TelephoneType;

typedef struct{
	TelephoneType type;
	char telNum[TEL_LEN + 1];//for '\0'
}Telephone;

typedef struct{
	char* name;
	Telephone telephones[MAX_NUMBERS];
	int index;
}TelephoneRecord;

void PrintAll(TelephoneRecord*, int);
void AddNewRecord(TelephoneRecord** , int* , int* );
int GetChoice();
void FreeAll(TelephoneRecord*, int );
void AddTelToRecord(TelephoneRecord* , int );
