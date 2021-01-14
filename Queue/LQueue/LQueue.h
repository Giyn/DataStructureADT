/**
 * @filename LQueue.h
 * @description LQueue header file
 * @author 许继元
 * @date 2020/4/24
 */

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/

#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

/**************************************************************
 *    Struct Define Section
 **************************************************************/

#include<stdlib.h>
#include<stdio.h>

typedef struct node {
    void *data;        //数据域指针
    struct node *next; //指向当前结点的下一结点
} Node;

typedef struct Lqueue {
    Node *front;   //队头
    Node *rear;    //队尾
    size_t length; //队列长度
} LQueue;

typedef enum {
    FALSE = 0, TRUE = 1
} Status;

char type;
char datatype[30];

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *  @description : 初始化队列
 *  @param       : Q - 队列指针
 *  @notice      : None
 */
void InitLQueue(LQueue *Q);

/**
 *  @name        : void DestroyLQueue(LQueue *Q)
 *  @description : 销毁队列
 *  @param       : Q - 队列指针
 *  @notice      : None
 */
void DestroyLQueue(LQueue *Q);

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : 检查队列是否为空
 *  @param       : Q - 队列指针Q
 *  @return      : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q);

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : 查看队头元素
 *  @param       : Q - 队列指针Q
 *                 e - 返回数据指针
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e);

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *  @description : 确定队列长度
 *  @param       : Q - 队列指针
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q);

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : 入队操作
 *  @param       : Q - 队列指针
 *                 data - 入队数据指针
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data);

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *  @description : 出队操作
 *  @param       : Q - 队列指针
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q);

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *  @description : 清空队列
 *  @param       : Q - 队列指针
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q);

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *  @description : 遍历函数操作
 *  @param       : Q - 队列指针Q
 *                 foo - 操作函数指针
 *  @return      : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void(*foo)(void *q));

/**
 *  @name        : void LPrint(void *q)
 *  @description : 操作函数
 *  @param       : q - 指针
 *  @return      : None
 *  @notice      : None
 */
void LPrint(void *q);

/**
 *  @name        : InputNumber
 *	@description : Get the correct integer input
 *	@param		 : None
 *	@return		 : int
 *  @notice      : None
 */
int InputNumber();

/**
 *  @name        : InputType
 *	@description : Get the data type
 *	@param		 : None
 *	@return		 : int
 *  @notice      : None
 */
int InputType();

/**
 *  @name        : InputData
 *	@description : Get the data
 *	@param		 : None
 *	@return		 : None
 *  @notice      : None
 */
void InputData(void *data);

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif
