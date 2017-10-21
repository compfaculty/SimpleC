#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[20];
	double price;
	int pages;
}Book;

typedef struct 
{
	char grade;
	Book b;
	
}StudyBook;

typedef union
{
	Book baseBook;
	StudyBook studyBook;
}GenericBook;

typedef enum{
	BaseBookType = 1,
	StudyBookType
}ActiveField;

void initBook(GenericBook* pBook, ActiveField field)
{
	switch(field)
	{
	case BaseBookType:
		strcpy(pBook->baseBook.name, "kjadgwuag");
		pBook->baseBook.pages = 1234;
		pBook->baseBook.price = 987.65;
		break;
	case StudyBookType:
		pBook->studyBook.grade = 'A';
		strcpy(pBook->studyBook.b.name, "Lama Dana");
		pBook->studyBook.b.pages = 73;
		pBook->studyBook.b.price = 69.99;
		break;
	}
}

void printBook(const GenericBook* book, ActiveField field)
{
	switch(field)
	{
		case BaseBookType:
			printf("base book: %s %lf %d\n", book->baseBook.name, book->baseBook.price,
				book->baseBook.pages);
			break;
		case StudyBookType:
			printf("study book: %s %lf %d %c\n", book->studyBook.b.name, book->studyBook.b.price,
				book->studyBook.b.pages, book->studyBook.grade);
			break;
	}
}

void main()
{
	GenericBook book;
	initBook(&book, StudyBookType);
	printBook(&book, StudyBookType);

	getchar();
}