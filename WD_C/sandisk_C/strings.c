#include <stdio.h>
#include <string.h>

void countChar(char* str, char ch, int* pCount)
{
	int cnt = 0;
	/*int i;
	int len = strlen(str);
	*pCount = 0;
	for(i =0;i<len; i++)
		if(str[i] == ch)*/
	//		*pCount = *pCount + 1;
	char* p = strchr(str, ch);
	while(p != NULL)
	{
		cnt++; //(*pCount)++;
		p = strchr(p+1, ch);
	}
	*pCount = cnt;

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

void main()
{
	char a[100] = "123abc45abb678ab";
	replaceAll(a, "ab","xyz");

	puts(a);
	getchar();

}

void main2()
{
	int res;
	char name[20] = "abracadabra";
	int i, len;
	countChar(name, 'a', &res);
	
	//strcat(name, " !!");
	//strcpy(name, "bla bla");
	len = strlen(name);
	/*for(i=0; name[i] != '\0'; i++)
		putchar(name[i]);
*/
	printf("%c appears in %s %d times", 'a', name, res);
	getchar();
}