/**
 * @filename SqStack.h
 * @description SqStack header file
 * @author 许继元
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

// 基于数组的顺序栈
Status initStack(SqStack *s, int sizes); // 初始化栈
Status isEmptyStack(SqStack *s); // 判断栈是否为空
Status getTopStack(SqStack *s, ElemType *e); // 得到栈顶元素
Status clearStack(SqStack *s); // 清空栈
Status destroyStack(SqStack *s); // 销毁栈
Status stackLength(SqStack *s, int *length); // 检测栈长度
Status pushStack(SqStack *s, ElemType data); // 入栈
Status popStack(SqStack *s, ElemType *data); // 出栈
Status printStack(SqStack *s); // 实时打印顺序栈
int InputNumber(); // 输入整数检测

#endif
