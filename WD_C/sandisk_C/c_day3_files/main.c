#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void file1();
typedef struct{
    char buf[30];
    int num;
}Data;
char *current_time(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    return asctime(timeinfo);
}

void ReadWriteBinary()
{
    Data arr[] ={{"qqqqqq qqqqqq", 123},
                {"bbbbb bb bbbb", 83756},
                {"cccccccccccc", 123456},
                {"dddddd", 121212},
                {"eee", 666},
                };
    Data arr1[5];
    FILE *fp = fopen("outBin.txt","w+");
    int count = sizeof(arr)/sizeof(Data);
    fwrite(arr, sizeofData, count, fp);

    int i;
    char ch;


}

int main(){

}


int main_2()
{
    printf("\nStart program: %s\n", current_time());
    Data arr[] ={{"qqqqqq qqqqqq", 123},
                {"bbbbb bb bbbb", 83756},
                {"cccccccccccc", 123456},
                {"dddddd", 121212},
                {"eee", 666},
                };

    FILE *fp = fopen("test2.txt","w");
    int i;
    char ch;
    int count = sizeof(arr)/sizeof(Data);
    fprintf(fp, "%d\n", count);
    for(i=0; i < count; i++){
        printf("%30s%10d\n", arr[i].buf, arr[i].num);
        fprintf(fp,"%29s%10d\n", arr[i].buf, arr[i].num);
    }
    fseek(fp, 0, SEEK_SET);
    fscanf(fp, "%d", &count);
    ch = fgetc(fp);
    Data* ptr = (Data*)malloc(sizeof(Data)*count);
    for(i=0; i<count;i++){
        fgets(ptr[i].buf, 30, fp);
        fscanf(fp, "%d", &ptr[i].num);
    }

    printf("\nEnd program: %s\n", current_time());
    fclose(fp);
    return 0;
}
void file1(){
    FILE *fp, *fp_out;
    char buf[32];
    int num;
    char ch;
    short sh = 24930;
    fp = fopen("test.txt", "r");
    fp_out = fopen("test_copy.txt", "w");

    if((fp != NULL) && (fp_out != NULL)){
            while(!feof(fp))
            {
                ch = fgetc(fp);
                if (ch != EOF){
                        //fputc(ch, fp_out);
                        fwrite(&sh, sizeof(short), 1, fp_out);

                }

//                fscnaf(fp, "%s", str);
//                fscnaf(fp, "%d", num);
//                fgets(buf, 32, fp);
                //printf("%s", buf);
                //fprintf(stdout, "%s", buf);
            }
    }
    fclose(fp);
    fclose(fp_out);

}
