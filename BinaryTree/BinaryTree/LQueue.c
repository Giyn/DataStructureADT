/**
 * @filename LQueue.c
 * @description LQueue source file
 * @author ���Ԫ
 * @date 2020/4/24
 */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include"LQueue.h"

char type;
int data_size = 0;

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *  @description : ��ʼ������
 *  @param       : Q - ����ָ��
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
    Q->front = Q->rear = (Node *) malloc(sizeof(Node));
    if (Q->front == NULL) return;

    data_size = sizeof(BiTNode);
    Q->front->data = (void *) malloc(data_size);
    Q->length = 0;
    Q->front->next = NULL;

    return;
}

/**
 *  @name        : void DestroyLQueue(LQueue *Q)
 *  @description : ���ٶ���
 *  @param       : Q - ����ָ��
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
 *  @description : �������Ƿ�Ϊ��
 *  @param       : Q - ����ָ��Q
 *  @return      : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
status IsEmptyLQueue(const LQueue *Q) {
    if (Q->length == 0) return TRUE;
    else return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : �鿴��ͷԪ��
 *  @param       : Q - ����ָ��Q
 *                 e - ��������ָ��
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
status GetHeadLQueue(LQueue *Q, void *e) {
    memcpy(e, Q->front->data, data_size);
    if (e == NULL) return FALSE;
    else return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *  @description : ȷ�����г���
 *  @param       : Q - ����ָ��
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : ��Ӳ���
 *  @param       : Q - ����ָ��
 *                 data - �������ָ��
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
status EnLQueue(LQueue *Q, void *data) {
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
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *  @description : ���Ӳ���
 *  @param       : Q - ����ָ��
 *  @return      : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
status DeLQueue(LQueue *Q) {
    if (Q->front == NULL) return FALSE;

    Node *p = Q->front;
    Q->front = p->next;
    Q->length--;
    free(p);
    p = NULL;

    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *  @description : ��ն���
 *  @param       : Q - ����ָ��
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
 *  @description : ������������
 *  @param       : Q - ����ָ��Q
 *                 foo - ��������ָ��
 *  @return      : None
 *  @notice      : None
 */
status TraverseLQueue(const LQueue *Q, void(*foo)(void *q)) {
    if (IsEmptyLQueue(Q)) return FALSE;

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
 *  @description : ��������
 *  @param       : q - ָ��
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
