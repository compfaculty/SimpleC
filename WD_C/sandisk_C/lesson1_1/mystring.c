#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

void countChar(char* str, char ch, int* Count){
        int cnt = 0;
        char* p = strchr(str, ch);
        while(p != NULL)
        {
            cnt++;
        }
    }

void findAndReplaseSub(char *s1, char *findStr, char *subStr){
    char temp[256];
    int i;
    while(1){

        char* result = strstr( s1, findStr );
        if( result == NULL ) {
            printf( "Could not find '%s' in '%s'/n", findStr, s1 );
            break;
        }
        strcpy(temp, result + strlen(findStr));
        for (i = 0 ; i < strlen(subStr); i++)
        {
            result[i] = subStr[i];
        }
        strcpy(result + strlen(findStr), temp);
    }
}

void replaceAll(char* a, char* sub, char* replaceSub)
{
	int subLen = strlen(sub);
	int replaceSubLen = strlen(replaceSub);
	char temp[100];
	char* p = strstr(a, sub);//a: "123abc45abb678ab",
	while(p)
	{
		strcpy(temp, p+subLen); //temp: c45abb678ab
		strcpy(p, replaceSub); //a: "123XYZ\05abb678ab"
		strcat(p, temp);
		p = strstr(p+replaceSubLen, sub);
	}
}

int findAllMatches(char* s, char* sub, int* matches)
{
	int matchesInd = 0;
	char* p = strstr(s, sub);//s[i] => p-s
	while(p != NULL)
	{
		matches[matchesInd] = p - s;
		matchesInd++;
		p = strstr(p+1, sub);
	}
	return matchesInd;
}


int* findAllMatches_arr(char* s, char* sub, int* cntPtr)
{
	int matchesInd = 0;
	char* p = strstr(s, sub);//s[i] => p-s
	int* matches;
	while(p != NULL)
	{
		matchesInd++;
		p = strstr(p+1, sub);
	}

	matches = (int*)malloc(matchesInd*sizeof(int));
	p = strstr(s, sub);
	matchesInd = 0;
	while(p != NULL)
	{
		matches[matchesInd] = p - s;
		matchesInd++;
		p = strstr(p+1, sub);
	}
	*cntPtr = matchesInd;
	return matches;
}

char *swap_and_join(char *s1, char *s2)
{
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    char *result = (char*)malloc((len_s1+len_s2 +1)*sizeof(char));
    int i=0;
    while((*(s1) != '\0') && (*(s2) != '\0'))
    {
            *(result + i) = *(s1++);
            *(result + i+1) = *(s2++);
            i = i+2;

    }
    if ((*(s1) == '\0') && (*(s2) == '\0'))
    {
        *(result + i + 1) = '\0';
        return result;
    }
    if (*(s1) == '\0'){
        strcpy(result+i, s2);
//        *(result + i + 1) = '\0';
        return result;
    }
    if (*(s2) == '\0'){
        strcpy(result+i, s1);
//        *(result + i + 1) = '\0';
        return result;
    }
}

int *sub_position(char *s, char *sub)
{
    int *tmp = (int*)malloc(strlen(s)*sizeof(int));
    char *index = strstr(s, sub);
    int i = 0;
    int count = 0;
    while(index){
        *(tmp + i) = index - s;
        i++;
        count++;
        index = strstr(index + strlen(sub), sub);
    }
    int *res = (int*)malloc(count*sizeof(int));
    memcpy(res, tmp, count*sizeof(count));
    free(tmp);
    return res;
}
