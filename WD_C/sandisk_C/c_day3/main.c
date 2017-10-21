#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEL_LEN 12
#define MAX_NUMBERS 3
#define INIT_SIZE 20
typedef enum{
    HOME,
    WORK,
    MOBILE
}TelephoneType;

typedef struct{
    TelephoneType type;
    char telNum[TEL_LEN + 1]; //for '/0'
}Telephone;

typedef struct{
    char *name;
    Telephone telephones[MAX_NUMBERS];
    int index;
}TelephoneRecord;

void AddNewRecord(TelephoneRecord** ptrDbArr, int* ptrInd, int* ptrSize){
    char tmpName[64];
    TelephoneRecord* dbArr = *ptrDbArr;
    if(*ptrInd >= *ptrSize)
    {
          *ptrDbArr = (TelephoneRecord*)realloc(*ptrDbArr, (*ptrSize)*2);
          dbArr = *ptrDbArr;
    }
    printf("Enter name:");
    gets(tmpName);
    printf("Tel type : 1 - home, 2- work, 3- mobile");
    scanf("%d", &(dbArr[*ptrInd].telephones[0].type));
    printf("Enter phone number\n");
    gets(dbArr[*ptrInd].telephones[0].telNum);
    dbArr[*ptrInd].index = 1;
    dbArr[*ptrInd].name = (char*)malloc(sizeof(char)*(strlen(tmpName)+1));
    strcpy(dbArr[*ptrInd].name, tmpName);
    (*ptrInd)++;
}

void AddTelToRecord(TelephoneRecord* dbArr, int ind){
    char tmpName[64];
    int i;
    printf("enter name:\n");
    gets(tmpName);
    for(i=0; i < ind; i++){
        if(strcmp(tmpName, dbArr[i].name) == 0){
            if(dbArr[i].index >= 3){
                printf("No more telephones for %s\n",  tmpName);
                return;
            }
            printf("Enter phone number\n");
            gets(dbArr[i].telephones[dbArr[i].index].telNum);
            printf("Tel type : 1 - home, 2- work, 3- mobile\n");
            scanf("%d", &(dbArr[i].telephones[dbArr[i].index].type));
            dbArr[i].index++;
        }
    }

}
void PrintAll(TelephoneRecord* dbArr, int ind){
    int i, j;
    for(i=0; i < ind; i++){
        printf("-----------------%s----------------\n", dbArr[i].name);
        for(j = 0;  j < dbArr[i].index; j++){
            printf("%s %d\n", dbArr[i].telephones[j].telNum, dbArr[i].telephones[j].type);
        }
    }

}

int main()
{

    TelephoneRecord *dbArr = (TelephoneRecord*)malloc(sizeof(TelephoneRecord)*INIT_SIZE);
    int ind = 0; //logical size
    int choice = 10;
    int size = INIT_SIZE; //allocation size
    printf("  1- to add new record\n"
               " 2- add to existing record\n"
               " 3- remove tel from record\n"
               " 4- show all records\n"
               " 5- show sorted\n"
               " 6- exit\n");

    scanf("%d", &choice);
    while(choice != 6){
        switch(choice){
            case 1:
                AddNewRecord(dbArr, &ind, &size);
                break;
            case 2:
                AddTelToRecord(dbArr, ind);
                break;
            case 3:
                //remove
                break;
            case 4:
                PrintAll(dbArr, ind);
                break;
            case 5:
                //show sordet
                break;
            case 6:
                exit(0);
                break;
            default :
                printf("Illegal input\n");

        }
        scanf("%d", &choice);
    }

    free(dbArr);
    return 0;
}
