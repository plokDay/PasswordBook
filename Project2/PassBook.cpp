#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"ctrl.h"
//功能：增删改查显示所有；加密写入文件；打开密码本也需要输入密码
int main(void)
{
	int nSec = 1;
	while (nSec)
	{
		char cKey[7] = { 0 };
		printf("请输入密码:\n");
		scanf_s("%s", cKey, 7);
		if (!strcmp(cKey, "123456"))
			nSec = 0;
		else
			printf("密码错误，请重新输入\n");
		system("cls");
		getchar();
	}	
	MenuP();

	return 0;
}