#ifndef MYSTRUCTURES_H_INCLUDED
#define MYSTRUCTURES_H_INCLUDED
#endif // MYSTRUCTURES_H_INCLUDED

typedef struct
{
    int day;
    int month;
    int year;
}Date;

typedef struct
{
    int age;
    double hight;
    char *fullName;
    Date birthdate;
}Person;

typedef struct
{
    char name[20];
    double price;
    int pages;
} Book;

typedef struct
{
    char grade;
    Book book;
} StudyBook;

typedef union
{
    Book basebook;
    StudyBook studybook;

} GenericBook;

typedef enum{
    BaseBookType = 1,
    StudyBookType
} ActiveField;

void buildArrayPerson(Person **arr, int size);
void initPerson(Person *per);
void initArrayPerson(Person arr[], int size);
Person *findLongestNamePerson(Person arr[], int size);
void initBook(GenericBook *pBook, ActiveField field);
