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
		return ERROR;
	DestroyBiTree(T->lchild);
	DestroyBiTree(T->rchild);
	free(T);
	return SUCCESS;
}
//初始条件：二叉树T存在
//操作结果：摧毁二叉树T
Status CreateBiTree(BiTree T, char *definition) //A(B(D(#,#),E(#,#)),C(#,#))
{
	int n = (int)definition[0];
	if (definition[(int)definition[0]] == '\0') 
	{
		return SUCCESS;
	}
	else
	{
		if (T == NULL)
		{
			T = (BiTree)malloc(sizeof(BiTNode));
		}
        T->data = definition[n];
		definition[0]++;
		if (definition[definition[0]] != '#')
		{
			T->lchild = (BiTree)malloc(sizeof(BiTNode));
			CreateBiTree(T->lchild, definition);   //从左至右建树
		} 
		else
		{
			T->lchild = NULL;
			definition[0]++;
		}
		if (definition[definition[0]] != '#')
		{
			T->rchild = (BiTree)malloc(sizeof(BiTNode));
			CreateBiTree(T->rchild, definition);
		}
		else
		{
			T->rchild = NULL;
			definition[0]++;
		}
    }
    return SUCCESS;
}    
//初始条件： definition给出二叉树的定义
//操作结果：按definition构造二叉树T


//以下部分函数定义未指定参数类型
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if (T == NULL)
	{
		return SUCCESS;
	}
    else
    {
        (*visit)(T->data);   //根
        PreOrderTraverse(T->lchild, (*visit));    //左
        PreOrderTraverse(T->rchild, (*visit));    //右
    }
    return SUCCESS;
}

//初始条件：二叉树T存在，visit为对结点的操作的应用函数
//操作结果：先序遍历T，对每个结点调用visit函数一次且仅一次，一旦visit失败，则操作失败
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))	//中序遍历
{
	if(T == NULL)
	{
		return SUCCESS;
	}
    else
    {
		InOrderTraverse(T->lchild, visit);    //左
        (*visit)(T->data);   //根
        InOrderTraverse(T->rchild, visit);    //右
    }
    return SUCCESS;
}
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))	//后序遍历
{
	if(T == NULL)
	{
		return SUCCESS;
	}
    else
    {
		PostOrderTraverse(T->lchild, visit);    //左
        PostOrderTraverse(T->rchild, visit);    //右
		(*visit)(T->data);   //根
    }
    return SUCCESS;
}
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))	//层序遍历
{
	queue<BiTree> q;
    BiTree front;

    if (T == NULL)
		return SUCCESS;

    q.push(T);

    while (!q.empty())
    {
        front = q.front();
        q.pop();

        if (front->lchild)
            q.push(front->lchild);

        if (front->rchild)
            q.push(front->rchild);

        visit(front->data);
    }
	return SUCCESS;	
} 
Status TPrint(TElemType e)
{
	cout<<e<<" ";
	return SUCCESS; 
}
int Value(BiTree T)			//构造出的二叉树求值
{
	jiaqilai = 0;
	char c;
	PreOrderTraverse(T, ganta);
	return jiaqilai;
}
Status ganta(TElemType e)
{
	jiaqilai += e - '0';
	return SUCCESS; 
} 
/*
提示：可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
可根据需要自行增加操作.
*/

