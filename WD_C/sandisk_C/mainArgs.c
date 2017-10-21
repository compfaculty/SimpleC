#include <stdio.h>
#include <stdlib.h>


void main1(int argc, char* argv[], char* envArr[])
{
	int i;
	char* pathVal;
	/*for(i = 0; i<argc; i++)
	{
		puts(argv[i]);
	}*/

	/*for(i = 0; envArr[i] ;i++)
	{
		puts(envArr[i]);
	}
*/
	
	pathVal = getenv("PATH");
	if(pathVal)
	{
		printf("before update PATH = %s",pathVal);
	}
	putenv("PATH=.");
	pathVal = getenv("PATH");
	if(pathVal)
	{
		printf("\n\nafter update PATH = %s",pathVal);
		
	}
	getchar();
}