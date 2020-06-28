#include "qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**
 *  @name        : void insertSort(int *a, int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
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
        // �����Ƚϣ�С�Ĵ���
        temp[k++] = a[l_begin] < a[r_begin] ? a[l_begin++] : a[r_begin++];
    }

    // ����벿����ʣ�࣬�ϲ���ȥ
    while(l_begin <= l_end)
    {
        temp[k++] = a[l_begin++];
    }
    // ���Ұ벿����ʣ�࣬�ϲ���ȥ
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
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
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
		MergeSort(a, begin, mid, temp); // ʹ�������
		MergeSort(a, mid + 1, end, temp); // ʹ�ұ�����
		MergeArray(a, begin, mid, end, temp);
	}
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	if (begin < end)
	{
		int base = Partition(a, begin, end); // ����Ŧ�ź�
		QuickSort_Recursion(a, end, base - 1);
		QuickSort_Recursion(a, base + 1, end);
	}
}

// ����Ԫ��
void Swap(int a[], int begin, int end)
{
	int temp = a[begin];
	a[begin] = a[end];
	a[end] = temp;
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end)
{
	int base = a[begin]; // ѡȡ��Ŧ
	while (begin < end)
	{
		// ���ұ߿�ʼ�ң�ֱ���ҵ�С����Ŧ��
		while(begin < end && a[end] >= base)
		{
			end--;
		}
		Swap(a, begin, end);
		// ����߿�ʼ�ң�ֱ���ҵ�������Ŧ��
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
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
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

		// ��ջ
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
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size, int max)
{
	int *temp, *result;

	temp = (int *)malloc(sizeof(int)*max);
	result = (int *)malloc(sizeof(int)*size);

	memset(temp, 0, sizeof(int)*max); // ��ʼ������

	// �ռ�
	for(int i=0; i<size; i++)
    {
		temp[a[i]] += 1;
	}
	// ͳ��
	for(int i=1; i<max; i++)
    {
		temp[i] += temp[i-1];
	}
	// ����
	for(int i=size-1; i >= 0; i--)
	{
		result[temp[a[i]]-1] = a[i];
		temp[a[i]]--;
	}
	// ��������
	for(int i=0; i<size; i++)
    {
		a[i] = result[i];
	}
	free(temp);
	free(result);
}

// ȡ�����������λ���ϵ�����
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
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a, int size)
{
    int *radix[10]; // ����

    for(int i=0; i<10; i++)
    {
        radix[i] = (int*)malloc(sizeof(int)*(size+1)); // ��ÿ��λ�÷���һ������
        radix[i][0] = 0; // ÿ��λ�õ������һ��λ��������Ԫ�ظ���
    }

    int len = 1, p=10;
    // ��������������ֵĳ���
    for(int i=0; i<size; i++)
    {
        while(a[i] > p)
        {
            p *= 10;
            len++;
        }
    }

    // ��ʼ����
    for(int pos=1; pos<=len; pos++)
    {
		// ����
		for (int i=0; i<size; i++)
		{
			int num = getBit(a[i], pos); // ȡ�����������λ���ϵ�����

            radix[num][0]++;
			int index = radix[num][0];

			radix[num][index] = a[i]; // ��Ԫ�طŵ���Ӧλ��
		}
		// ����
		for (int i=0, j=0; i<BASE_SIZE; i++)
		{
			for (int k=1; k <= radix[i][0]; k++)
            {
				a[j++] = radix[i][k];
			}
			radix[i][0] = 0; // ������λ
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
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
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

// �����ɫ���������
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
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
int No_K(int *a, int size, int k)
{
	int begin = 0; // �����һ���ǵ�K��
	int end = size-1;
	return Find_K(a, begin, end, (size-k)+1); // ��K�󣬽���Ϊ��С�����ţ���(size-k)+1��
}

int Find_K(int *a, int begin, int end, int k)
{
	if(begin == end)
    {
		return a[begin];
	}
	int base = a[begin]; // ѡ��λ������Ŧ
	int index = Partition(a, begin, end); // �����ŵ�������λ��

	if(index+1 == k)
    {
		return base;
	}
	else
	{
		if(index+1 < k)
        {
			return Find_K(a, index+1, end, k); // ˵����K�������ұ�
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
	int num = 0; // �����������
	int status = 0; // ��־״̬
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

    // ������д��data.txt�ļ�
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
    // ������д��data.txt�ļ�
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
    // ������д��data.txt�ļ�
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
