#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include "./head/BinaryTree.h"
#include "./head/tool.h"
using namespace std;

int main()
{
	bool dd;
	int d, n, zz = -1; //zz -1 退出
	BiTree T;
	char *definition;
	TElemType c;
	while(1)
	{
		dd = 0;
		system("cls");//++2*3-74/84
		cout<<"*************************************"<<endl;
		cout<<"*******欢迎来到前缀表达式计算器******"<<endl;
		cout<<"*        前缀表达式的格式如下       *"<<endl;
		cout<<"*    例：1+2+3 前缀表达式：++123    *"<<endl;
		cout<<"*************************************"<<endl;
		cout<<"*          1.开始计算               *"<<endl;
		cout<<"*          2.退出                   *"<<endl;
		cout<<"*************************************"<<endl;
		cout<<"*          输入数字来选取           *"<<endl;
		cout<<"*************************************"<<endl;
		if (SHURU(&d))//检测输入是否合法 
		{
			error_();
			dd = 1;
		} 
		if (d > 2 || d < 1)
		{
			error_();
			dd = 1;
		}
		if (dd == 1)//出错 重新开始 
		{
			continue;
		} 	
		if (d == 2)
		{
			break;
		}
		
		if (zz == 1)
		{
			DestroyBiTree(T);
		}
		InitBiTree(T);
		T = (BiTree)malloc(sizeof(BiTNode));
		T->lchild = NULL;
		T->rchild = NULL;
		zz = 1;
		
		definition = (char *)malloc(sizeof(char)*2001);
		memset(definition, 0, sizeof(definition));
		cout<<"请输入前缀表达式"<<endl;
		scanf(" %s",definition+1);
		definition[0] = 1;
		
		CreateBiTree(T, definition);
	//	cout<<"*************************************"<<endl;
	//	PreOrderTraverse1(T);
		cout<<endl;
		cout<<"结果为：";
		printf("%lf\n", Value(T));
	//	break;
		system("pause");
	} 
	system("pause"); 
	return 0;
}
