#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"

typedef char TElemType; // 假设二叉树结点的元素类型为字符

typedef struct  BiTNode
{
	TElemType data; // 数据域
	struct BiTNode *lchild, *rchild; // 左、右孩子指针
} BiTNode, *BiTree; // 二叉链表

typedef enum Status
{
	SUCEESS,
	ERROR
} Status;


Status InitBiTree(BiTree T); // 初始化二叉树
Status DestroyBiTree(BiTree T); // 销毁二叉树
Status CreateBiTree(BiTree T, char* definition); // 构造二叉树
// 以下部分函数定义未指定参数类型
Status PreOrderTraverse(BiTNode T, Status(*visit)(TElemType e)); // 先序遍历
Status InOrderTraverse(BiTNode T, Status(*visit)(TElemType e));	//中序遍历
Status PostOrderTraverse(BiTNode T, Status(*visit)(TElemType e)); //后序遍历
Status LevelOrderTraverse(BiTNode T, Status(*visit)(TElemType e)); //层序遍历
int Value(BiTNode T); // 前缀表达式求值
char InputOperator(); // 输入前缀表达式
void Print(char data);
int Operate(int n1, int n2, char operate); // 运算
