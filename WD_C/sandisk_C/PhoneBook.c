#include "PhoneBook.h"

void AddNewRecord(TelephoneRecord** ptrDbArr, int* ptrInd, int* ptrSize)
{
	char tmpName[64];
	TelephoneRecord* dbArr;
	if(*ptrInd >= * ptrSize)
	{
		*ptrDbArr = (TelephoneRecord*)realloc(*ptrDbArr, *ptrSize * 2);
		*ptrSize *= 2;
	}
	dbArr = *ptrDbArr;	
	printf("enter name: ");
	gets(tmpName);
	//todo if name exists -> AddTelToRecord
	
	printf("enter phone number: ");
	gets(dbArr[*ptrInd].telephones[0].telNum);

	printf("tel type: 1 - home, 2 - work, 3 - mobile: ");
	scanf("%d", &(dbArr[*ptrInd].telephones[0].type));

	dbArr[*ptrInd].index = 1;
	dbArr[*ptrInd].name = (char*)malloc(sizeof(char) * (strlen(tmpName) + 1));
	strcpy(dbArr[*ptrInd].name, tmpName);
	(*ptrInd)++;
}

void AddTelToRecord(TelephoneRecord* dbArr, int ind)
{
	char tmpName[64];
	int i;
	printf("enter name: ");
	gets(tmpName);
	for(i = 0; i <ind; i++)
	{
		if(strcmp(tmpName, dbArr[i].name) == 0)
		{
			if(dbArr[i].index >= 3)
			{
				printf("No more telphones for %s\n\n", tmpName);
				return;
			}
			printf("enter new phone number: ");
			gets(dbArr[i].telephones[dbArr[i].index].telNum);

			printf("tel type: 1 - home, 2 - work, 3 - mobile: ");
			scanf("%d", &(dbArr[i].telephones[dbArr[i].index].type));
			dbArr[i].index++;
		}
	}
}

int GetChoice()
{
	int choice;
	printf("1 - to add new record\n"
		"2 - add tel to existing record\n"
		"3 - remove tel from record\n"
		"4 - show all\n"
		"5 - show sorted\n"
		"6 - exit\n");
	scanf("%d", &choice);
	getchar();
	return choice;
}

void FreeAll(TelephoneRecord* dbArr, int ind)
{
	int i;
	for(i = 0; i< ind; i++)
		free(dbArr[i].name);
	free(dbArr);
}

void main()
{
	TelephoneRecord* dbArr;
	int ind = 0;//logical size
	int choice = 10;
	int size = INIT_SIZE; //allocation size
	dbArr = (TelephoneRecord*)malloc(INIT_SIZE * sizeof(TelephoneRecord));
	
	choice = GetChoice();

	while(choice != 6)
	{
		switch(choice)
		{
		case 1:
			AddNewRecord(&dbArr, &ind, &size);
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
			//show sorted
			break;
		default:
			printf("illigal input\n");
		}
		choice = GetChoice();
	}
	FreeAll(dbArr, ind);
	getchar();
}

void PrintAll(TelephoneRecord* dbArr, int ind)
{
	int i,j;
	for(i = 0; i < ind; i++)
	{
		printf(" ------------ %s ----------\n", dbArr[i].name);
		for(j = 0; j < dbArr[i].index; j++)
		{
			printf("tel #%d: type %d, num %s\n", j+1, 
				dbArr[i].telephones[j].type, dbArr[i].telephones[j].telNum);
		}
		printf("\n\n");
	}
}

