#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main()
{
    LinkedList head; // Head of LinkedList.
    int flag = 0; // Whether exist LinkedList.
    while(SUCCESS)
    {
        system("cls");
        printf("\n\n\n---------------------------\n");
        printf(">>> 1.Creat.               \n");
        printf(">>> 2.Print.               \n");
        printf(">>> 3.Initialize.          \n");
        printf(">>> 4.Destroy.             \n");
        printf(">>> 5.Insert.              \n");
        printf(">>> 6.Delete.              \n");
        printf(">>> 7.Search.              \n");
        printf(">>> 8.Reverse.             \n");
        printf(">>> 9.Reverse odd&even.    \n");
        printf(">>> 10.Find MidNode.       \n");
        printf(">>> 11.Judge loop.         \n");
        printf(">>> 12.Create a loop one.  \n");
        printf(">>> 13.Exit.               \n");
        printf("---------------------------\n");
        if(flag)
        {
            TraverseList(head, visit); // Print LinkedList.
        }
        else
        {
            printf("No LinkedList.\n");
        }
        printf("---------------------------\n");
        printf("----->>> Please input your choice:");
        switch(InputNumber())
        {
        case 1:
            head = Create();
            flag = 1;
            break;
        case 2:
            if(flag)
            {
                TraverseList(head, visit);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 3:
            head = InitList(head);
            flag = 1;
            break;
        case 4:
            if(flag)
            {
                DestroyList(head);
                flag = 0;
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 5:
            if(flag)
            {
                int i;
                ElemType x;
                printf("Where to insert? ");
                scanf("%d", &i);
                printf("Input data:");
                scanf("%d", &x);
                head = InsertList(head, i, x);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 6:
            if(flag)
            {
                ElemType x;
                printf("What to delete? ");
                scanf("%d", &x);
                DeleteList(head, x);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 7:
            if(flag)
            {
                int i;
                LinkedList temp;
                printf("Where it is? ");
                scanf("%d", &i);
                temp = SearchList(head, i);
                printf("What you find is %d.\n", temp->data);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 8:
            if(flag)
            {
                head = ReverseList(head);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 9:
            if(flag)
            {
                head = ReverseEvenList(head);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 10:
            if(flag)
            {
                LinkedList mid, temp = head;
                mid = FindMidNode(head);
                if(LinkedList_length(head)%2 == 0)
                {
                    printf("The data of middle Node is %d\n", mid->data);
                }
                else // The length of LinkList is even.Print the middle two values of the LinkedList.
                {
                    while(temp->next != mid) // Find the middle node which is near the head node.
                    {
                        temp = temp->next;
                    }
                    printf("The data of middle Node is %d and %d\n", temp->data, temp->next->data);
                }
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 11:
            if(flag)
            {
                IsLoopList(head);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 12:
            head = Create_loopLinkedList();
            break;
        case 13:
            exit(0);
        default:
            break;
        }
        system("pause");
    }
    return 0;
}
