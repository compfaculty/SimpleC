#include <stdio.h>
#include <stdlib.h>

void ReadWriteBinary();

typedef struct
{
	char buf[30];
	int num;
}Data;


void main_old()
{
	//ReadWriteAscii();
	ReadWriteBinary();
}

void ReadWriteBinary()
{
	Data arr[] = {{"aaaaaaaaaa aaaaaa", 123}, {"bbbbb bbbb bbb", 83756}, 
	{"ccccccccccc", 1245783}, {"ddddddd", 1211313}, {"eee", 765634523}};
	Data arr1[5];
	FILE* fp = fopen("C:\\Katia\\outBin.txt", "w+");
	int cnt = sizeof(arr)/sizeof(Data);
	fwrite(arr,sizeof(Data),cnt, fp);
	fseek(fp, 0, SEEK_SET);
	fread(arr1, sizeof(Data), 5, fp);
	fclose(fp);
}
void ReadWriteAscii()
{
	Data* ptr;
	char ch;
	Data arr[] = {{"aaaaaaaaaa aaaaaa", 123}, {"bbbbb bbbb bbb", 83756}, 
	{"ccccccccccc", 1245783}, {"ddddddd", 1211313}, {"eee", 765634523}};
	FILE* fp = fopen("C:\\Katia\\out.txt", "w+");
	int i;
	int cnt = sizeof(arr)/sizeof(Data);
	//write
	fprintf(fp,"%d\n", cnt);
	for(i =0; i<cnt;i++)
	{
		fprintf(fp,"%29s%10d\n",arr[i].buf, arr[i].num);
	}

	//read
	fseek(fp, 0, SEEK_SET);
	fscanf(fp, "%d", &cnt);
	ch = fgetc(fp);
	ptr = (Data*)malloc(sizeof(Data)*cnt);
	for(i = 0; i<cnt;i++)
	{
		fgets(ptr[i].buf, 30, fp);
		fscanf(fp, "%d", &ptr[i].num);
		ch = fgetc(fp);
	}



	fclose(fp);
	getchar();
}

void main_()
{
	FILE* fp;
	char str[32];
	int num;
	char ch;
	fp = fopen("C:\\Users\\katia\\Desktop\\a.txt", "r");
	while(!feof(fp))
	{
		ch = fgetc(fp);
		fputc(ch, stdout);
		////fgets(str, 32, fp);
		//fscanf(fp, "%s", str);
		//fscanf(fp, "%d", &num);
		//fprintf(stdout, "string is : %s, number is: %d\n",str, num);
	}

	fclose(fp);
	getchar();
}