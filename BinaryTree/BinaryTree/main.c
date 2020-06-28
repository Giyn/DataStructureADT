#pragma once
#include"BinaryTree.h"
#include<stdio.h>

int main()
{
	int choice = 0;
	BiTree T = malloc(sizeof(BiTNode));
	T->data = NULL;
	Status status = ERROR;
	do {
		system("cls");
		printf("\n\n");
		printf("  <前缀表达式构造二叉树>  \n");
		printf("--------------------------\n");
		printf(">>> 1.初始化二叉树\n");
		printf(">>> 2.销毁二叉树\n");
		printf(">>> 3.先序遍历\n");
		printf(">>> 4.中序遍历\n");
		printf(">>> 5.后序遍历\n");
		printf(">>> 6.层次遍历\n");
		printf(">>> 7.前缀表达式求值\n");
		printf(">>> 8.退出程序\n");
		printf("--------------------------\n");
		printf("\n请选择你想进行的操作:");
		char opr;
		switch (InputNumber())
		{
		case 1:
			printf("请输入前缀表达式(例:+1-32):");
			status = InitBiTree(T);
			break;
		case 2:
			status = DestroyBiTree(T);
			if (status == SUCEESS)
            {
				printf("成功销毁二叉树\n");
				T = malloc(sizeof(BiTNode));
				T->data = NULL;
			}
			break;
		case 3:
			status = PreOrderTraverse(*T, &Print);
			printf("\n");
			break;
		case 4:
			status = InOrderTraverse(*T, &Print);
			printf("\n");
			break;
		case 5:
			status = PostOrderTraverse(*T, &Print);
			printf("\n");
			break;
		case 6:
			status = LevelOrderTraverse(*T, &Print);
			printf("\n");
			break;
		case 7:
			if (T->data == NULL)
            {
				printf("未初始化\n");
				break;
			}
			printf("表达式的值为: %d\n", Value(*T));
			break;
		case 8:
			printf("\nByeBye~");
			exit(0);
			break;
		default:
			printf("无此选项\n");
		}
        system("pause");
	} while (1);
}
