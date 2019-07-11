#pragma once

//文件操作的关键点在于
//凡事涉及到对文件进行操作的功能
//一律都在内存中进行
//包括增删改
//操作之前先将文件中的东西初始化到内存，
//操作完之后再将内存中的东西写入文件
//直接覆盖原来文件中的内容

void InitP();//初始化，将文件中的内容读出到内存并解密
void SaveP();//将内存中的数据加密并写入文件
void ShowAll();//显示所有
void AddP();//增
int FindP();//查
void DeleteP();//删
void AlertP();//改
void MenuP();//菜单