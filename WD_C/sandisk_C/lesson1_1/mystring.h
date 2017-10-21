#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED



#endif // MYSTRING_H_INCLUDED

//count specific char in string
void countChar(char* str, char ch, int* Count);

//find and replace substring
void findAndReplaseSub(char *s1, char *findStr, char *subStr);
void replaceAll(char* a, char* sub, char* replaceSub);

//
int findAllMatches(char* s, char* sub, int* matches);
int* findAllMatches_arr(char* s, char* sub, int* cntPtr);

//create new string mixing s1 and s2 and if one
//is longer put the tail to the end of result string
char *swap_and_join(char *s1, char *s2);

//returns array with positions of sub in string
int *sub_position(char *s, char *sub);

