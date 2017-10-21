#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef enum
{
    HomeTelephone = 1,
    MobileTelephone,
    WorkTelephone
}TelephoneTypes;

typedef struct
{
    TelephoneTypes type;
    char *number;
}Telephone;

typedef struct{
    char *name;
    Telephone *number[3];
}TelephoneRecord;

void AddRecord(TelephoneRecord **DB, int size, TelephoneRecord *newrecord);
void RemoveNumber(TelephoneRecord **DB, int size, char *number);
void ShowAllRecords(TelephoneRecord **DB, int size);
void ShowSortedByName(TelephoneRecord **DB, int size);
TelephoneRecord *createRecord();
void initRecord(TelephoneRecord *record);
int main()
{
    int count = 0;
    int recordsAmmount = 1;
    int i;
    printf("Please insert amount of records\n");
    //scanf("%d", &recordsAmmount);

    //create DB
    TelephoneRecord **DB = (TelephoneRecord**)malloc(sizeof(TelephoneRecord*)*SIZE);
    for(i=0; i < recordsAmmount;i++){
        TelephoneRecord *tmp = createRecord();
        initRecord(tmp);
        AddRecord(DB, count, tmp);
        count++;
    }
    ShowAllRecords(DB,1);
    printf("Hello world!\n");
    free(DB);
    return 0;
}
TelephoneRecord *createRecord(){
    TelephoneRecord *res = (TelephoneRecord*)malloc(sizeof(TelephoneRecord));
    return res;
}
Telephone *createTelephone(int tel_type, char *number){
    Telephone *tmpTel = (Telephone*)malloc(sizeof(Telephone));
    tmpTel->number = (char*)malloc(sizeof(char)*(strlen(number) + 1));
    strcpy(tmpTel->number, number);
    switch(tel_type)
    {
        case 1:
            tmpTel->type = HomeTelephone;
            break;
        case 2:
            tmpTel->type = MobileTelephone;
            break;
        case 3:
            tmpTel->type = WorkTelephone;
            break;
    }
    return tmpTel;
}
void initRecord(TelephoneRecord *record){
    char tmpName[40];
    char tmpNumber[40];
    int tel_type;

    printf("Insert contact name");
    scanf("%s",tmpName);
    //scanf("%d%s%s",&tel_type, tmpNumber, tmpName);

    record->name = (char*)malloc(sizeof(char)*(strlen(tmpName) + 1));
    strcpy(record->name, tmpName);
    printf("Insert tel type and number");
    scanf("%d%s",&tel_type, tmpNumber);

    record->number[0] = createTelephone(tel_type, tmpNumber);

}
void AddRecord(TelephoneRecord **DB, int c, TelephoneRecord *newrecord){
    *(DB + c) = newrecord;
}
void RemoveNumber(TelephoneRecord **DB, int size, char *number);
void ShowAllRecords(TelephoneRecord **DB, int size){
    int i;
    for(i=0; i < size; i++){
        printf("Name %s Number %s Type %d", (*DB+i)->name,(*DB+i)->number[0]->number, (*DB+i)->number[0]->type);
    }
}
void ShowSortedByName(TelephoneRecord **DB, int size);
