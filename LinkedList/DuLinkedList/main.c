#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"

int main()
{
    DuLinkedList head; // Head of DuLinkedList.
    int flag = 0; // Whether exist DuLinkedList.
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
        printf(">>> 8.Exit.                \n");
        printf("---------------------------\n");
        if(flag)
        {
            TraverseList_DuL(head, visit); // Print LinkedList.
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
            {
                int n;
                printf("Length of the DuLinkedList:");
                scanf("%d", &n);
                head = Create(n);
                flag = 1;
                break;
            }
        case 2:
            if(flag)
            {
                TraverseList_DuL(head, visit);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 3:
            head = InitList_DuL(head);
            flag = 1;
            break;
        case 4:
            if(flag)
            {
                DestroyList_DuL(head);
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
                head = Insert_Node(head);
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 6:
            if(flag)
            {
                int x;
                printf("What to delete? ");
                scanf("%d", &x);
                head = DeleteList_DuL(head, x);
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
                DuLinkedList temp;
                printf("Where to search? ");
                scanf("%d", &i);
                temp = SearchList(head, i);
                if(temp)
                {
                    printf("What you find is %d.\n", temp->data);
                }
            }
            else
            {
                printf("No LinkedList.\n");
            }
            break;
        case 8:
            exit(0);
        default:
            break;
        }
        system("pause");
    }
    return 0;
}
