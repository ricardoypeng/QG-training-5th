#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include "./head/BinaryTree.h"
using namespace std;
/*
typedef char TElemType;     // 假设二叉树结点的元素类型为字符

typedef struct  BiTNode {
    TElemType      data;     // 数据域
    struct BiTNode  *lchild,*rchild;  // 左、右孩子指针
} BiTNode, *BiTree;   // 二叉链表

typedef enum Status{
	SUCEESS
	ERROR
}Status;

*/
int jiaqilai;
Status InitBiTree(BiTree T)
{
	T = NULL;
	return SUCCESS;
}
//操作结果：构造空二叉树T
Status DestroyBiTree(BiTree T)
{
	if (T->lchild == NULL && T->rchild == NULL) 
	{
		free(T); 
		return SUCCESS;
	} 
	DestroyBiTree(T->lchild);
	DestroyBiTree(T->rchild);
	free(T);
	return SUCCESS;
}
//初始条件：二叉树T存在
//操作结果：摧毁二叉树T
Status CreateBiTree(BiTree T, char *definition) //A(B(D(#,#),E(#,#)),C(#,#))
{
	if (definition[definition[0]] == '\0')
	{
		return SUCCESS;
	}
	int n = (int)definition[0];
    T->data = definition[n];
//	cout<<T->data<<endl;
	definition[0]++;
	
//	cout<<"next l is:"<<definition[definition[0]]<<endl;
	if (definition[definition[0]] >= '0' && definition[definition[0]] <= '9')
	{				
		T->lchild = (BiTree)malloc(sizeof(BiTNode));
		T->lchild->data = definition[definition[0]];
		T->lchild->lchild = NULL;
		T->lchild->rchild = NULL;
		definition[0]++;
		if (definition[definition[0]] == '\0')
		{
			return SUCCESS;
		}
	} 
	else
	{
		if (definition[definition[0]] == '+' || definition[definition[0]] == '-' || definition[definition[0]] == '*' || definition[definition[0]] == '/')
		{
//			cout<<"yunsuan "<<definition[definition[0]]<<endl;
			T->lchild = (BiTree)malloc(sizeof(BiTNode));
			CreateBiTree(T->lchild, definition);
		} 
//		else
//		{
//			cout<<"eeeerrrrrrrrrrrrrroooooooooooooorrrrrrrrrrr"<<endl;
//		}
	}
//	cout<<"1 next l is:"<<T->lchild->data<<endl;
	
//	cout<<" next r is:"<<definition[definition[0]]<<endl;
	if (definition[definition[0]] >= '0' && definition[definition[0]] <= '9')
	{
//		cout<<"shuzi "<<T->data<<endl;
		T->rchild = (BiTree)malloc(sizeof(BiTNode));
		T->rchild->data = definition[definition[0]];
		T->rchild->lchild = NULL;
		T->rchild->rchild = NULL;
		definition[0]++;
		if (definition[definition[0]] == '\0')
		{
			return SUCCESS;
		}
	}
	else
	{
//		cout<<"yunsuan "<<definition[definition[0]]<<endl;
		T->rchild = (BiTree)malloc(sizeof(BiTNode));
		CreateBiTree(T->rchild, definition);
	}
//	cout<<" 1next r is:"<<T->rchild->data<<endl;
//	cout<<": l is:"<<T->lchild->data<<" r is:"<<T->rchild->data<<endl;
    return SUCCESS;
}
//初始条件： definition给出二叉树的定义
//操作结果：按definition构造二叉树T


//以下部分函数定义未指定参数类型
Status PreOrderTraverse(BiTree T, double *d)
{
//	cout<<"fuckingdata "<<T<<"    :   "<<T->data<<endl;
//	cout<<"now is :";
//	cout<<T->data<<endl;
	double i, j, k;
	if (T->data >= '0' && T->data <= '9')
	{
//		cout<<"T->data:";
//		cout<<T->data<<endl;
		*d = (double)((int)T->data - '0');
        return SUCCESS;
	}
    else
    {
//		cout<<"??"<<endl;
    	if (T->data == '+')
    	{
//   		cout<<"+left"<<endl;
 //   		cout<<T->lchild->data<<endl;
    		PreOrderTraverse(T->lchild, &i);
//    		cout<<"+right"<<endl;
    		PreOrderTraverse(T->rchild, &j);
//    		cout<<i<<"+"<<j<<"="<<i + j<<endl;
    		*d = i + j;
    		return SUCCESS;
		}
		if (T->data == '-')
    	{
 //   		cout<<"-left"<<endl;
    		PreOrderTraverse(T->lchild, &i);
 //   		cout<<"-right"<<endl;
    		PreOrderTraverse(T->rchild, &j);
 //   		cout<<i<<"-"<<j<<"="<<i - j<<endl;
    		*d = i - j;
    		return SUCCESS;
		}
		if (T->data == '*')
    	{
 //   		cout<<"*left"<<endl;
    		PreOrderTraverse(T->lchild, &i);
 //   		cout<<"*right"<<endl;
    		PreOrderTraverse(T->rchild, &j);
 //   		cout<<i<<"*"<<j<<"="<<i * j<<endl;
    		*d = i * j;
    		return SUCCESS;
		}
		if (T->data == '/')
    	{
  //  		cout<<"/left"<<endl;
    		PreOrderTraverse(T->lchild, &i);
  //  		cout<<"/right"<<endl;
    		PreOrderTraverse(T->rchild, &j);
 //   		cout<<i<<"/"<<j<<"="<<i / j<<endl;
    		*d = i / j;
    		return SUCCESS;
		}
    }
}
double Value(BiTree T)			//构造出的二叉树求值
{
	double n = 0;
	PreOrderTraverse(T, &n);
	return n;
}
Status TPrint(TElemType e)
{
	cout<<e<<" ";
	return SUCCESS; 
}
/*
提示：可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
可根据需要自行增加操作.
*/

