/**
 * @filename qgsort.h
 * @description qgsort header file
 * @author 许继元
 * @date 2020/4/24
 */

#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkStack.h"

#define MAX_SIZE 200000 // 数组容量
#define BASE_SIZE 10    // 基数排序的基数

/**
 *  @name        : void insertSort(int *a, int n);
 *  @description : 插入排序
 *  @param       : 数组指针a, 数组长度 n
 */
void insertSort(int *a, int n);

/**
 *  @name        : void MergeArray(int *a, int begin, int mid, int end, int *temp);
 *  @description : 归并排序(合并数组)
 *  @param       : 数组指针a, 数组起点begin, 数组中点mid, 数组终点end, 承载数组指针temp
 */
void MergeArray(int *a, int begin, int mid, int end, int *temp);

/**
 *  @name        : void MergeSort(int *a, int begin, int end, int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a, 数组起点begin, 数组终点end, 承载数组指针temp
 */
void MergeSort(int *a, int begin, int end, int *temp);

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序(递归版)
 *  @param       : 数组指针a, 数组起点begin, 数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end);

/**
 *  @name        : void Swap(int a[], int begin, int end)
 *  @description : 交换元素
 *  @param       : 数组指针a, 数组起点begin, 数组终点end
 */
void Swap(int a[], int begin, int end);

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序(枢轴存放)
 *  @param       : 数组指针a, 数组起点begin, 数组终点end
 */
int Partition(int *a, int begin, int end);

/**
 *  @name        : void QuickSort(int *a, int size)
 *  @description : 快速排序(非递归版)
 *  @param       : 数组指针a, 数组长度size
 */
void QuickSort(int *a, int size);

/**
 *  @name        : void CountSort(int *a, int size, int max)
 *  @description : 计数排序
 *  @param       : 数组指针a, 数组长度size, 数组最大值max
 */
void CountSort(int *a, int size, int max);

/**
 *  @name        : void RadixCountSort(int *a, int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a, 数组长度size
 */
void RadixCountSort(int *a, int size);

/**
 *  @name        : void ColorSwap(int *a, int p1, int p2)
 *  @description : 颜色交换
 *  @param       : 数组指针a(只含0, 1, 2元素)
 */
void ColorSwap(int *a, int p1, int p2);

/**
 *  @name        : void ColorSort(int *a, int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a(只含0, 1, 2元素), 数组长度size
 */
void ColorSort(int *a, int size);

/**
 *  @name        : int CheckColorData(int *a, int size)
 *  @description : 检查用于颜色排序的数据是否合法
 *  @param       : 数组指针a(只含0, 1, 2元素)
 */
int CheckColorData(int *a, int size);

/**
 *  @name        : int No_K(int *a, int size, int k)
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a, 数组长度size
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
