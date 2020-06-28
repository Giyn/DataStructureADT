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
		printf("  <ǰ׺���ʽ���������>  \n");
		printf("--------------------------\n");
		printf(">>> 1.��ʼ��������\n");
		printf(">>> 2.���ٶ�����\n");
		printf(">>> 3.�������\n");
		printf(">>> 4.�������\n");
		printf(">>> 5.�������\n");
		printf(">>> 6.��α���\n");
		printf(">>> 7.ǰ׺���ʽ��ֵ\n");
		printf(">>> 8.�˳�����\n");
		printf("--------------------------\n");
		printf("\n��ѡ��������еĲ���:");
		char opr;
		switch (InputNumber())
		{
		case 1:
			printf("������ǰ׺���ʽ(��:+1-32):");
			status = InitBiTree(T);
			break;
		case 2:
			status = DestroyBiTree(T);
			if (status == SUCEESS)
            {
				printf("�ɹ����ٶ�����\n");
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
				printf("δ��ʼ��\n");
				break;
			}
			printf("���ʽ��ֵΪ: %d\n", Value(*T));
			break;
		case 8:
			printf("\nByeBye~");
			exit(0);
			break;
		default:
			printf("�޴�ѡ��\n");
		}
        system("pause");
	} while (1);
}
