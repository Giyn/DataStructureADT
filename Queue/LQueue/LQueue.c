/**
 * @filename LQueue.c
 * @description LQueue source file
 * @author 许继元
 * @date 2020/4/24
 */

#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>

char type;
int data_size = 0;

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *  @description : 初始化队列
 *  @param       : Q - 队列指针
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
    Q->front = Q->rear = (Node *) malloc(sizeof(Node));
    data_size = InputType();
    Q->front->data = (void *) malloc(data_size);
    Q->length = 0;
    Q->front->next = NULL;
    printf("Successfully initialize a queue!\n");
}

/**
 *  @name        : void DestroyLQueue(LQueue *Q)
 *  @description : 销毁队列
 *  @param       : Q - 队列指针
 *  @notice      : None
 */
void DestroyLQueue(LQueue *Q) {
    if (Q->length == 0) return;

    Node *p = Q->front;
    Node *q = p;
    Q->front = Q->rear = (Node *) malloc(sizeof(Node));
    Q->length = 0;

    while (p != NULL) {
        q = p;
        p = p->next;
        free(q->data);
        free(q);
    }
    free(Q->front);
    Q->front = Q->rear = NULL;
    Q = NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : 检查队列是否为空
 *  @param       : Q - 队列指针Q
 *  @return      : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q) {
    if (Q->length == 0) return TRUE;
    else return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : 查看队头元素
 *  @param       : Q - 队列指针Q
 *                 e - 返回数据指针
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e) {
    memcpy(e, Q->front->data, data_size);
    if (e == NULL) return FALSE;
    else return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *  @description : 确定队列长度
 *  @param       : Q - 队列指针
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : 入队操作
 *  @param       : Q - 队列指针
 *                 data - 入队数据指针
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = (void *) malloc(data_size);
    memcpy(p->data, data, data_size);
    p->next = NULL;

    if (Q->front == NULL) Q->front = p;
    if (Q->rear == NULL) Q->rear = p;
    if (Q->length == 0) Q->front = Q->rear = p;
    else {
        Q->rear->next = p;
        Q->rear = p;
    }
    Q->length++;
    printf("Successfully enter the queue.\n");
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *  @description : 出队操作
 *  @param       : Q - 队列指针
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q) {
    if (Q->front == NULL) return FALSE;

    Node *p = Q->front;
    Q->front = p->next;
    Q->length--;
    free(p);
    p = NULL;
    printf("Successfully delete the head of queue.\n");

    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *  @description : 清空队列
 *  @param       : Q - 队列指针
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
    Node *p = Q->front;
    Node *q = p;
    Q->front = Q->rear = (Node *) malloc(sizeof(Node));
    Q->length = 0;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q->data);
        free(q);
    }
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *  @description : 遍历函数操作
 *  @param       : Q - 队列指针Q
 *                 foo - 操作函数指针
 *  @return      : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void(*foo)(void *q)) {
    if (IsEmptyLQueue(Q)) {
        printf("Now the queue is empty.");
        return FALSE;
    }
    Node *p = Q->front;

    while (p) {
        (*foo)(p->data);
        if (p->next == NULL) return TRUE;
        printf("<- ");
        p = p->next;
    }
}

/**
 *  @name        : void LPrint(void *q)
 *  @description : 操作函数
 *  @param       : q - 指针
 *  @return      : None
 *  @notice      : None
 */
void LPrint(void *q) {
    if (type == 'i') {
        int *e = (int *) q;
        printf("%d", *e);
    } else if (type == 'l') {
        long *e = (long *) q;
        printf("%ld", *e);
    } else if (type == 'f') {
        float *e = (float *) q;
        printf("%f", *e);
    } else if (type == 'd') {
        double *e = (double *) q;
        printf("%lf", *e);
    } else if (type == 'c') {
        char *e = (char *) q;
        printf("%c", *e);
    }
}

/**
 *  @name        : InputNumber
 *	@description : Get the correct integer input
 *	@param		 : None
 *	@return		 : int
 *  @notice      : None
 */
int InputNumber() {
    int num = 0; // Store converted numbers.
    int status = 0; // Flag status.
    char str[100]; // Receive string.
    do {
        scanf("%s", str);
        status = TRUE;

        for (int i = 0; str[i] != '\0'; i++) {
            // Check for illegal characters.
            if (i == 0) {
                if (str[i] == '-' || str[i] == '+') continue;
            } else {
                if (str[i] < '0' || str[i] > '9') status = FALSE;
            }
        }
        if (status == FALSE) printf("Illegally input, please input again:");
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
                status = FALSE;
            }
        }
    } while (status == FALSE);

    return num;
}

/**
 *  @name        : InputType
 *	@description : Get the data type
 *	@param		 : None
 *	@return		 : int
 *  @notice      : None
 */
int InputType() {
    int ret = 0;
    do {
        ret = 0;
        printf("Choose a data type：");
        printf("[i->int] [l->long] [f->float] [d->double] [c->char]\n");
        getchar();
        printf("Input a char:");
        type = getchar();
        if (type == 'i') return 4;
        else if (type == 'l') return 8;
        else if (type == 'f') return 4;
        else if (type == 'd') return 8;
        else if (type == 'c') return 1;
        else {
            ret = -1;
            printf("\nIllegally input, please input again:");
        }
    } while (ret == -1);

    return 0;
}

/**
 *  @name        : InputData
 *	@description : Get the data
 *	@param		 : None
 *	@return		 : None
 *  @notice      : None
 */
void InputData(void *data) {
    int ret = 0;
    do {
        ret = 0;
        if (type == 'i') scanf("%d", data, data_size);
        else if (type == 'l') scanf("%ld", data, data_size);
        else if (type == 'f') scanf("%f", data, data_size);
        else if (type == 'd') scanf("%lf", data, data_size);
        else if (type == 'c') scanf("%c", data, data_size);

        if (getchar() != '\n') {
            ret = -1;
            for (; getchar() != '\n';);
            printf("Illegally input, please input again:", ret);
        } else return FALSE;
    } while (ret = -1);
}
