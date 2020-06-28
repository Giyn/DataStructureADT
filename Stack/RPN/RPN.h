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

Status initLStack(LinkStack *s); // 初始化栈
Status isEmptyLStack(LinkStack *s); // 判断栈是否为空
double getTopLStackint(LinkStack *s); // 得到栈顶元素
char getTopLStackchar(LinkStack *s); // 得到栈顶元素
Status destroyLStack(LinkStack *s); // 销毁栈
Status pushLStackdouble(LinkStack *s, double data); // 入栈
Status pushLStackchar(LinkStack *s, char data); // 入栈
Status popLStackdouble(LinkStack *s, double *data); // 出栈
Status popLStackchar(LinkStack *s, char *data); // 出栈
void inputCheck(int *val); // 检查输入
void inputString(char s[]); // 输入字符串
Status checkString(char s[]); // 检查字符串
Status convertString(char s1[], char s2[], LinkStack *s); // 中缀表达式转化为后缀表达式
int judgePriority(char a, char b); // 判断运算符优先级
double computeString(LinkStack *s1, char s[]); // 计算结果
