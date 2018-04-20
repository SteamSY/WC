#include<io.h>
#include<stdio.h>
#include<string.h>
void zifushu(FILE *wenjian);
void dancishu(FILE *wenjian);
void juzishu(FILE *wenjian);
void daimahangshu(FILE *wenjian);
void konghangshu(FILE *wenjian);
void zhushihangshu(FILE *wenjian);

void main()
{
	FILE *wenjian;
	wenjian = fopen("c:\\WC\\TXT\\wenben.txt","r");
	char mingling[100];
	char s1[100] = "wc.exe-c file.txt";
	char s2[100] = "wc.exe-w file.txt";
	char s3[100] = "wc.exe-s file.txt";
	char s4[100] = "wc.exe-d file.txt";
	char s5[100] = "wc.exe-k file.txt";
	char s6[100] = "wc.exe-z file.txt";
	printf("请输入计数指令:");
	gets(mingling);
	while(1)
	{
		if(strcmp(mingling,s1) == 0)
		{
			zifushu(wenjian);
			break;
		}
		if(strcmp(mingling,s2) == 0)
		{
			dancishu(wenjian);
			break;
		}
		if(strcmp(mingling,s3) == 0)
		{
			juzishu(wenjian);
			break;
		}
		if(strcmp(mingling,s4) == 0)
		{
			daimahangshu(wenjian);
			break;
		}
		if(strcmp(mingling,s5) == 0)
		{
			konghangshu(wenjian);
			break;
		}
		if(strcmp(mingling,s6) == 0)
		{
			zhushihangshu(wenjian);
			break;
		}
		if(strcmp(mingling,s1) != 0 && strcmp(mingling,s2) != 0 && strcmp(mingling,s3) != 0)
		{
			printf("请重新输入正确计数指令:");
			gets(mingling);
		}
	}
	fclose(wenjian);
}

void daimahangshu(FILE *wenjian)
{
	int daimahang = 0;
	char c;
	while((c = fgetc(wenjian)) != EOF)
	{
		fputc(c,stdout);
		if(c == '\n')
		{
			daimahang++;
		}
	}
	printf("\n代码行数=%d\n",daimahang);
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

void konghangshu(FILE *wenjian)
{
	int konghang = 0;
	int flag = 1;
	char c;
	while((c = fgetc(wenjian)) != EOF)
	{
		fputc(c,stdout);
		if(c == '\n')
		{
			flag++;
			if(flag >= 2)
			{
				konghang++;
			}
		}	
		else
		{
			flag = 0;
		}
	}
	if(flag >= 2)
	{
		konghang++;
	}
	printf("\n空行数=%d\n",konghang);
}

void zhushihangshu(FILE *wenjian)
{
	int zhushihang = 0;
	int flag = 0;
	char c;
	while((c = fgetc(wenjian)) != EOF)
	{
		if(c == '/')
		{
			flag++;
		}
		if(c == '*')
		{
			flag++;
		}
		if(flag >= 4)
		{
			zhushihang++;
			flag = 0;
		}
	}
	printf("\n注释行数=%d\n",zhushihang);
}
