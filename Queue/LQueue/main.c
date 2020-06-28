#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"

int main()
{
    int data_size = 0;
    int e = 0, n = 0;
    LQueue *q;
    int flag = 0;
    q = (void*)malloc(sizeof(LQueue));
    q->front = q->rear = NULL;
    q->length = 0;
    while(1)
    {
        system("cls");
        printf("                 \n");
        printf("                 \n");
        printf("-----------------\n");
        printf(">>> 1.Initialize \n");
        printf(">>> 2.EnLQueue   \n");
        printf(">>> 3.DeLQueue   \n");
        printf(">>> 4.Clear      \n");
        printf(">>> 5.Destory    \n");
        printf(">>> 6.Length     \n");
        printf(">>> 7.isEmpty    \n");
        printf(">>> 8.GetHead    \n");
        printf(">>> 9.Traverse   \n");
        printf(">>> 10.Exit      \n");
        printf("-----------------\n");
        if(flag)
        {
            TraverseLQueue(q, &LPrint);
        }
        else
        {
            printf("No queue now.");
        }
        printf("\n-----------------\n");
        printf("Input a choice you want:");
        switch (InputNumber())
		{
		case 1:
            InitLQueue(q);
            flag = 1;
			break;
        case 2:
            if(q->front == NULL)
            {
                printf("Now there is no queue.\n");
                break;
            }
            else
            {
                printf("Input data:");
                void *e = NULL;
                e = (void*)malloc(data_size);
                InputData(e);
                EnLQueue(q, e);
            }
            break;
		case 3:
			if(q->front == NULL)
            {
				printf("Now there is no queue.\n");
				break;
			}
			else if(IsEmptyLQueue(q))
            {
				printf("Now the queue is empty.\n");
			}
			else
			{
				DeLQueue(q);
			}
			break;
		case 4:
			if(q->front == NULL)
            {
				printf("Now there is no queue.\n");
				break;
			}
			else
			{
				if(IsEmptyLQueue(q))
				{
					printf("Now the queue is empty.\n");
				}
				else
				{
					ClearLQueue(q);
					printf("Successfully clear the queue.\n");
				}
			}
			break;
		case 5:
			if(q->front == NULL)
            {
				printf("Now there is no queue.\n");
				break;
			}
			else
			{
				DestoryLQueue(q);
				flag = 0;
				printf("Successfully destroy the queue.\n");
			}
			break;
		case 6:
			if(q->front == NULL)
            {
				printf("Now there is no queue.\n");
				break;
			}
			else
			{
				n = LengthLQueue(q);
				printf("The length of the queue is %d.\n", n);
			}
			break;
		case 7:
			if(q->front == NULL)
            {
				printf("Now there is no queue.\n");
				break;
			}
			else
			{
				if(IsEmptyLQueue(q))
				{
					printf("It is empty.\n");
				}
				else
				{
					printf("It is not empty.\n");
				}
			}
			break;
		case 8:
			if(q->front == NULL)
            {
				printf("Now there is no queue.\n");
				break;
			}
			else
			{
				if(IsEmptyLQueue(q))
				{
					printf("Now the queue is empty.\n");
				}
				else
				{
					GetHeadLQueue(q, &e);
					printf("The head of queue is ");
					LPrint(&e);
					printf(".\n");
				}
			}
			break;
        case 9:
            TraverseLQueue(q, &LPrint);
            printf("\n");
            break;
		case 10:
			printf("\nByeBye~");
			exit(0);
			break;
		default:
			printf("No such choice.\n");
		}
		system("pause");
    }
}
