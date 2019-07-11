#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "data.h"
#include "ctrl.h"
//采用异或加密，每个字符都异或5
//将文件中的内容读出到内存并解密
void InitP()
{
	FILE *pFile = nullptr;

	//1.打开
	if (fopen_s(&pFile, "pwd.txt", "ab+"))	//rb+既能读也能写，用w会被覆盖，用r不能从0开始加
		printf("失败\n");
	//读取并解密
	fseek(pFile, 0, SEEK_END);
	int n = ftell(pFile);
	gCount = n / 400;
	fseek(pFile, 0, SEEK_SET);
	for (int i = 0; i < gCount; i++)
	{
		fread(cWeb[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cWeb[i][j] ^= 5;
		}
		fread(cUser[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cUser[i][j] ^= 5;
		}
		fread(cPwd[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cPwd[i][j] ^= 5;
		}
		fread(cNote[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cNote[i][j] ^= 5;
		}
	}
	//3.关闭
	fclose(pFile);
}
//将内存中的数据加密并写入文件
void SaveP()
{
	FILE *pFile = nullptr;
	//1.打开
	if (fopen_s(&pFile, "pwd.txt", "wb+"))
		printf("失败\n");
	//2.加密写入
	for (int i = 0; i < gCount; i++)
	{
		for (int j = 0; j < CHM; j++)
		{
			cWeb[i][j] ^= 5;

		}
		fwrite(cWeb[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cUser[i][j] ^= 5;

		}
		fwrite(cUser[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cPwd[i][j] ^= 5;

		}
		fwrite(cPwd[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cNote[i][j] ^= 5;

		}
		fwrite(cNote[i], CHM, 1, pFile);
	}
	//3.关闭
	fclose(pFile);
}