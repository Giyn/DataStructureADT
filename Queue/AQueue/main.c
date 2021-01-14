/**
 * @filename main.c
 * @description AQueue test file
 * @author 许继元
 * @date 2020/4/24
 */

#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"

int main() {
    int data_size = 0;
    int e = 0, n = 0;
    AQueue *q;
    int flag = 0;
    q = (void *) malloc(sizeof(AQueue));
    q->front = q->rear = NULL;
    q->length = 0;
    q->data[0] = NULL;
    while (1) {
        system("cls");
        printf("                 \n");
        printf("                 \n");
        printf("-----------------\n");
        printf(">>> 1.Initialize \n");
        printf(">>> 2.EnAQueue   \n");
        printf(">>> 3.DeAQueue   \n");
        printf(">>> 4.Clear      \n");
        printf(">>> 5.Destroy    \n");
        printf(">>> 6.Length     \n");
        printf(">>> 7.isEmpty    \n");
        printf(">>> 8.isFull     \n");
        printf(">>> 9.GetHead    \n");
        printf(">>> 10.Traverse  \n");
        printf(">>> 11.Exit      \n");
        printf("-----------------\n");
        if (flag) TraverseAQueue(q, &APrint);
        else printf("No queue now.");
        printf("\n-----------------\n");
        printf("Input a choice you want:");
        switch (InputNumber()) {
            case 1:
                InitAQueue(q);
                flag = 1;
                break;
            case 2:
                if (q->data[0] == NULL) {
                    printf("Now there is no queue.\n");
                    break;
                } else {
                    printf("Input data:");
                    void *e = NULL;
                    e = (void *) malloc(data_size);
                    InputData(e);
                    EnAQueue(q, e);
                    printf("Successfully enter the queue.\n");
                }
                break;
            case 3:
                if (q->data[0] == NULL) {
                    printf("Now there is no queue.\n");
                    break;
                } else if (IsEmptyAQueue(q)) printf("Now the queue is empty.\n");
                else {
                    DeAQueue(q);
                    printf("Successfully delete the head of queue.\n");
                }
                break;
            case 4:
                if (q->data[0] == NULL) {
                    printf("Now there is no queue.\n");
                    break;
                } else {
                    if (IsEmptyAQueue(q)) printf("Now the queue is empty.\n");
                    else {
                        ClearAQueue(q);
                        printf("Successfully clear the queue.\n");
                    }
                }
                break;
            case 5:
                if (q->data[0] == NULL) {
                    printf("Now there is no queue.\n");
                    break;
                } else {
                    DestroyAQueue(q);
                    flag = 0;
                    printf("Successfully destroy the queue.\n");
                }
                break;
            case 6:
                if (q->data[0] == NULL) {
                    printf("Now there is no queue.\n");
                    break;
                } else {
                    n = LengthAQueue(q);
                    printf("The length of the queue is %d.\n", n);
                }
                break;
            case 7:
                if (q->data[0] == NULL) {
                    printf("Now there is no queue.\n");
                    break;
                } else {
                    if (IsEmptyAQueue(q)) printf("It is empty.\n");
                    else printf("It is not empty.\n");
                }
                break;
            case 8:
                if (q->data[0] == NULL) {
                    printf("Now there is no queue.\n");
                    break;
                } else {
                    if (IsFullAQueue(q)) printf("It is full.\n");
                    else printf("It is not full.\n");
                }
                break;
            case 9:
                if (q->data[0] == NULL) {
                    printf("Now there is no queue.\n");
                    break;
                } else {
                    if (IsEmptyAQueue(q)) printf("Now the queue is empty.\n");
                    else {
                        GetHeadAQueue(q, &e);
                        printf("The head of queue is ");
                        APrint(&e);
                        printf(".\n");
                    }
                }
                break;
            case 10:
                TraverseAQueue(q, &APrint);
                printf("\n");
                break;
            case 11:
                printf("\nByeBye~");
                exit(0);
                break;
            default:
                printf("No such choice.\n");
        }
        system("pause");
    }
}
