#pragma once
#include"BinaryTree.h"
#include<stdbool.h>

bool isInited = false; // 初始化标志


// 初始化二叉树
Status InitBiTree(BiTree T)
{
	char n = InputOperator();
	CreateBiTree(T, &n);
	isInited = true;
	printf("\n成功创建二叉树\n");
	return SUCEESS;
}

// 摧毁二叉树
Status DestroyBiTree(BiTree T)
{
	if (T->data==NULL)
	{
		printf("未初始化\n");
		return ERROR;
	}
	if (T->lchild)
	{
		DestroyBiTree(T->lchild);
		T->lchild = NULL;
	}
	if (T->rchild)
	{
		DestroyBiTree(T->rchild);
		T->rchild = NULL;
	}
	if (T != NULL)
	{
		free(T);
		T = NULL;
	}
	isInited = false;
	return SUCEESS;
}

// 先序构造二叉树
Status CreateBiTree(BiTree T, char* definition)
{
	T->data = *definition; // 利用definition指针构造表达式
	if (T->data >= 48 && T->data <= 57)
    {
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else
	{
		T->lchild = (BiTNode*)malloc(sizeof(BiTNode));
		T->rchild = (BiTNode*)malloc(sizeof(BiTNode));
		char n;
		n = InputOperator(); // 输入表达式
		CreateBiTree(T->lchild, &n);
		n = InputOperator();
		CreateBiTree(T->rchild, &n);
	}
}

// 先序遍历
Status PreOrderTraverse(BiTNode T, Status(*visit)(TElemType e))
{
	if (T.data == NULL)
    {
		printf("未初始化\n");
		return ERROR;
	}
	visit(T.data);
	if (T.lchild != NULL)
	{
		PreOrderTraverse(*(T.lchild), visit);
	}
	if (T.rchild != NULL)
	{
		PreOrderTraverse(*(T.rchild), visit);
	}
}

// 中序遍历
Status InOrderTraverse(BiTNode T, Status(*visit)(TElemType e))
{
	if (T.data == NULL)
    {
		printf("未初始化\n");
		return ERROR;
	}
	if (T.lchild != NULL)
	{
		InOrderTraverse(*(T.lchild), visit);
	}
	visit(T.data);
	if (T.rchild != NULL)
	{
		InOrderTraverse(*(T.rchild), visit);
	}
}

// 后序遍历
Status PostOrderTraverse(BiTNode T, Status(*visit)(TElemType e))
{
	if (T.data == NULL)
    {
		printf("未初始化\n");
		return ERROR;
	}
	if (T.lchild != NULL)
	{
		PostOrderTraverse(*(T.lchild), visit);
	}
	if (T.rchild != NULL)
	{
		PostOrderTraverse(*(T.rchild), visit);
	}
	visit(T.data);
}

// 层序遍历
Status LevelOrderTraverse(BiTNode T, Status(*visit)(TElemType e))
{
	if (T.data == NULL)
    {
		printf("未初始化\n");
		return ERROR;
	}
	LQueue Q;
	BiTNode t;
	Q.front = Q.rear = NULL;
	Q.length = 0;
	InitLQueue(&Q);
	EnLQueue(&Q, &T); // 根节点入队
	while (!IsEmptyLQueue(&Q))
	{
		GetHeadLQueue(&Q, &t);
		DeLQueue(&Q);
		visit(t.data); // 访问结点
		if (t.lchild != NULL)
		{
		    EnLQueue(&Q, t.lchild); // 入队
		}
		if (t.rchild != NULL)
        {
            EnLQueue(&Q, t.rchild); // 入队
        }
	}
}
// 计算前缀表达式的值
int Value(BiTNode T)
{

	if (T.data >= 48 && T.data <= 57)
    {
		return T.data-48;
	}
	return Operate(Value(*T.lchild), Value(*T.rchild), T.data);
}

void Print(char data)
{
	printf("%c", data);
}

int Operate(int n1, int n2, char operate)
{
	int result = 0;
	switch (operate)
	{
	case '+':
		result = n1 + n2;
		break;
	case '-':
		result = n1 - n2;
		break;
	case '*':
		result = n1 * n2;
		break;
	case '/':
		if (n2 == 0)
		{
			printf("分母不能为0\n");
			return 0;
		}
		else
        {
            result = n1/n2;
        }
		break;
	}
	return result;
}

/**
 *  @name        : InputNumber
 *	@description : to input a checked number
 *	@param		 : none
 *	@return		 : int
 *  @notice      : None
 */
int InputNumber()
{
	typedef enum
	{
		FALSE = 0,
		TRUE = 1
	} Status;

	int n = 0;
	int num = 0; // 存放输入数字
	int status = 0; // 标志状态
	do
	{
		status = TRUE;
		n = scanf("%d", &num, 4);
		if (getchar() != '\n')
        {
			for (; getchar() != '\n';);
			printf("非法输入,请再次尝试:");
			status = FALSE;
		}
	} while (status == FALSE);
	return num;
}

/**
 *  @name        : InputOperator
 *	@description : to input a checked operator
 *	@param		 : none
 *	@return		 : char
 *  @notice      : None
 */
char InputOperator()
{
	char n;
	Status status = TRUE;
	do
	{
		status = TRUE;
		n = getch();
		if ((n < 47 || n>58) && n != '+' &&n != '-' && n != '*' && n != '/')
        {
			status = FALSE;
		}
	} while (status == FALSE);
	printf("%c", n);
	return n;
}
