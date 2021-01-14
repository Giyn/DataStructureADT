/**
 * @filename SqStack.h
 * @description SqStack header file
 * @author ���Ԫ
 * @date 2020/4/24
 */

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack {
    ElemType *elem; // Pointer.
    int top; // Top index.
    int size; // Array length.
} SqStack;

// ���������˳��ջ
Status initStack(SqStack *s, int sizes); // ��ʼ��ջ
Status isEmptyStack(SqStack *s); // �ж�ջ�Ƿ�Ϊ��
Status getTopStack(SqStack *s, ElemType *e); // �õ�ջ��Ԫ��
Status clearStack(SqStack *s); // ���ջ
Status destroyStack(SqStack *s); // ����ջ
Status stackLength(SqStack *s, int *length); // ���ջ����
Status pushStack(SqStack *s, ElemType data); // ��ջ
Status popStack(SqStack *s, ElemType *data); // ��ջ
Status printStack(SqStack *s); // ʵʱ��ӡ˳��ջ
int InputNumber(); // �����������

#endif
