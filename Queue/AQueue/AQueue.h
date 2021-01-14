/**
 * @filename AQueue.h
 * @description AQueue header file
 * @author 许继元
 * @date 2020/4/24
 */

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/

#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED

/**************************************************************
 *    Macro Define Section
 **************************************************************/

#define MAXQUEUE 10

/**************************************************************
 *    Struct Define Section
 **************************************************************/

#include<stdlib.h>
#include<stdio.h>

typedef struct Aqueue {
    void *data[MAXQUEUE]; //数据域
    int front;
    int rear;
    size_t length; //队列长度
} AQueue;

typedef enum {
    FALSE = 0, TRUE = 1
} Status;

char type;
char datatype[MAXQUEUE];

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *  @description : 初始化队列
 *  @param       : Q - 队列指针
 *  @notice      : None
 */
void InitAQueue(AQueue *Q);

/**
 *  @name        : void DestroyAQueue(AQueue *Q)
 *  @description : 销毁队列
 *  @param       : Q - 队列指针
 *  @notice      : None
 */
void DestroyAQueue(AQueue *Q);

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *  @description : 检查队列是否已满
 *  @param       : Q - 队列指针
 *  @return      : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q);

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *  @description : 检查队列是否为空
 *  @param       : Q - 队列指针Q
 *  @return      : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q);

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *  @description : 查看队头元素
 *  @param       : Q - 队列指针
 *                 e - 存放元素
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e);

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *  @description : 确定队列长度
 *  @param       : Q - 队列指针
 *  @return      : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q);

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *  @description : 入队操作
 *  @param       : Q - 队列指针
 *                 data - 入队数据指针
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data);

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *  @description : 出队操作
 *  @param       : Q - 队列指针
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q);

/**
 *  @name        : void ClearAQueue(Queue *Q)
 *  @description : 清空队列
 *  @param       : Q - 队列指针
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q);

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *  @description : 遍历函数操作
 *  @param       : Q - 队列指针
 *                 foo - 操作函数指针
 *  @return      : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void(*foo)(void *q));

/**
 *  @name        : void APrint(void *q)
 *  @description : 操作函数
 *  @param       : q - 指针
 *  @notice      : None
 */
void APrint(void *q);

/**
 *  @name        : int InputNumber()
 *	@description : Check input number
 *	@param		 : None
 *	@return		 : Integer
 *  @notice      : None
 */
int InputNumber();

/**
 *  @name        : InputType
 *	@description : Get the data type
 *	@param		 : none
 *	@return		 : Integer
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
