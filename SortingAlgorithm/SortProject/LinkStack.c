/**
 * @filename LinkStack.c
 * @description LinkStack source file
 * @author ะํผฬิช
 * @date 2020/4/24
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

StackNode *bottom = NULL;

Status initLStack(LinkStack *s) {
    s->count = 0;
    s->top = (StackNode *) malloc(sizeof(StackNode));
    s->top->data = 1234567890;
    s->top->next = NULL;
    bottom = s->top;

    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s) {
    if (s->count == 0) return SUCCESS;

    return ERROR;
}

Status getTopLStack(LinkStack *s, ElemType *e) {
    if (s->top == NULL) {
        printf("There is no stack.\n");
        return ERROR;
    }
    *e = s->top->data;

    return SUCCESS;
}

Status clearLStack(LinkStack *s) {
    StackNode *p = NULL;
    s->count = 0;
    s->top = bottom;
    p = bottom = bottom->next;
    while (p) {
        p = bottom->next;
        free(bottom);
        bottom = p;
    }
    printf("Successfully clear the stack.\n");

    return SUCCESS;
}

Status destroyLStack(LinkStack *s) {
    StackNode *p = NULL;
    s->count = 0;
    s->top = NULL;
    while (p) {
        p = bottom->next;
        free(bottom);
        bottom = p;
    }
    printf("Successfully destroy the stack.\n");

    return SUCCESS;
}

Status LStackLength(LinkStack *s, int *length) {
    if (s->top == NULL) {
        printf("There is no stack.\n");
        return ERROR;
    }
    *length = s->count;
    printf("The length of the stack is %d.\n", *length);

    return SUCCESS;
}

Status pushLStack(LinkStack *s, ElemType data) {
    StackNode *p = (StackNode *) malloc(sizeof(StackNode));
    p->data = data;
    p->next = NULL;
    s->top->next = p;
    s->top = p;
    s->count++;

    return SUCCESS;
}

Status popLStack(LinkStack *s, ElemType *data) {
    StackNode *p = bottom;
    if (s->count == 0) {
        printf("The stack is empty.\n");
        return ERROR;
    } else {
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

        return SUCCESS;
    }
}

Status printStack(LinkStack *s) {
    StackNode *p = NULL;
    if (s->top == NULL) {
        printf("There is no stack now.\n");
        return ERROR;
    } else if (s->count == 0) return ERROR;

    for (p = bottom->next; p; p = p->next) printf("|%d", p->data);
    printf("\n");

    return SUCCESS;
}
