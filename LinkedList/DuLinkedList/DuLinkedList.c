/**
 * @filename DuLinkedList.c
 * @description DuLinkedList source file
 * @author 许继元
 * @date 2020/4/24
 */

#include <stdio.h>
#include <stdlib.h>
#include "DuLinkedList.h"

/**
 *  @data        : void *InitList_DuL(DuLinkedList L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *InitList_DuL(DuLinkedList L) {
    L = (DuLinkedList) malloc(sizeof(DuLNode));
    if (!L) return OVERFLOW;
    L->prior = L->next = NULL;
    printf("Successfully initialize a DuLinkedList!\n");

    return L;
}

/**
 *  @data        : void DestroyList_DuL(DuLinkedList L)
 *	@description : destroy a linked list
 *	@param		 : L(the head pointer)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList L) {
    DuLinkedList p;
    p = L;
    while (p) {
        p = p->next;
        free(L);
        L = p;
    }
}

/**
 *  @data        : void *Insert_Node(DuLinkedList head)
 *	@description : insert node q before node p
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Insert_Node(DuLinkedList head) {
    DuLinkedList q;
    DuLinkedList pnext = head;
    int i = 1;
    int n;

    printf("Where to insert? ");
    scanf("%d", &n);

    while ((i < n) && (pnext != NULL)) {
        i++;
        pnext = pnext->next;
    }

    if (pnext == NULL) return ERROR;
    else {
        q = (DuLinkedList) malloc(sizeof(DuLNode));
        printf("What to insert? ");
        scanf("%d", &q->data);

        q->next = pnext->next;
        if (n = 0) {
            pnext->next = q;
            q->next = NULL;
        } else {
            pnext->next = q;
            pnext->next->prior = q;
            q->prior = pnext;
        }
    }

    return head;
}

/**
 *  @data        : void *DeleteList_DuL(DuLinkedList L, ElemType e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : L(the head pointer), ElemType e
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *DeleteList_DuL(DuLinkedList L, ElemType e) {
    if (L == NULL || L->next == NULL) return ERROR;
    DuLinkedList q, pre;
    q = L->next;

    while (q->data != e) {
        pre = q;
        q = q->next;
        if (q == NULL) {
            printf("No such data.\n");
            return ERROR;
        }
    }
    pre->next = q->next;
    free(q);
    printf("Successfully delete node!\n");

    return L;
}

/**
 *  @data        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLinkedList p = L->next;
    while (p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 *  @name        : void visit(ElemType e)
 *	@description : visit the data of the node
 *	@param		 : data of the node
 *	@return		 : None
 *  @notice      : None
 */
void visit(ElemType e) {
    printf("%d->", e);
}

/**
 *  @name        : void *Create(int n)
 *	@description : Create a linked list
 *	@param		 : int n
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Create(int n) {
    DuLinkedList h, p, s;
    h = (DuLinkedList) malloc(sizeof(DuLNode));

    if (h == NULL) return OVERFLOW;

    h->data = 0;
    h->prior = NULL;
    h->next = NULL;
    p = h;

    for (int i = 0; i < n; i++) {
        s = (DuLinkedList) malloc(sizeof(DuLNode));
        if (s == NULL) return OVERFLOW;
        p->next = s;
        printf("Please enter the data for No.%d node:", i + 1);
        scanf("%d", &s->data);
        s->prior = p;
        s->next = NULL;
        p = s;
    }
    printf("Successfully create a DuLinkedList!\n");

    return h;
}

/**
 *  @name        : void *SearchList(LinkedList L, int i)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head pointer), e
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *SearchList(DuLinkedList L, int i) // Maybe can create a function to realize find by value.
{
    if (L == NULL || L->next == NULL) {
        printf("Something wrong.\nThe DuLinkedList may not exist or there is only one node.");
        return NULL;
    }
    int j = 1;
    DuLinkedList p = L->next;
    if (i == 1) return L;
    if (i < 1) return NULL;

    while (p && i > j) {
        p = p->next;
        if (p == NULL) {
            printf("No such position.\n");
            return ERROR;
        }
        j++;
    }

    return p;
}

/**
 *  @name        : int InputNumber()
 *	@description : Check input number
 *	@param		 : None
 *	@return		 : Integer
 *  @notice      : None
 */
int InputNumber() {
    int num = 0; // Store converted numbers.
    int status = 0; // Flag status.
    char str[100]; // Receive string.
    do {
        scanf("%s", str);
        status = SUCCESS;

        for (int i = 0; str[i] != '\0'; i++) {
            // Check for illegal characters.
            if (i == 0) {
                if (str[i] == '-' || str[i] == '+') continue;
            } else {
                if (str[i] < '0' || str[i] > '9') status = ERROR;
            }
        }
        if (status == ERROR) printf("No such choice, input it again:");
        else {
            int i = 0;
            // Convert string to number.
            for (i = 0, num = 0; str[i] != '\0'; i++) {
                if (i == 0) {
                    if (str[i] == '-' || str[i] == '+') continue;
                    else {
                        num *= 10;
                        num += (str[i] - 48);
                    }
                } else {
                    num *= 10;
                    num += (str[i] - 48);
                }
            }
            if (str[0] == '-') num = -num;
            // Check if the number entered is out of bounds.
            if (i >= 10) {
                printf("Overflow, please input again:");
                status = ERROR;
            }
        }
    } while (status == ERROR);

    return num;
}
