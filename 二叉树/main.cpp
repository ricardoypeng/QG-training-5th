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
	char definition[2001];
	TElemType c;
	while(1)
	{
		dd = 0;
		system("cls");
		cout<<"*************************************"<<endl;
		cout<<"*********欢迎来到二叉树的练习********"<<endl;
		cout<<"*        构造二叉树的格式如下       *"<<endl;
		cout<<"*          124##5##36##7##          *"<<endl;
		cout<<"*************************************"<<endl;
		cout<<"*          1.创建空二叉树           *"<<endl;
		cout<<"*          2.摧毁二叉树             *"<<endl;
		cout<<"*          3.构造二叉树             *"<<endl;
		cout<<"*          4.先序遍历               *"<<endl;
		cout<<"*          5.中序遍历               *"<<endl;
		cout<<"*          6.后序遍历               *"<<endl;
		cout<<"*          7.层序遍历               *"<<endl;	
		cout<<"*          8.树的值                 *"<<endl;
		cout<<"*          9.退出                   *"<<endl;
		cout<<"*************************************"<<endl;
		cout<<"*          输入数字来选取           *"<<endl;
		cout<<"*************************************"<<endl;
		if (SHURU(&d))//检测输入是否合法 
		{
			error_();
			dd = 1;
		}
		if (dd == 1)//出错 重新开始 
		{
			continue;
		} 	
		if (d == 9)
		{
			break;
		}
		switch (d)
		{
			case 1 :
			{
				if (zz == 1)
				{
					DestroyBiTree(T);
				}
				InitBiTree(T);
				T = (BiTree)malloc(sizeof(BiTNode));
				T->lchild = NULL;
				T->rchild = NULL;
				cout<<"已初始化"<<endl; 
				zz = 0;
				system("pause");
				break; 
			} 
			
			case 2 :
			{
				if (zz == 0)
				{
					T = NULL;
					zz = -1;
					cout<<"已摧毁"<<endl;
					system("pause");
					break;
				}
				if (zz == -1)
				{
					cout<<"都没有怎么摧毁"<<endl; 
					system("pause");
					break;
				}
				if (zz == 1)
				{
					DestroyBiTree(T);
					cout<<"已摧毁"<<endl;
					zz = -1;
					system("pause");
					break;
				}
			} 
			
			case 3 :
			{
				if (zz != 0)
				{
					cout<<"请先初始化"<<endl;
					system("pause");
					break; 
				}
				memset(definition, 0, sizeof(definition));
				cin>>definition+1;
				definition[0] = 1;
				CreateBiTree(T, definition);
				zz = 1;
				system("pause");
				break; 
			} 
			
			case 4 :
			{
				if (zz == -1)
				{
					cout<<"请先初始化"<<endl;
					system("pause");
					break; 
				}
				if (zz == 0)
				{
					cout<<"树是空的"<<endl;
					system("pause");
					break; 
				}
				PreOrderTraverse(T, TPrint);
				cout<<endl;
				system("pause");
				break; 
			} 
			
			case 5 :
			{
				if (zz == -1)
				{
					cout<<"请先初始化"<<endl;
					system("pause");
					break; 
				}
				if (zz == 0)
				{
					cout<<"树是空的"<<endl;
					system("pause");
					break; 
				}
				InOrderTraverse(T, TPrint);
				cout<<endl;
				system("pause");
				break; 
			} 
			
			case 6 :
			{
				if (zz == -1)
				{
					cout<<"请先初始化"<<endl;
					system("pause");
					break; 
				}
				if (zz == 0)
				{
					cout<<"树是空的"<<endl;
					system("pause");
					break; 
				}
				PostOrderTraverse(T, TPrint);
				cout<<endl;
				system("pause");
				break; 
			} 
			
			case 7 :
			{
				if (zz == -1)
				{
					cout<<"请先初始化"<<endl;
					system("pause");
					break; 
				}
				if (zz == 0)
				{
					cout<<"树是空的"<<endl;
					system("pause");
					break; 
				}
				LevelOrderTraverse(T, TPrint);
				cout<<endl; 
				system("pause");
				break; 
			} 
			
			case 8 :
			{
				if (zz == -1)
				{
					cout<<"请先初始化"<<endl;
					system("pause");
					break; 
				}
				if (zz == 0)
				{
					cout<<"树是空的"<<endl;
					system("pause");
					break; 
				}
				cout<<"总数为：" ; 
				cout<<Value(T)<<endl;
				system("pause");
				break; 
			} 
			
			default :
			{
				error_();
				break;
			}
		}
	}
	system("pause"); 
	return 0;
}
