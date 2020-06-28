#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

int main()
{
    int flag = 0; // There is no stack.
    SqStack *head = (SqStack*)malloc(sizeof(SqStack)); // Top pointer.
    head->elem = NULL;
    head->size = head->top = 0;
    while(1)
    {
        system("cls");
        printf("                 \n");
        printf("                 \n");
        printf("-----------------\n");
        printf(">>> 1.Initialize \n");
        printf(">>> 2.Push       \n");
        printf(">>> 3.Pop        \n");
        printf(">>> 4.Clear      \n");
        printf(">>> 5.Destroy    \n");
        printf(">>> 6.Length     \n");
        printf(">>> 7.isEmpty    \n");
        printf(">>> 8.getTop     \n");
        printf(">>> 9.Exit       \n");
        printf("-----------------\n");
        printStack(head);
        printf("-----------------\n");
        printf("Input a choice you want:");
        switch(InputNumber())
        {
            case 1:
                {
                    head = (SqStack*)malloc(sizeof(SqStack));
                    printf("Input the length of stack:");
                    initStack(head, InputNumber());
                }
                flag = 1;
                break;
            case 2:
                if(flag == 1)
                {
                    printf("Input the data to be push:");
                    pushStack(head, InputNumber());
                }
                else
                {
                    printf("Now there is no stack.\n");
                }
                break;
            case 3:
                if(flag == 1)
                {
                    ElemType *e = (ElemType*)malloc(sizeof(ElemType));
                    popStack(head, e);
                }
                else
                {
                    printf("Now there is no stack.\n");
                }
                break;
            case 4:
                if(flag == 1)
                {
                    clearStack(head);
                }
                else
                {
                    printf("Now there is no stack.\n");
                }
                break;
            case 5:
                if(flag == 1)
                {
                    destroyStack(head);
                    flag = 0;
                }
                else
                {
                    printf("Now there is no stack.\n");
                }
                break;
            case 6:
                {
                    int *length = (int*)malloc(sizeof(int));
                    stackLength(head, length);
                }
                break;
            case 7:
                if(flag == 1)
                {
                    isEmptyStack(head);
                }
                else
                {
                    printf("Now there is no stack.\n");
                }
                break;
            case 8:
                if(flag == 1)
                {
                    ElemType *e = (ElemType*)malloc(sizeof(ElemType));
                    getTopStack(head, e);
                }
                else
                {
                    printf("Now there is no stack.\n");
                }
                break;
            case 9:
                printf("\nByeBye~");
                exit(0);
                break;
            default:
                printf("No such option.\n");
        }
        system("pause");
    }
    return 0;
}
