/***************************************************************************************
 *	File Name				:	duLinkedList.h
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

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

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
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior, *next;
} DuLNode, *DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @data        : void *InitList_DuL(DuLinkedList L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *InitList_DuL(DuLinkedList L);

/**
 *  @data        : void DestroyList_DuL(DuLinkedList L)
 *	@description : destroy a linked list
 *	@param		 : L(the head pointer)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList L);

/**
 *  @data        : void *Insert_Node(DuLinkedList head)
 *	@description : insert node q before node p
 *	@param		 : L(the head pointer)
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Insert_Node(DuLinkedList head);

/**
 *  @data        : void *DeleteList_DuL(DuLinkedList L, ElemType e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : L(the head pointer), ElemType e
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *DeleteList_DuL(DuLinkedList L, ElemType e);

/**
 *  @data        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));
void visit(ElemType e);

/**
 *  @name        : void *Create(int n)
 *	@description : Create a linked list
 *	@param		 : int n
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Create(int n);

/**
 *  @name        : void *SearchList(LinkedList L, int i)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head pointer), e
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *SearchList(DuLinkedList L, int i);

int InputNumber(); // Check input number.

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
