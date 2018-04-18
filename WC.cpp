#include<io.h>
#include<stdio.h>
#include<string.h>
void zifushu(FILE *wenjian);
void dancishu(FILE *wenjian);
void juzishu(FILE *wenjian);

void main()
{
	FILE *wenjian;
	wenjian = fopen("c:\\WC\\TXT\\wenben.txt","r");
	char mingling[100];
	char s1[100] = "wc.exe-c file.txt";
	char s2[100] = "wc.exe-w file.txt";
	char s3[100] = "wc.exe-s file.txt";
	printf("请输入计数指令:");
	gets(mingling);
	if(strcmp(mingling,s1) == 0)
	{
		zifushu(wenjian);
	}
	if(strcmp(mingling,s2) == 0)
	{
		dancishu(wenjian);
	}
	if(strcmp(mingling,s3) == 0)
	{
		juzishu(wenjian);
	}
	fclose(wenjian);
}

void zifushu(FILE *wenjian)
{
	int zifu = 0;
	char c;
	while((c = fgetc(wenjian)) != EOF)
	{
		fputc(c,stdout);
		zifu++;
	}
	printf("\n字符数=%d\n",zifu);
}

void dancishu(FILE *wenjian)
{
	int danci = 1;
	int flag;
	char c;
	while((c = fgetc(wenjian)) != EOF)
	{
		fputc(c,stdout);
		if(c == ' '|| c == '.' || c == '\n')
		{
			flag = 0;
		}
		if(flag == 0 && c != '\n' && c != '.')
		{
			flag = 1;
			danci++;
		}
	}
	printf("\n单词数=%d\n",danci);
}

void juzishu(FILE *wenjian)
{
	int juzi = 0;
	char c;
	while((c = fgetc(wenjian)) != EOF)
	{
		fputc(c,stdout);
		if(c == '.')
		{
			juzi++;
		}
	}
	printf("\n句子数=%d\n",juzi);
}