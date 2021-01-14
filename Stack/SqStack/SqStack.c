/**
 * @filename SqStack.c
 * @description SqStack source file
 * @author ะํผฬิช
 * @date 2020/4/24
 */

#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

Status initStack(SqStack *s, int sizes) {
    if (sizes <= 0) {
        printf("Stack size must > 0.\n");
        return ERROR;
    } else {
        s->size = sizes; // Array length.
        s->top = -1; // Top index.
        // Allocate memory to the array, sizes is the length of the array.
        s->elem = (ElemType *) malloc(sizes * sizeof(ElemType));
        printf("Successfully create a %d size stack.\n", sizes);

        return SUCCESS;
    }
}

Status isEmptyStack(SqStack *s) {
    if (s == NULL || s->top == -1) {
        printf("It is empty.\n");
        return SUCCESS;
    }
    printf("Not empty.\n");

    return ERROR;
}

Status getTopStack(SqStack *s, ElemType *e) {
    if (s == NULL || s->top == -1) {
        printf("The is no stack now.\n");
        return ERROR;
    } else {
        *e = s->elem[s->top];
        printf("The top element is %d.\n", *e);
        return SUCCESS;
    }
}

Status clearStack(SqStack *s) {
    if (s == NULL) {
        printf("The stack is already empty now.\n");
        return ERROR;
    } else {
        s->top = -1;
        printf("Successfully clear the stack.\n");
        return SUCCESS;
    }
}

Status destroyStack(SqStack *s) {
    if (s == NULL || s->size == 0) {
        printf("Please initialize first.\n");
        return ERROR;
    } else {
        free(s->elem);
        s->size = 0;
        s->elem = NULL;
        printf("Successfully destroy the stack.\n");
        return SUCCESS;
    }
}

Status stackLength(SqStack *s, int *length) {
    if (s == NULL || s->size == 0) {
        printf("Please initialize first.\n");
        return ERROR;
    } else {
        *length = s->top + 1;
        printf("The length of the stack is %d.\n", *length);
        return SUCCESS;
    }
}

Status pushStack(SqStack *s, ElemType data) {
    if (s == NULL || (s->size <= s->top + 1)) {
        printf("Stack is full.\n");
        return ERROR;
    } else {
        s->elem[++s->top] = data;
        printf("Successfully push %d to the stack.\n", data);
        return SUCCESS;
    }
}

Status popStack(SqStack *s, ElemType *data) {
    if (s == NULL || s->top == -1) {
        printf("The stack is empty.\n");
        return ERROR;
    } else {
        *data = s->elem[s->top];
        s->top--;
        printf("Successfully pop %d out the stack.\n", *data);
        return SUCCESS;
    }
}

Status printStack(SqStack *s) {
    if (s->size == 0) {
        printf("There is no stack now.\n");
        return ERROR;
    } else if (s == NULL || s->top == -1) return ERROR;

    for (int i = 0; i <= s->top; i++) printf("|%d", s->elem[i]);
    printf("\n");

    return SUCCESS;
}

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
        if (status == ERROR) printf("Illegally input, please input again:");
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
