/**
 * @filename LinkedList.c
 * @description LinkedList source file
 * @author 许继元
 * @date 2020/4/24
 */

#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 *  @name        : void *InitList(LinkList L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head pointer)
 *	@return		 : LNode(the new head node) or Status
 *  @notice      : None
 */
void *InitList(LinkedList L) {
    if (!L) return ERROR;

    L = (LinkedList) malloc(sizeof(LNode));
    if (L == NULL) return OVERFLOW;

    printf("Successfully initialize the LinkedList.\n");
    L->next = NULL;

    return L;
}

/**
 *  @name        : Status DestroyList(LinkedList L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head pointer)
 *	@return		 : Status
 *  @notice      : None
 */
Status DestroyList(LinkedList L) {
    LinkedList p;
    p = L;

    while (p) {
        p = p->next;
        free(L); // Free up memory space.
        L = p;
    }
    printf("Successfully destroy the LinkedList!\n");

    return SUCCESS;
}

/**
 *  @name        : void *InsertList(LinkedList L, int i, ElemType x)
 *	@description : insert node q after node p
 *	@param		 : LinkedList L, int i, ElemType x
 *	@return		 : L(the head pointer) or Status
 *  @notice      : None
 */
void *InsertList(LinkedList L, int i, ElemType x) {
    if (L == NULL) {
        printf("Something wrong.\nThe LinkedList may not exist or there is only one node.");
        return ERROR;
    }
    LinkedList pre;
    pre = L;
    for (int temp = 1; temp < i; temp++) pre = pre->next;

    LinkedList q;
    q = (LinkedList) malloc(sizeof(LNode));
    q->data = x;
    q->next = pre->next;
    pre->next = q;

    printf("Successfully insert node!\n");

    return L;
}

/**
 *  @name        : void *DeleteList(LinkedList L, ElemType x)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : LinkedList L, ElemType x
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *DeleteList(LinkedList L, ElemType x) {
    if (L == NULL || L->next == NULL) {
        printf("Something wrong.\nThe LinkedList may not exist or there is only one node.");
        return ERROR;
    }
    LinkedList q, pre;
    q = L->next;

    while (q->data != x) {
        pre = q;
        q = q->next;
    }
    pre->next = q->next;
    free(q);
    printf("Successfully delete node!");

    return L;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head pointer), visit
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LinkedList p = L->next;
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
 *  @name        : void *SearchList(LinkedList L, int i)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head pointer), e
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *SearchList(LinkedList L, int i) // Maybe can create a function to realize find by value.
{
    if (L == NULL || L->next == NULL) {
        printf("Something wrong.\nThe LinkedList may not exist or there is only one node.");
        return NULL;
    }
    int j = 1;
    LinkedList p = L->next;

    if (i == 1) return L;
    if (i < 1) return NULL;

    while (p && i > j) {
        p = p->next;
        j++;
    }

    return p;
}

/**
 *  @name        : void *ReverseList(LinkedList L)
 *	@description : reverse the linked list
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *ReverseList(LinkedList L) {
    if (L == NULL) {
        printf("Something wrong.\nThe LinkedList may not exist.");
        return ERROR;
    }
    LNode *p, *q, *r;
    p = L->next;
    L->next = NULL;
    q = r = NULL;

    while (p) {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }
    L->next = r;

    return L;
}

/**
 *  @name        : void IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void IsLoopList(LinkedList L) {
    if (L == NULL || L->next == NULL) {
        printf("Something wrong.\nThe LinkedList may not exist or there is only one node.");
        return ERROR;
    }
    LinkedList fast, slow;
    slow = L;
    fast = L->next;
    while (1) {
        if (!fast || !fast->next) {
            printf("It is not a loop LinkedList.\n");
            return SUCCESS;
        } else if (fast == slow || fast->next == slow) // Fast pointer catches up or exceeds slow pointer.
        {
            printf("It is a loop LinkedList.\n");
            return SUCCESS;
        } else {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : choose to finish
 */
LNode *ReverseEvenList(LinkedList L) {
    LinkedList cur = L->next;
    LinkedList pre;
    LinkedList phead = (LinkedList) malloc(sizeof(LNode));
    phead->next = NULL;
    LinkedList ph = phead;

    while (cur && cur->next) {
        pre = cur;
        ph->next = pre->next; // First point to the second node in two groups.
        ph = ph->next; // Move ph pointer.
        cur = cur->next->next; // Move the cur pointer for the next round of swaps.
        ph->next = pre; // Point to the first node in two sets.
        ph = ph->next; // Move ph pointer.
    }
    ph->next = cur; // Finally point to the remaining element if cur is NULL or odd.

    return phead;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head pointer)
 *	@return		 : LNode*
 *  @notice      : choose to finish
 */
LNode *FindMidNode(LinkedList L) {
    if (L == NULL || L->next == NULL) return L;

    LinkedList fast, slow;
    fast = slow = L;
    while (fast != NULL) {
        if (fast->next == NULL) fast = fast->next;
        else fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

/**
 *  @name        : void *Create()
 *	@description : Create a linked list
 *	@param		 : None
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Create() {
    LinkedList head;
    LinkedList p, s;
    ElemType x, cycle = 1;
    head = (LinkedList) malloc(sizeof(LNode));
    p = head;

    while (cycle) {
        printf("Please input the data(input non-integer to exit):");
        if (scanf("%d", &x) == 1) {
            s = (LinkedList) malloc(sizeof(LNode));
            s->data = x;
            p->next = s;
            p = s;
        } else cycle = 0;
    }
    printf("Successfully create a LinkedList!\n");
    p->next = NULL;

    return head;
}

/**
 *  @name        : int LinkedList_length(LinkedList L)
 *	@description : Measure the length of linked list
 *	@param		 : L(the head pointer)
 *	@return		 : Length of linked list
 *  @notice      : None
 */
int LinkedList_length(LinkedList L) {
    int k = 0;
    while (L != NULL) {
        k++;
        L = L->next;
    }

    return k;
}

/**
 *  @name        : void *Create_loopLinkedList()
 *	@description : Create a loop LinkedList
 *	@param		 : None
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Create_loopLinkedList() {
    int i, length = 0, data = 0;
    LinkedList pTail = NULL, p_new = NULL;
    LinkedList pHead = (LinkedList) malloc(sizeof(LNode));

    if (NULL == pHead) {
        printf("Memory allocation failed!\n");
        return OVERFLOW;
    }

    pHead->data = 0;
    pHead->next = pHead;
    pTail = pHead;

    printf("Please enter the length of the LinkedList:");
    scanf("%d", &length);

    for (i = 1; i < length + 1; i++) {
        p_new = (LinkedList) malloc(sizeof(LNode));

        if (NULL == p_new) {
            printf("Memory allocation failed!\n");
            return OVERFLOW;
        }

        printf("Please enter the data for No.%d node:", i);
        scanf("%d", &data);

        p_new->data = data;
        p_new->next = pHead; // The last node always points to the head node.
        pTail->next = p_new;
        pTail = p_new;
    }

    return pHead;
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
