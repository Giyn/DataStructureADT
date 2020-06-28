#include "qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**
 *  @name        : void insertSort(int *a, int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a, int n)
{
	for(int i=1, move=i-1, temp=0; i<n; i++, move=i-1)
	{
		temp = a[i];
		while(move>=0 && temp<a[move])
		{
			a[move+1] = a[move];
			move--;
		}
		move++;
		a[move] = temp;
	}
}

/**
 *  @name        : void MergeArray(int *a, int begin, int mid, int end, int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a, int begin, int mid, int end, int *temp)
{
    if(a == NULL || begin>=end)
    {
        return ;
    }
    temp = (int*)malloc((end - begin + 1)*sizeof(int));
    int l_begin = begin;
    int l_end = mid;
    int r_begin = mid + 1;
    int r_end = end;

    int k = 0;

    while(l_begin<=l_end && r_begin<=r_end)
    {
        // 两两比较，小的存入
        temp[k++] = a[l_begin] < a[r_begin] ? a[l_begin++] : a[r_begin++];
    }

    // 若左半部分有剩余，合并进去
    while(l_begin <= l_end)
    {
        temp[k++] = a[l_begin++];
    }
    // 若右半部分有剩余，合并进去
    while(r_begin <= r_end)
    {
        temp[k++] = a[r_begin++];
    }

    for(int i=0; i<end-begin+1; i++)
    {
        a[begin+i] = temp[i];
    }

    free(temp);
}

/**
 *  @name        : void MergeSort(int *a, int begin, int end, int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a, int begin, int end, int *temp)
{
    if(a == NULL)
    {
        return ;
    }
	int mid = 0;
	if(begin < end)
    {
		mid = (begin + end) / 2;
		MergeSort(a, begin, mid, temp); // 使左边有序
		MergeSort(a, mid + 1, end, temp); // 使右边有序
		MergeArray(a, begin, mid, end, temp);
	}
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	if (begin < end)
	{
		int base = Partition(a, begin, end); // 把枢纽排好
		QuickSort_Recursion(a, end, base - 1);
		QuickSort_Recursion(a, base + 1, end);
	}
}

// 交换元素
void Swap(int a[], int begin, int end)
{
	int temp = a[begin];
	a[begin] = a[end];
	a[end] = temp;
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end)
{
	int base = a[begin]; // 选取枢纽
	while (begin < end)
	{
		// 从右边开始找，直到找到小于枢纽的
		while(begin < end && a[end] >= base)
		{
			end--;
		}
		Swap(a, begin, end);
		// 从左边开始找，直到找到大于枢纽的
		while(begin < end && a[begin] <= base)
		{
			begin++;
		}
		Swap(a, begin, end);
	}
	return begin;
}

/**
 *  @name        : void QuickSort(int *a, int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a, int size)
{
	int base, n;
	int left = 0;
	int right = size - 1;

	LinkStack stack;
	initLStack(&stack);
	pushLStack(&stack, 0);
	pushLStack(&stack, right);

	while(!isEmptyLStack(&stack))
	{
		getTopLStack(&stack, &right);
		popLStack(&stack, &n);
		getTopLStack(&stack, &left);
		popLStack(&stack, &n);
		base = Partition(a, left, right);

		// 入栈
		if(base - 1 > left)
		{
			pushLStack(&stack, left);
			pushLStack(&stack, base-1);
		}
		if(base + 1 < right)
		{
			pushLStack(&stack, base+1);
			pushLStack(&stack, right);
		}
	}
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size, int max)
{
	int *temp, *result;

	temp = (int *)malloc(sizeof(int)*max);
	result = (int *)malloc(sizeof(int)*size);

	memset(temp, 0, sizeof(int)*max); // 初始化数组

	// 收集
	for(int i=0; i<size; i++)
    {
		temp[a[i]] += 1;
	}
	// 统计
	for(int i=1; i<max; i++)
    {
		temp[i] += temp[i-1];
	}
	// 分配
	for(int i=size-1; i >= 0; i--)
	{
		result[temp[a[i]]-1] = a[i];
		temp[a[i]]--;
	}
	// 重新填入
	for(int i=0; i<size; i++)
    {
		a[i] = result[i];
	}
	free(temp);
	free(result);
}

// 取出本次排序的位置上的数字
int getBit(int num, int pos)
{
	int temp = 1;
	for(int i=0; i<pos-1; i++)
    {
		temp *= 10;
	}
	return (num / temp) % 10;
}

/**
 *  @name        : void RadixCountSort(int *a, int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a, int size)
{
    int *radix[10]; // 索引

    for(int i=0; i<10; i++)
    {
        radix[i] = (int*)malloc(sizeof(int)*(size+1)); // 给每个位置分配一个数组
        radix[i][0] = 0; // 每个位置的数组第一个位置用来存元素个数
    }

    int len = 1, p=10;
    // 计算数组中最长数字的长度
    for(int i=0; i<size; i++)
    {
        while(a[i] > p)
        {
            p *= 10;
            len++;
        }
    }

    // 开始排序
    for(int pos=1; pos<=len; pos++)
    {
		// 排序
		for (int i=0; i<size; i++)
		{
			int num = getBit(a[i], pos); // 取出本次排序的位置上的数字

            radix[num][0]++;
			int index = radix[num][0];

			radix[num][index] = a[i]; // 把元素放到对应位置
		}
		// 回收
		for (int i=0, j=0; i<BASE_SIZE; i++)
		{
			for (int k=1; k <= radix[i][0]; k++)
            {
				a[j++] = radix[i][k];
			}
			radix[i][0] = 0; // 计数复位
		}
    }
}

void ColorSwap(int* a, int p1, int p2)
{
	int temp = a[p1];
	a[p1] = a[p2];
	a[p2] = temp;
}

/**
 *  @name        : void ColorSort(int *a, int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a, int size)
{
	int left = 0;
	int right = size - 1;
	int i = 0;
	while(i <= right)
    {
		if(a[i] == 0)
		{
			ColorSwap(a, i, left++);
        }
		else if(a[i] == 2)
		{
			ColorSwap(a, i, right--);
		}
		i++;
	}
}

// 检查颜色排序的数据
int ChecColorData(int *a, int size)
{
	for(int i=0; i<size; i++)
    {
		if(a[i]>2 || a[i]<0)
		{
			return -1;
		}
	}
	return 0;
}

/**
 *  @name        : int No_K(int *a, int size, int k)
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int No_K(int *a, int size, int k)
{
	int begin = 0; // 假设第一个是第K大
	int end = size-1;
	return Find_K(a, begin, end, (size-k)+1); // 第K大，解释为从小到大排，第(size-k)+1个
}

int Find_K(int *a, int begin, int end, int k)
{
	if(begin == end)
    {
		return a[begin];
	}
	int base = a[begin]; // 选中位数做枢纽
	int index = Partition(a, begin, end); // 把它排到它所在位置

	if(index+1 == k)
    {
		return base;
	}
	else
	{
		if(index+1 < k)
        {
			return Find_K(a, index+1, end, k); // 说明第K大在它右边
		}
		else
		{
			return Find_K(a, begin, index - 1, k);
		}
	}
}

/**
 *  @name        : InputNumber
 *	@description : to input a checked number
 *	@param		 : none
 *	@return		 : int
 *  @notice      : None
 */
int InputNumber()
{
	typedef enum
	{
		FALSE = 0, TRUE = 1
	} Status;

	int n = 0;
	int num = 0; // 存放输入数字
	int status = 0; // 标志状态
	do
	{
		status = TRUE;
		n = scanf("%d", &num);
		if(getchar() != '\n')
        {
			for (; getchar() != '\n';);
			printf("Illegally input, try again:");
			status = FALSE;
		}
	} while(status == FALSE);
	return num;
}

/**
 *  @name        : InputData(int *data)
 *	@description : Input data
 *	@param		 : int * data
 *	@return		 : int
 *  @notice      : None
 */
InputData(int *data)
{
	int i = 0, n;
	printf("Data amount:");
	n = InputNumber();
	for(int i=0; i<MAX_SIZE && i<n; i++)
    {
		printf("Input No.%d data:", i+1);
		data[i] = InputNumber();
	}

    // 把数据写入data.txt文件
	FILE *fpWrite = fopen("data.txt", "w");
	if(fpWrite == NULL)
	{
		return 0;
	}
	for(int i=0; i<MAX_SIZE && i<n; i++)
    {
        fprintf(fpWrite, "%d ", data[i]);
    }
	fclose(fpWrite);

	return n;
}

/**
 *  @name        : Print(int *data, int n)
 *	@description : Print data
 *	@param		 : int *data, int n
 *	@return		 : int
 *  @notice      : None
 */
Print(int *data, int n)
{
    int count = 1;
	if (n == 0)
    {
		return n;
	}
	printf("Now the data is:\n");

	for (int i=0; i<MAX_SIZE && i<n; i++)
    {
		printf("%-7d ", data[i]);
		if(count%14 == 0)
        {
            printf("\n");
        }
        count++;
	}
    // 把数据写入data.txt文件
	FILE *fpWrite = fopen("data.txt", "w");
	if(fpWrite == NULL)
	{
		return 0;
	}
	for(int i=0; i<MAX_SIZE && i<n; i++)
    {
        fprintf(fpWrite, "%d ", data[i]);
    }
	fclose(fpWrite);

    printf("\n-------------------------------");
	printf("\n");
	//system("pause");
	return n;
}

/**
 *  @name        : int test(int *a, int *n)
 *	@description : test the algorithm
 *	@param		 : int *a, int *n
 *	@return		 : int
 *  @notice      : None
 */
int test(int *a, int *n)
{
	printf("Data mount:");
	do
    {
		*n = InputNumber();
		if(*n>MAX_SIZE || *n<0)
		{
			printf("Input number in [0-%d]:", MAX_SIZE);
		}
		else
		{
			break;
		}
	} while(1);
	for (int i=0; i<*n; i++)
	{
		a[i] = rand();
	}
    // 把数据写入data.txt文件
	FILE *fpWrite = fopen("data.txt", "w");
	if(fpWrite == NULL)
	{
		return 0;
	}

	for(int i=0; i<MAX_SIZE && i<*n; i++)
    {
        fprintf(fpWrite, "%d ", a[i]);
    }
	fclose(fpWrite);

	printf("\nSuccessfully generate data! \nData mount is %d.\n\n", *n);
	system("pause");
	system("cls");
    printf("                               \n");
    printf("    <Sorting algorithm test>   \n");
    printf("-------------------------------\n");
    printf(">>> 1.Insert                   \n");
    printf(">>> 2.Merge                    \n");
    printf(">>> 3.QuickSort(Recursive)     \n");
    printf(">>> 4.QuickSort(not Recursive) \n");
    printf(">>> 5.Count                    \n");
    printf(">>> 6.RadixCount               \n");
    printf(">>> 7.Color                    \n");
    printf(">>> 8.Find No.k large          \n");
    printf(">>> 9.Exit                     \n");
    printf("-------------------------------\n");
}
