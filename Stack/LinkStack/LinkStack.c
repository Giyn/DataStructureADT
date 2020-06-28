#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

// LinkStack.

StackNode *bottom = NULL;
// LinkStack.
Status initLStack(LinkStack *s)
{
	s->count = 0;
	s->top = (StackNode*)malloc(sizeof(StackNode));
	s->top->data = 1234567890;
	s->top->next = NULL;
	bottom = s->top;
	printf("Successfully initialize the stack.\n");
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)
{
	if (s->count == 0)
    {
        printf("It is empty.\n");
		return SUCCESS;
	}
    printf("Not empty.\n");
    return ERROR;
}

Status getTopLStack(LinkStack *s, ElemType *e)
{
    if(s->top == NULL)
    {
        printf("There is no stack.\n");
        return ERROR;
    }
    *e = s->top->data;
    printf("The top element is %d.\n", *e);
	return SUCCESS;
}

Status clearLStack(LinkStack *s)
{
	StackNode* p = NULL;
	s->count = 0;
	s->top = bottom;
	p = bottom = bottom->next;
	while (p)
	{
		p = bottom->next;
		free(bottom);
		bottom = p;
	}
	printf("Successfully clear the stack.\n");
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)
{
	StackNode* p = NULL;
	s->count = 0;
	s->top = NULL;
	while (p)
	{
		p = bottom->next;
		free(bottom);
		bottom = p;
	}
	printf("Successfully destroy the stack.\n");
	return SUCCESS;
}

Status LStackLength(LinkStack *s, int *length)
{
    if(s->top == NULL)
    {
        printf("There is no stack.\n");
        return ERROR;
    }
	*length = s->count;
	printf("The length of the stack is %d.\n", *length);
	return SUCCESS;
}

Status pushLStack(LinkStack *s, ElemType data)
{
	StackNode * p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = NULL;
	s->top->next = p;
	s->top = p;
	s->count++;
	printf("Successfully push %d to the stack.\n", data);
	return SUCCESS;
}

Status popLStack(LinkStack *s, ElemType *data)
{
	StackNode * p = bottom;
	if (s->count == 0)
    {
		printf("The stack is empty.\n");
		return ERROR;
	}
	else
	{
		*data = s->top->data;
		for (; p; p = p->next) {
			if (p->next == s->top) {
				free(p->next);
				p->next = NULL;
				s->top = p;
				s->count--;
				break;
			}
		}
		printf("Successfully pop %d out the stack.\n", *data);
		return SUCCESS;
	}
}

// 实时打印链栈
Status printStack(LinkStack * s)
{
	StackNode * p = NULL;
	if (s->top == NULL) {
		printf("There is no stack now.\n");
		return ERROR;
	}
	else if (s->count == 0)
    {
		return ERROR;
	}
	for (p = bottom->next; p; p = p->next)
    {
		printf("|%d", p->data);
	}
	printf("\n");
	return SUCCESS;
}

// 输入整数检测
int InputNumber()
{
	int num = 0; // Store converted numbers.
	int status = 0; // Flag status.
	char str[100]; // Receive string.
	do
	{
		scanf("%s", str);
		status = SUCCESS;
		for (int i = 0; str[i] != '\0'; i++)
		{
			// Check for illegal characters.
			if (i == 0)
            {
				if (str[i] == '-' || str[i] == '+')
					continue;
			}
			else
			{
				if (str[i] < '0' || str[i] > '9')
				{
					status = ERROR;
				}
			}
		}
		if (status == ERROR) {
			printf("Illegally input, please input again:");
		}
		else
		{
			int i = 0;
			// Convert string to number.
			for (i = 0, num = 0; str[i] != '\0'; i++)
			{
				if (i == 0)
                {
					if (str[i] == '-' || str[i] == '+')
					{
						continue;
					}
					else
					{
						num *= 10;
						num += (str[i] - 48);
					}
				}
				else
				{
					num *= 10;
					num += (str[i] - 48);
				}
			}
			if (str[0] == '-')
            {
				num = -num;
			}
			// Check if the number entered is out of bounds.
			if (i >= 10)
			{
				printf("Overflow, please input again:");
				status = ERROR;
			}
		}
	} while (status == ERROR);
	return num;
}
