#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "data.h"
#include "ctrl.h"

char cWeb[MAX][CHM];
char cUser[MAX][CHM];
char cPwd[MAX][CHM];
char cNote[MAX][CHM];
int gCount = 0;

void ShowAll()
{
	InitP();
	printf("共%d条记录\n------------------------------------------\n", gCount);
	for (int i = 0; i < gCount; i++)
	{
		printf("第%d条记录：\n-------------------------------------------\n", i + 1);
		printf("站点：%s\n用户名：%s\n密码：%s\n备注：%s\n", cWeb[i], cUser[i], cPwd[i], cNote[i]);
		printf("-------------------------------------------\n");
	}


	system("pause");
}
void AddP()
{
	InitP();
	printf("请输入目标站点、用户名、密码、备注信息\n");
	scanf_s("%s %s %s %s", cWeb[gCount], CHM, cUser[gCount], CHM, cPwd[gCount], CHM, cNote[gCount], CHM);
	gCount++;
	SaveP();
	printf("添加成功\n");
}
int FindP()
{
	InitP();
	printf("请输入站点名：\n");
	char cKey[CHM];//关键字
	scanf_s("%s", cKey, CHM);
	int nFd = -1;
	for (int i = 0; i < gCount; i++)
	{
		if (!strcmp(cKey, cWeb[i]))
		{
			nFd = i;
			break;
		}
	}
	if (nFd == -1)
		printf("没有找到\n");
	else
	{
		printf("第%d条符合：\n", nFd + 1);
		printf("-------------------------------------------\n");
		printf("站点名：%s\n用户名：%s\n密码：%s\n备注：%s\n", cWeb[nFd], cUser[nFd], cPwd[nFd], cNote[nFd]);
	}
	return nFd;
}
void DeleteP()
{
	int nIdx = FindP();
	if (nIdx == -1)
		printf("无法删除\n");
	else
	{
		for (int i = nIdx; i < gCount - 1; i++)
		{
			strcpy_s(cWeb[i], CHM, cWeb[i + 1]);
			strcpy_s(cUser[i], CHM, cUser[i + 1]);
			strcpy_s(cPwd[i], CHM, cPwd[i + 1]);
			strcpy_s(cNote[i], CHM, cNote[i + 1]);
		}
		gCount--;

		SaveP();
		printf("删除成功\n");
	}
	system("pause");
}
void AlertP()
{
	int nIdx = FindP();
	if (nIdx == -1)
		printf("无法删除\n");
	else
	{
		printf("-------------------------------------------\n");
		printf("请输入新的用户名、密码、备注\n");
		scanf_s("%s %s %s", cUser[nIdx], CHM, cPwd[nIdx], CHM, cNote[nIdx], CHM);
		SaveP();
		printf("修改成功\n");
	}
	system("pause");
}