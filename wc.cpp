#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

void Count(char * file); 
int Zicount=0;
int Wordcount=0;
int Hangcount=0;

void Count(char * file)
{
    FILE * fp;
    char a;
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        exit(-1);
    }
    while(!feof(fp))
    {
        a=fgetc(fp);

        if(a!=' '&&a!='\n'&&a!='\t'&&a!=','&&a!='.'&&a!='!'&&a!=';'&&a!='=')
            Zicount++;
        if(a==' '||a=='\n'||a=='\t'||a==','||a=='.'||a=='!'||a=='='||a==';')
        {
            if(a=='=')                   //���==      
                Wordcount--;
            Wordcount++;
        }
    }
    Zicount--;          //at end of the file,Zicount will add 
    fclose(fp);
}


int main(int argc, char* argv[])               //argv[1]����ָ�argv[2]�����ļ�·��
{
    FILE *fp;
    Count(argv[2]);
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        {    
        printf("���ļ������ڣ�\n\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        continue;
        }
        else if(strcmp(argv[1],"-c")==0)                   //ͳ���ļ��ַ���
            printf("�ļ�%s�ַ���Ϊ:%d\n",argv[2],Zicount);
        else if(strcmp(argv[1],"-w")==0)                   //ͳ���ļ�������
            printf("�ļ�%s������Ϊ:%d\n",argv[2],Wordcount);
        else if(strcmp(argv[1],"exit")==0)
        {
            printf("�������!\n");
            break;
        }
        else 
            printf("��ָ����ڣ�����������\n");
        printf("\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
    }
    return 0;
}





