#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"

typedef char TElemType; // �������������Ԫ������Ϊ�ַ�

typedef struct  BiTNode
{
	TElemType data; // ������
	struct BiTNode *lchild, *rchild; // ���Һ���ָ��
} BiTNode, *BiTree; // ��������

typedef enum Status
{
	SUCEESS,
	ERROR
} Status;


Status InitBiTree(BiTree T); // ��ʼ��������
Status DestroyBiTree(BiTree T); // ���ٶ�����
Status CreateBiTree(BiTree T, char* definition); // ���������
// ���²��ֺ�������δָ����������
Status PreOrderTraverse(BiTNode T, Status(*visit)(TElemType e)); // �������
Status InOrderTraverse(BiTNode T, Status(*visit)(TElemType e));	//�������
Status PostOrderTraverse(BiTNode T, Status(*visit)(TElemType e)); //�������
Status LevelOrderTraverse(BiTNode T, Status(*visit)(TElemType e)); //�������
int Value(BiTNode T); // ǰ׺���ʽ��ֵ
char InputOperator(); // ����ǰ׺���ʽ
void Print(char data);
int Operate(int n1, int n2, char operate); // ����
