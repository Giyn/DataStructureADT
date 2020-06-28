/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : void *InitList(LinkList L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head pointer)
 *	@return		 : LNode(the new head node) or Status
 *  @notice      : None
 */
void *InitList(LinkedList L);

/**
 *  @name        : Status DestroyList(LinkedList L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head pointer)
 *	@return		 : Status
 *  @notice      : None
 */
Status DestroyList(LinkedList L);

/**
 *  @name        : void *InsertList(LinkedList L, int i, ElemType x)
 *	@description : insert node q after node p
 *	@param		 : LinkedList L, int i, ElemType x
 *	@return		 : L(the head pointer) or Status
 *  @notice      : None
 */
void *InsertList(LinkedList L, int i, ElemType x);

/**
 *  @name        : void *DeleteList(LinkedList L, ElemType x)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : LinkedList L, ElemType x
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *DeleteList(LinkedList L, ElemType x);

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head pointer), visit
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e));
void visit(ElemType e);

/**
 *  @name        : void *SearchList(LinkedList L, int i)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head pointer), e
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *SearchList(LinkedList L, int i);

/**
 *  @name        : void *ReverseList(LinkedList L)
 *	@description : reverse the linked list
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *ReverseList(LinkedList L);

/**
 *  @name        : void IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void IsLoopList(LinkedList L);

/**
 *  @name        : LNode* ReverseEvenList(LinkedList L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList L);

/**
 *  @name        : LNode* FindMidNode(LinkedList L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head pointer)
 *	@return		 : LNode*
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList L);

/**
 *  @name        : void *Create()
 *	@description : Create a linked list
 *	@param		 : None
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Create();

/**
 *  @name        : int LinkedList_length(LinkedList L)
 *	@description : Measure the length of linked list
 *	@param		 : L(the head pointer)
 *	@return		 : Length of linked list
 *  @notice      : None
 */
int LinkedList_length(LinkedList L);

/**
 *  @name        : void *Create_loopLinkedList()
 *	@description : Create a loop LinkedList
 *	@param		 : None
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Create_loopLinkedList();

int InputNumber(); // Check input number.

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
