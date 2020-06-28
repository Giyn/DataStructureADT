#include "AQueue.h"
#include <stdio.h>
#include <stdlib.h>

char type;
int data_size = 0;

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    data_size = InputType();
    for(int i=0; i<MAXQUEUE; i++)
    {
        Q->data[i] = (void*)malloc(sizeof(data_size));
    }
    Q->front = Q->rear = 0;
    Q->length = 0;
    printf("Successfully initialize a queue!\n");
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
    for(int i=0; i<MAXQUEUE; i++)
    {
        free(Q->data[i]);
        Q->data[0] = NULL;
    }
    Q->front = Q->rear = 0;
    Q->length = 0;
}

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
    if((Q->rear+1) % MAXQUEUE == Q->front)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
    if(Q->length == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
    if(Q == NULL || (Q->front == Q->rear))
    {
        return FALSE;
    }
    memcpy(e, Q->data[Q->front], Q->length);
    return TRUE;
}

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    return Q->length;
}

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data)
{
    if(Q->length == MAXQUEUE)
    {
        printf("The queue is full.\n");
        return FALSE;
    }
    if(Q->rear == MAXQUEUE - 1)
    {
		memcpy(Q->data[Q->rear = 0], data, data_size);
	}
	else
	{
		if(Q->length == 0)
        {
			memcpy(Q->data[Q->rear], data, data_size);
		}
		else
		{
			memcpy(Q->data[Q->rear + 1], data, data_size);
			Q->rear++;
		}
	}
	Q->length++;
    return TRUE;
}

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if(Q->front == Q->rear)
    {
		return FALSE;
	}
	if(Q->front == MAXQUEUE - 1)
    {
		Q->front = 0;
	}
	else
	{
		Q->front++;
	}
	Q->length--;
}

/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	Q->front = Q->rear = 0;
	Q->length = 0;
}

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	if(IsEmptyAQueue(Q))
    {
        printf("Now the queue is empty.");
        return FALSE;
    }
	int count = 0;
	for (int i=Q->front; ; i++)
	{
		if (i == MAXQUEUE)
		{
			i = 0;
		}
		(*foo)(Q->data[i]);
		count++;
		if (count == Q->length)
		{
			return TRUE;
		}
		printf("<-");
	}
}

/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q)
{
	if (type == 'i')
    {
        int *e = (int*)q;
        printf("%d", *e);
    }
	else if (type == 'l')
    {
        long*e = (long*)q;
        printf("%ld", *e);
    }
	else if (type == 'f')
    {
        float*e = (float*)q;
        printf("%f", *e);
    }
	else if (type == 'd')
    {
        double *e = (double*)q;
        printf("%lf", *e);
    }
	else if (type == 'c')
    {
        char* e = (char*)q;
        printf("%c", *e);
    }
}

/**
 *  @name        : InputNumber
 *	@description : Get the correct integer input
 *	@param		 : none
 *	@return		 : int
 *  @notice      : None
 */
int InputNumber()
{
	int num = 0; // Store converted numbers.
	int status = 0; // Flag status.
	char str[100]; // Receive string.
	do
	{
		scanf("%s", str);
		status = TRUE;
		for (int i = 0; str[i] != '\0'; i++)
		{
			// Check for illegal characters.
			if (i == 0)
            {
				if (str[i] == '-' || str[i] == '+')
					continue;
			}
			else
			{
				if (str[i] < '0' || str[i] > '9')
				{
					status = FALSE;
				}
			}
		}
		if (status == FALSE) {
			printf("Illegally input, please input again:");
		}
		else
		{
			int i = 0;
			// Convert string to number.
			for (i = 0, num = 0; str[i] != '\0'; i++)
			{
				if (i == 0)
                {
					if (str[i] == '-' || str[i] == '+')
					{
						continue;
					}
					else
					{
						num *= 10;
						num += (str[i] - 48);
					}
				}
				else
				{
					num *= 10;
					num += (str[i] - 48);
				}
			}
			if (str[0] == '-')
            {
				num = -num;
			}
			// Check if the number entered is out of bounds.
			if (i >= 10)
			{
				printf("Overflow, please input again:");
				status = FALSE;
			}
		}
	} while (status == FALSE);
	return num;
}

int InputType()
{
	int ret = 0;
	do
	{
		ret = 0;
		printf("Choose a data type��");
		printf("[i->int] [l->long] [f->float] [d->double] [c->char]\n");
		getchar();
		printf("Input a char:");
		type = getchar();
		if(type == 'i')
        {
            return 4;
        }
        else if(type == 'l')
        {
            return 8;
        }
        else if(type == 'f')
        {
            return 4;
        }
		else if(type == 'd')
        {
            return 8;
        }
        else if(type == 'c')
        {
            return 1;
        }
        else
        {
            ret = -1;
            printf("Illegally input, please input again:");
        }
	} while (ret == -1);
	return 0;
}

void InputData(void * data)
{
	int ret = 0;
	do
    {
		ret = 0;
		if (type == 'i')
        {
            scanf("%d", data, data_size);
        }
		else if (type == 'l')
        {
            scanf("%ld", data, data_size);
        }
		else if (type == 'f')
        {
            scanf("%f", data, data_size);
        }
		else if (type == 'd')
        {
            scanf("%lf", data, data_size);
        }
		else if (type == 'c')
        {
            scanf("%c", data, data_size);
        }
		if (getchar() != '\n')
        {
			ret = -1;
			for (; getchar()!='\n'; );
			printf("Illegally input, please input again:", ret);
		}
		else
		{
			return FALSE;
		}
	} while (ret = -1);
}
