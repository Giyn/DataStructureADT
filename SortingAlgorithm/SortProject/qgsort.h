/**
 * @filename qgsort.h
 * @description qgsort header file
 * @author ���Ԫ
 * @date 2020/4/24
 */

#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkStack.h"

#define MAX_SIZE 200000 // ��������
#define BASE_SIZE 10    // ��������Ļ���

/**
 *  @name        : void insertSort(int *a, int n);
 *  @description : ��������
 *  @param       : ����ָ��a, ���鳤�� n
 */
void insertSort(int *a, int n);

/**
 *  @name        : void MergeArray(int *a, int begin, int mid, int end, int *temp);
 *  @description : �鲢����(�ϲ�����)
 *  @param       : ����ָ��a, �������begin, �����е�mid, �����յ�end, ��������ָ��temp
 */
void MergeArray(int *a, int begin, int mid, int end, int *temp);

/**
 *  @name        : void MergeSort(int *a, int begin, int end, int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a, �������begin, �����յ�end, ��������ָ��temp
 */
void MergeSort(int *a, int begin, int end, int *temp);

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : ��������(�ݹ��)
 *  @param       : ����ָ��a, �������begin, �����յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end);

/**
 *  @name        : void Swap(int a[], int begin, int end)
 *  @description : ����Ԫ��
 *  @param       : ����ָ��a, �������begin, �����յ�end
 */
void Swap(int a[], int begin, int end);

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : ��������(������)
 *  @param       : ����ָ��a, �������begin, �����յ�end
 */
int Partition(int *a, int begin, int end);

/**
 *  @name        : void QuickSort(int *a, int size)
 *  @description : ��������(�ǵݹ��)
 *  @param       : ����ָ��a, ���鳤��size
 */
void QuickSort(int *a, int size);

/**
 *  @name        : void CountSort(int *a, int size, int max)
 *  @description : ��������
 *  @param       : ����ָ��a, ���鳤��size, �������ֵmax
 */
void CountSort(int *a, int size, int max);

/**
 *  @name        : void RadixCountSort(int *a, int size)
 *  @description : ������������
 *  @param       : ����ָ��a, ���鳤��size
 */
void RadixCountSort(int *a, int size);

/**
 *  @name        : void ColorSwap(int *a, int p1, int p2)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a(ֻ��0, 1, 2Ԫ��)
 */
void ColorSwap(int *a, int p1, int p2);

/**
 *  @name        : void ColorSort(int *a, int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a(ֻ��0, 1, 2Ԫ��), ���鳤��size
 */
void ColorSort(int *a, int size);

/**
 *  @name        : int CheckColorData(int *a, int size)
 *  @description : ���������ɫ����������Ƿ�Ϸ�
 *  @param       : ����ָ��a(ֻ��0, 1, 2Ԫ��)
 */
int CheckColorData(int *a, int size);

/**
 *  @name        : int No_K(int *a, int size, int k)
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a, ���鳤��size
 */
int No_K(int *a, int size, int k);

/**
 *  @name        : InputNumber
 *	@description : to input a checked number
 *	@param		 : none
 *	@return		 : int
 *  @notice      : None
 */
int InputNumber();

/**
 *  @name        : InputData(int *data)
 *	@description : Input data
 *	@param		 : int * data
 *	@return		 : int
 *  @notice      : None
 */
int InputData(int *data);

/**
 *  @name        : Print(int *data, int n)
 *	@description : Print data
 *	@param		 : int *data, int n
 *	@return		 : int
 *  @notice      : None
 */
int Print(int *data, int n);

/**
 *  @name        : int test(int *a, int *n)
 *	@description : test the algorithm
 *	@param		 : int *a, int *n
 *	@return		 : int
 *  @notice      : None
 */
int test(int *a, int *n);

#endif
