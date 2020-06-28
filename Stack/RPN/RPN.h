#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef enum Status
{
    ERROR = 0, SUCCESS = 1
} Status;

// StackNode
typedef  struct StackNode
{
    char cData;
    double data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

// LinkStack
typedef  struct  LinkStack
{
    LinkStackPtr top;
    int	count;
} LinkStack;

Status initLStack(LinkStack *s); // ��ʼ��ջ
Status isEmptyLStack(LinkStack *s); // �ж�ջ�Ƿ�Ϊ��
double getTopLStackint(LinkStack *s); // �õ�ջ��Ԫ��
char getTopLStackchar(LinkStack *s); // �õ�ջ��Ԫ��
Status destroyLStack(LinkStack *s); // ����ջ
Status pushLStackdouble(LinkStack *s, double data); // ��ջ
Status pushLStackchar(LinkStack *s, char data); // ��ջ
Status popLStackdouble(LinkStack *s, double *data); // ��ջ
Status popLStackchar(LinkStack *s, char *data); // ��ջ
void inputCheck(int *val); // �������
void inputString(char s[]); // �����ַ���
Status checkString(char s[]); // ����ַ���
Status convertString(char s1[], char s2[], LinkStack *s); // ��׺���ʽת��Ϊ��׺���ʽ
int judgePriority(char a, char b); // �ж���������ȼ�
double computeString(LinkStack *s1, char s[]); // ������
